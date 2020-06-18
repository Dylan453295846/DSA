#include "Fibonacci.h"
#include <iostream>

int main()
{
	int n;
	std::cout << "Please input a number as Fibonacci parameter: ";
	std::cin >> n;
	Fibonacci Fib;
	for (int i = 1; i <=n; i++) {
		std::cout<<Fib.Fibonacci_3(i)<<" ";
	}
	std::cout << "\n" << "another!";
	for (int i = 1; i <= n; i++) {
		std::cout << Fib.Fibonacci_2(i) << " ";
	}

	std::cout << "\n" << "another!";
	for (int i = 1; i <= n; i++) {
		std::cout << Fib.Fibonacci_1(i) << " ";
	}
	std::cout << "\n" << "End!";
	return 0;
}