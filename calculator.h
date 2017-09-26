#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cstdlib>
#include <string>

class Calculator
{
private:
	double *value, *syms;	// The Value array and corresponding symbols array generated
	std::string inum;			// The input expression

public:
	double separator(std::string inum);
	double calculation();

};
#endif

