#include <iostream>
#include <iomanip>
#include <cmath>

double get_input()
{
	int wrong_attempts=0;
	double result;
	while(wrong_attempts<3) // not more than 3 attempts are allowed to have a valid input
	{
		std::cout << "Please enter a double precision floating point number within 10^(-5) and 10^50: ";
		std::cin >> result;
		if((result<0.00001) || (result > pow(10.0,50.0))) wrong_attempts++; else break; // check for valid input
	}
	if(wrong_attempts==3) return 0; else return result; // return value depends on success of input validation
}

double findx(double input)
{
	//our function f(x)=(1+x)*ln(1+x)-x-y should be 0 
	//derivative function for Newton-method f'(x)=ln(1+x) 
	// x_n-f(x_n)/f'(x_n)=x_n-(1+x_n)+(x_n+y)/(ln(1+x))=(x_n+y)/(ln(1+x))-1
	double x_cur=1;
	double x_next=(x_cur+input)/std::log(1+x_cur)-1; 
	while(std::abs(x_cur-x_next)>x_next/std::pow(10.0,11.0))
	{
		x_cur=x_next;
		x_next=(x_cur+input)/std::log(1+x_cur)-1;
	}
	return x_cur; //x_cur has at least 10 significant correct decimals as wished
}

int main()
{
	double y=get_input();
	if(y==0) { std::cout << "You were stubborn enough to enter input I won't accept. Goodbye!" << std::endl; return 1;}
	std::cout << std::setprecision(15); //Print all significant numbers
	std::cout << "The approximated solution is: "<< findx(y) << std::endl;
	return 0;
}
