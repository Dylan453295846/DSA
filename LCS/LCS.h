#ifndef _LCS_H_
#define _LCS_H_
#include <vector>

class LCS {
public:
	LCS() {};
	~LCS() {};

	int lcs1(std::vector<char> A, std::vector<char> B);
	int lcs2(std::vector<char> A, std::vector<char> B);

};
#endif // !_LCS_H_
