#include <iostream>
using namespace std;

int minCost(int n, vector<int>& A) {
    A.push_back(0);
    A.push_back(n);
    sort(A.begin(),A.end());
    int N = A.size();
    vector<vector<int>> dp(N,vector<int>(N,INT_MAX));
    for (int i = 0; i < N-1; i++) dp[i][i+1] = 0;
    for (int i = 0; i < N-2; i++) dp[i][i+2] = A[i+2] - A[i];
    for (int len = 4; len <= N; len++) {
        for (int i = 0; i <= N-len; i++) {
            int j = i+len -1;
            for (int k = i+1; k < j; k++) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j] +A[j] - A[i]);
        }
    }
    return dp[0][N-1];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/780901/C%2B%2B-bottom-up-dp-with-explanation
	return 0;
}

