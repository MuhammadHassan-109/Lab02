#pragma once

class Polynomial {
private:
	struct Term {
		float coeff;
		int exp;
		struct Term* next;
	};
	typedef struct Term* TermPtr;
	TermPtr poly; // Pointer to first term
public:
	Polynomial(); // Constructor
	Polynomial(const Polynomial& other);
	~Polynomial(); // Destructor
	void readFromFile(char filename[]); // Read polynomial from file
	void display(); // Display polynomial
	Polynomial add(Polynomial other); // Add two polynomials
	Polynomial multiply(Polynomial other); // Multiply two polynomials
	float evaluate(float x); // Evaluate polynomial at x
	bool isEmpty(); // Check if polynomial is empty
	Polynomial& operator=(const Polynomial& other);
	void addTerm(float coeff, int exp);
};