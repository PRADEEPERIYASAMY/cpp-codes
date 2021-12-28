#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// lcs using recursion
// int lcs(string s1,string s2,int n,int m){
//     if(n == 0|| m == 0) return 0;
//     if(s1[n-1] == s2[m-1]) return 1+lcs(s1,s2,n-1,m-1);
//     return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
// }

// lcs using memo 
int memo[1000][1000];

// int lcs(string s1,string s2,int n,int m){
//     if(memo[n][m] != -1) return memo[n][m];
    
//     if(n == 0 || m == 0) memo[n][m] = 0;
//     else{
//         if(s1[n-1] == s2[m-1]){
//             memo[n][m] = 1+lcs(s1,s2,n-1,m-1);
//         }else{
//             memo[n][m] = max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
//         }
//     }
    
//     return memo[n][m];
// }

// lcs using tabularization

int lcs(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    for (int i = 0; i < n; i++) dp[i][0] = 0;
    for (int i = 0; i < m; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    memset(memo,-1,sizeof(memo));
	string s1="AXYZ", s2="BAZ";
	int n = 4, m = 3;
	cout<<lcs(s1,s2,n,m);
	return 0;
}

