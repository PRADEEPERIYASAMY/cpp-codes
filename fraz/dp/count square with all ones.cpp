#include <iostream>
using namespace std;

int countSquares(vector<vector<int>>& A) {
    int res = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if(i>0 && j>0 && A[i][j]) A[i][j] = min({A[i-1][j],A[i][j-1],A[i-1][j-1]})+1;
            res +=A[i][j];
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643692/C%2B%2B-DP-%2B-Iterative-Easy-solution
	return 0;
}

