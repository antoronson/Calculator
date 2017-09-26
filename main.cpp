#include "calculator.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string my_string;
	cout<<"Enter the Calculator variable"<<endl;
	cin>>my_string;

	Calculator my_calc;
	my_calc.separator(my_string);

}