#include <iostream>
using namespace std;

int longestArithSeqLength(vector<int>& A) {
    int n = A.size();
    int result = 0;
    vector<vector<int>> dp(n,vector<int>(1001,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = A[i] - A[j]+500;
            dp[i][diff] = dp[j][diff]>0?dp[j][diff]+1:2;
            result = max(result,dp[i][diff]);
        }
    }
    return result;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-arithmetic-subsequence/discuss/474884/C%2B%2B-DP-with-explanation
	return 0;
}

