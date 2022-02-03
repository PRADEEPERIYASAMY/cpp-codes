#include <iostream>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n+1,0); //catlan number
    dp[0] = 1;
    for (int i = 0; i <= n; i++) for (int j = 0; j < i; j++) dp[i] += dp[j]*dp[i-j-1];
    return dp[n];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/unique-binary-search-trees/discuss/1565599/C%2B%2B-EASY-INTUITIVE-SOL-(2-approaches)-oror-Recursive-DP-oror-Catalan-Numbers
	return 0;
}

