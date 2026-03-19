#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


Polynomial::Polynomial()
{
	poly = NULL;
}

Polynomial::~Polynomial()
{
	TermPtr p = poly, temp;
	while (p != NULL)
	{

		temp = p->next;
		delete p;
		p = temp;
	}
}

Polynomial::Polynomial(const Polynomial& other)
{
	poly = NULL;
	TermPtr p = other.poly;
	while (p) {
		addTerm(p->coeff, p->exp);
		p = p->next;
	}
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (this == &other) return *this;
	// Delete current list
	TermPtr curr = poly;
	while (curr != NULL) {
		TermPtr temp = curr;
		curr = curr->next;
		delete temp;
	}
	poly = NULL;
	// Copy from other
	TermPtr p = other.poly;
	while (p) {
		addTerm(p->coeff, p->exp);
		p = p->next;
	}
	return *this;
}

bool Polynomial::isEmpty()
{
	return poly == nullptr;
}

void Polynomial::display()
{
	if (isEmpty())
	{
		cout << "No polynomial found / empty list..." << endl;
		return;
	}
	TermPtr p = poly;
	bool first = true;
	while (p != nullptr)
	{
		if (p->coeff == 0) { p = p->next; continue; }

		// Print sign
		if (first)
		{
			if (p->coeff < 0)
			{
				cout << "-";
			}
		}
		else
		{
			if (p->coeff < 0)
			{
				cout << " - ";
			}
			else
			{
				cout << " + ";
			}
		}

		float absCoeff = (p->coeff >= 0) ? p->coeff : -p->coeff;

		// Print coefficient and variable
		if (p->exp == 0)
		{
			cout << absCoeff;
		}
		else if (p->exp == 1)
		{
			if (absCoeff == 1)
			{
				cout << "x";
			}
			else
			{
				cout << absCoeff << "x";
			}
		}
		else
		{
			if (absCoeff == 1)
			{
				cout << "x^" << p->exp;
			}
			else
			{
				cout << absCoeff << "x^" << p->exp;
			}
		}
		first = false;
		p = p->next;
	}
	cout << endl;
}


void Polynomial::addTerm(float coeff, int exp)
{
	if (coeff == 0)
	{
		return;
	}

	TermPtr curr = poly;
	TermPtr prev = NULL;

	while (curr != NULL && curr->exp > exp)
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr != NULL && curr->exp == exp)
	{
		curr->coeff += coeff;
		if (curr->coeff == 0)
		{
			if (prev == NULL)
			{
				poly = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			delete curr;
		}
	}
	else
	{
		TermPtr newTerm = new Term;
		newTerm->coeff = coeff;
		newTerm->exp = exp;
		newTerm->next = curr;
		if (prev == NULL)
		{
			poly = newTerm;
		}
		else
		{
			prev->next = newTerm;
		}
	}
}

Polynomial Polynomial::add(Polynomial other)
{
	Polynomial result;
	TermPtr p = this->poly, q = other.poly;

	while (p != nullptr && q != nullptr)
	{
		if (p->exp == q->exp)
		{
			result.addTerm(p->coeff + q->coeff, p->exp);
			p = p->next;
			q = q->next;
		}
		else if (p->exp > q->exp)
		{
			result.addTerm(p->coeff, p->exp);
			p = p->next;
		}
		else // q->exp > p->exp
		{
			result.addTerm(q->coeff, q->exp);
			q = q->next;
		}
	}

	// Add remaining terms from p
	while (p != NULL)
	{
		result.addTerm(p->coeff, p->exp);
		p = p->next;
	}

	// Add remaining terms from q
	while (q != NULL)
	{
		result.addTerm(q->coeff, q->exp);
		q = q->next;
	}

	return result;
}


Polynomial Polynomial::multiply(Polynomial other)
{
	Polynomial result;

	for (TermPtr p = this->poly; p != nullptr; p = p->next)
	{
		for (TermPtr q = other.poly; q != nullptr; q = q->next)
		{
			// Multiply coefficients and add exponents
			float coeff = p->coeff * q->coeff;
			int exp = p->exp + q->exp;

			TermPtr r = result.poly, prev = nullptr;
			while (r != nullptr && r->exp > exp)
			{
				prev = r;
				r = r->next;
			}
			if (r != nullptr && r->exp == exp)
			{
				r->coeff += coeff;
			}
			else
			{
				TermPtr newTerm = new Term{ coeff, exp, r };
				if (prev == nullptr)
				{
					result.poly = newTerm;
				}
				else
				{
					prev->next = newTerm;
				}
			}
		}
	}
	return result;
}

void Polynomial::readFromFile(char filename[])
{
	// Clear the current polynomial
	TermPtr curr = poly;
	while (curr != NULL)
	{
		TermPtr temp = curr;
		curr = curr->next;
		delete temp;
	}
	poly = NULL;

	// Try to open the file
	ifstream file(filename);
	if (!file)
	{

		string fname = string(filename) + ".txt";
		file.open(fname.c_str());
		if (!file)
		{
			cout << "Error: Cannot open file '" << filename << "' or '" << fname << "'" << endl;
			return;
		}
	}

	float coeff;
	int exp;
	while (file >> coeff >> exp)
	{
		addTerm(coeff, exp);
	}
	file.close();
}

float Polynomial::evaluate(float x)
{
	float result = 0;
	TermPtr current = poly;

	while (current != NULL)
	{
		float term = current->coeff;
		for (int i = 0; i < current->exp; i++)
			term *= x;
		result += term;
		current = current->next;
	}

	return result;
}