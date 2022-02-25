#include <bits/stdc++.h>
using namespace std;

// recursion
// int count(string a,string b,int m,int n){
//     if((m == 0 && n == 0) || n == 0) return 1;
//     if(m == 0) return 0;
//     if(a[m-1] == b[n-1]) return count(a,b,m-1,n-1)+count(a,b,m-1,n);
//     else return count(a,b,m-1,n);
// }

//dp 
int count(string a, string b,int m,int n){
    int dp[m+1][n+1] = {{0}};
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
	string a = "GeeksforGeeks";
    string b = "Gks";
    cout << count(a, b, a.size(), b.size()) << endl;
    return 0;
}

