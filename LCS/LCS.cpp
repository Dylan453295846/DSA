#include "LCS.h"
#include <iostream>
#include<algorithm> //max

// recursion method, time costly, o(2^n)
int LCS::lcs1(std::vector<char> A, std::vector<char> B)
{
	int len = 0;
	int m = A.size();
	int n = B.size();
	if (m == 0 || n == 0) return 0;
	if (A[m - 1] == B[n - 1]) { //  减而治之
		len++;
		A.pop_back();
		B.pop_back();
		len += lcs1(A, B);
	}
	else { // 分而治之
		std::vector<char> A1, B1; 
		A1 = A; B1 = B;
		A.pop_back();
		B.pop_back();
		if (lcs1(A1, B) < lcs1(A, B1)) len += lcs1(A, B1);
		else len += lcs1(A1, B);
	}
	return len;
}

// dynamic programming,iteriation,o(mn)
int LCS::lcs2(std::vector<char> A, std::vector<char> B)
{
	int m = A.size();
	int n = B.size();
	if (m == 0 || n == 0) return 0;
	std::vector<std::vector<int>> table;
	table.resize(n);
	for (int i = 0; i < n; i++) table[i].resize(m,0);
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			
			if (B[i] == A[j]) table[i][j] = table[i - 1][j - 1] + 1; // 减而治之
			else table[i][j] = std::max(table[i - 1][j], table[i][j - 1]); // 分而治之
		}
	}

	return table[n-1][m-1];
}