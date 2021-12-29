#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
// logic based -- sum of length of both string - (lcs of both string)
// int lcs(string x,string y){
//     int n = x.length();
//     int m = y.length();
//     int dp[n+1][m+1];
//     for (int i = 0; i <= n; i++) dp[i][0] = 0; 
//     for (int i = 0; i <= m; i++) dp[0][i] = 0;
    
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
//             else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//         }
//     }
//     return dp[n][m];
// }

// int shortestSuperSequence(string x,string y){
//     return x.length()+y.length()-lcs(x,y);
// }

// recursive

// int shortestSuperSequence(string x,string y, int n,int m){
//     if(n == 0) return m;
//     if(m == 0) return n;
//     if(x[n-1] == y[m-1]) return 1+shortestSuperSequence(x,y,n-1,m-1);
//     return 1+min(shortestSuperSequence(x,y,n-1,m),shortestSuperSequence(x,y,n,m-1));
// }

// dp
int shortestSuperSequence(string x,string y, int n,int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(x[i-1] == y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
 
int main() {
	string x = "AGGTAB";
    string y = "GXTXAYB";
    cout << "Length of the shortest supersequence is "<< shortestSuperSequence(x, y,x.length(),y.length()) << endl;

	return 0;
}

