#include "calculator.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{


	std::string my_string;
	cout<<"Enter the Calculator variable"<<endl;
	cin>>my_string;

	Calculator my_calc;

	my_calc.separator(my_string);
	my_calc.calculation();

}