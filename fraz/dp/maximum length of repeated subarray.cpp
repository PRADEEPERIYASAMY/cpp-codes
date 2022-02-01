#include <iostream>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size(),n = B.size(),res = 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                res = max(res,dp[i][j]);
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
	return 0;
}

