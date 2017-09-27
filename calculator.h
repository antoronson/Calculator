#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cstdlib>
#include <string>
#include <stack>


class Calculator
{
private:
	std::stack<double> numbers;		// Number storage Stack - Global
	std::stack<double> operators;			// Operator Storage - Global
	std::string inum;			// The input expression

public:
	double separator(std::string inum);
	double calculation();
	double calculations(double oper1, double oper2, double operat);

};
#endif

