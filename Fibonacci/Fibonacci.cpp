#include "Fibonacci.h"
#include <vector>

// recursion algorithm, worst estimate
int Fibonacci::Fibonacci_1(int n)
{
	return (n < 3) ? 1 : Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}

// dynamic programming, bottom-up to avoid repetition
int Fibonacci::Fibonacci_2(int n)
{
	int f = 1, g = 1;
	if (n < 3) return 1;
	
	while ((n--)-2) {
		g = g + f;
		f = g - f;
	}
	return g;
}

// general method
int Fibonacci::Fibonacci_3(int n)
{
	std::vector<int> value;
	value.resize(n,1);
	for (int i = 2; i < n; i++){
		value[i] = value[i - 1] + value[i - 2];
	}
	return value[n - 1];
}