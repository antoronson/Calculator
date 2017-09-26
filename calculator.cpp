#include "calculator.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

double Calculator::separator(std::string inum)
{
	//c-count
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
	double temp_s_i = 0;
	std::stringstream temp;					// Temporary memory to convert string to integer

	for(int i = 0; i < inum.size(); i++)// For every character read, we generate number and symbol array
	{
		if (isdigit(inum[i]))
		{
			temp <<inum[i];
			temp >> temp_s_i;
			temp.clear();
			value[c_c_num] = value[c_c_num]*10 + temp_s_i;
		}
		else
		{
			c_c_num++;
		switch (inum[i])
		{ 
		case '+':
			syms[c_c_sym] = 2;
			break;
		case '-':
			syms[c_c_sym] = 1;
			break;
		case '*':
			syms[c_c_sym] = 4;
			break;
		case '/':
			syms[c_c_sym] = 3;
			break;
		default:
			syms[c_c_sym] = -1;
		}
		

		c_c_sym++;
		}
	}

	for(int i =0; i < c_sym; i++)

		cout<<syms[i]<<endl;
	cout<<"--------------------------------------------"<<endl;
	for(int i = 0; i<c_sym+1;i++)
		cout<<value[i]<<endl;
}

double Calculator::calculaiton()
{

	// Local Variable Initialization
	// Absorbs value and syms variable from class library

	int ord_ = 4, sym_size = 0;
	double ans =0;

	sym_size = syms.size();

	// Find the max order of precedence

	while ord_ ~= 0 
	{
		for (int i = 0; i < sym_size; i++)
		{
			if(syms[i] == ord_)
			{
				double temp_ans =0;
				switch syms[i]
				{
					case 1:
					{	temp_ans = value[i] - value[i+1];
						value[i] = temp_ans;
						value[i+1] = temp_ans;
						break;
					}
					case 2:
					{
						temp_ans = value[i] + value[i+1];
						break;
					}

					case 3:
					{
						temp_ans = value[i] / value[i+1];
						break;
					}

					case 4:
					{
						temp_ans = value[i] * value[i+1];
						break;
					}
					default:
						cout<<"Error"<<endl;
				}
				value[i] = temp
			}
		}
	} 
}
