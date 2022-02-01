#include <iostream>
using namespace std;

int countSubstrings(string s) {
    int n = s.size(),res = 0;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for (int j = 0; j < n; j++) for (int i = j; i >= 0; i--) if(s[i] == s[j]) if(j-i<2 || dp[i+1][j-1]) res++,dp[i][j] = true;
    return res;
} 

int main() {
	// leetcode
	// https://leetcode.com/problems/palindromic-substrings/
	return 0;
}

