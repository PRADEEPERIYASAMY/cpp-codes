#include <bits/stdc++.h>
using namespace std;

bool strmatch(char str[],char pattern[],int n,int m){
    if(m == 0) return n == 0;
    bool dp[n+1][m+1] = {false};
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) if(pattern[i-1] == '*') dp[0][i] = dp[0][i-1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(pattern[j-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
            else if(pattern[j-1] == '?' || str[i-1] == pattern[j-1])dp[i][j] =dp[i-1][j-1];
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/wildcard-pattern-matching/
	char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
    if (strmatch(str, pattern, strlen(str),strlen(pattern))) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
