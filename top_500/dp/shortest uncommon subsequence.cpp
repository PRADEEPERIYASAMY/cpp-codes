#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

// recursion
// int shortestSeq(char *s,char *t,int m,int n){
//     if(m == 0) return MAX;
//     if(n<=0) return  1;
//     int k;
//     for (k = 0; k < n; k++) if(t[k] == s[0]) break;
//     if(k == n) return 1;
//     return min(shortestSeq(s+1,t,m-1,n),1+shortestSeq(s+1,t+k+1,m-1,n-k-1));
// }

// dp 
int shortestSeq(char *s,char *t,int m,int n){
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    for (int i = 0; i <= n; i++) dp[0][i] = MAX;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char ch = s[i-1];
            int k;
            for (k = j-1; k >= 0 ; k--) if(t[k] == ch) break;
            if(k == -1) dp[i][j] =1;
            else dp[i][j] = min(dp[i-1][j],dp[i-1][k]+1);
        }
    }
    int ans = dp[m][n];
    if(ans>=MAX) ans = -1;
    return ans;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/shortest-uncommon-subsequence/
	char S[] = "babab";
    char T[] = "babba";
    int m = strlen(S), n = strlen(T);
    int ans = shortestSeq(S, T, m, n);
    if (ans >= MAX) ans = -1;
    cout << "Length of shortest subsequence is: "<< ans << endl;
    return 0;
}
