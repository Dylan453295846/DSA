#include "LCS.h"
#include <iostream>


int main()
{
	LCS lcs;

	std::vector<char> A;
	A = { 'c','o','m' ,'m','u','n','i'};
	std::vector<char> B;
	B = { 'p','o','m' ,'m','n','o','i'};
	char a[] = "st3erionvjddcfvgbhn";
	char b[] = "uvy3ctxwtrxdfcgvhbj";
	for (int i = 0; i < 5; i++) A.push_back(a[i]);
	for (int i = 0; i < 5; i++) B.push_back(b[i]);

	int len2 = lcs.lcs2(A, B);
	std::cout << len2<< std::endl;
	int len = lcs.lcs1(A, B);
	std::cout << len<< std::endl;

	std::cout << "\n" << "End!";
	return 0;
}