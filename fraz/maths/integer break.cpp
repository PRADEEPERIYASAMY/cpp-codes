#include <iostream>
using namespace std;

// DP + Math
// int integerBreak(int n) {
//     if(n<=2) return 1;
//     if(n == 3) return 2;
//     if(n == 4) return 4;
//     vector<int> dp(n+1,0);
//     dp[1] = 1;
//     dp[2] = 1;
//     dp[3] = 2;
//     dp[4] = 4;
//     for (int i = 5; i <= n; i++) dp[i] = 3*max(i-3,dp[i-3]);
//     return dp[n];
// }

// maths
int integerBreak(int n){
    if(n == 2) return 1;
    if(n == 3) return 2;
    int res = 1;
    while(n>4){
        res*=3;
        n-=3;
    }
    res*=n;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/integer-break/submissions/
	return 0;
}

