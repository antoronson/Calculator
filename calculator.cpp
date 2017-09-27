#include "calculator.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

double Calculator::separator(std::string inum)
{
/*	//c-count
	int c_inum = 0, c_sym = 0;
	for(int i = 0; i < inum.size(); i++)	// Read chracter by character and count number of symbols
	{
		switch (inum[i])
		{ 
		case '+':
			c_sym++;
			break;
		case '-':
			c_sym++;
			break;
		case '*':
			c_sym++;
			break;
		case '/':
			c_sym++;
			break;
		default:
			c_sym  = c_sym + 0;
		}
	}

	value = new double[c_sym + 1];			// The value storage
	syms = new double[c_sym];				// Symbol Storage + -> 2, - -> 1, * -> 4, / -> 3 Order or Priority
	int c_c_sym = 0, c_c_num = 0;
*/	// Two Stacks, Two Bool Variables, Two Temporary Storage Variable. 
	std::stringstream temp;					// Temporary memory to convert string to integer
	double temp_s_i = 0, num_accu = 0, syms = 0, last_op = 0, this_op = 0;
	for(int i = 0; i < inum.size(); i++)// For every character read, we generate number and symbol array
	{
		if (isdigit(inum[i]))
		{
			temp <<inum[i];
			temp >> temp_s_i;
			temp.clear();
			num_accu = num_accu*10 + temp_s_i;	
		}
		else
		{
		numbers.push(num_accu);
		num_accu = 0;
		switch (inum[i])
		{ 
			case '+':
				syms = -2;
				break;
			case '-':
				syms = -1;
				break;
			case '*':
				syms = -4;
				break;
			case '/':
				syms = -3;
				break;
			default:
				syms = 0;
		}
		operators.push(syms);
		}

		if (!operators.empty())
		{
			syms = operators.top();
			operators.pop();
			if ((!operators.empty()) && (operators.top() < syms))
			{
				while (!operators.empty())
				{
					numbers.push(operators.top());

					operators.pop();
				}
				operators.push(syms);
		
			}
			else
			{
				operators.push(syms);
			}
		}

	}
	numbers.push(num_accu);
	while (!operators.empty())
	{
		numbers.push(operators.top());
		operators.pop();
	}

};


double Calculator::calculation()
{
	// We reorganize the stack and empty the numbers stack to operators stack
	// Variable Initialization

	double op1 = 0, op2 = 0, ope = 0, temp_ans = 0;
	bool flag = false;
	
	// Push from numbers to operators

	while (!numbers.empty())
	{
		operators.push(numbers.top());
		numbers.pop();
	}


	while (!operators.empty())
	{
		while ((!operators.empty()) && (operators.top() >0))
		{
			numbers.push(operators.top());
			operators.pop();
		}

		op2 = numbers.top();
		numbers.pop();
		if (!numbers.empty())
		{
			op1 = numbers.top();
			numbers.pop();
		}
		else
		{
			flag = true;
			cout<<"Answer is" << op2<<endl;
			// Declare op2 as output and break the loop break the loop
		}
		if (flag == true) 
			break;
		ope = operators.top();
		operators.pop();
		cout<<"No Error"<<endl;
		cout<<op1<<op2<<ope<<endl;
		temp_ans = calculations(op1, op2, ope);
		operators.push(temp_ans);
		while (!numbers.empty())
		{
			operators.push(numbers.top());
			numbers.pop();
		}
		if (flag == true)
			break;
	}

};

double Calculator::calculations (double oper1, double oper2, double operat)
{
	double local_ans = 0;
	int operation = static_cast<int>(operat);
		cout<<operation<<endl;
		switch (operation)
		{ 
			case -2:
				local_ans = oper1 + oper2;
				break;
			case -1:
				local_ans = oper1 - oper2;
				break;
			case -4:
				local_ans = oper1 * oper2;
				break;
			case -3:
				local_ans = oper1 / oper2;
				break;
			default:
				cout<<"Invalid ! Error in calculation"<<endl;
		}
		cout<<local_ans<<endl;
		return local_ans;
};