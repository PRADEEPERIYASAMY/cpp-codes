#include <bits/stdc++.h>
using namespace std;

// recursion
// int isKPalRec(string str1,string str2,int m,int n){
//     if(m == 0) return n;
//     if(n == 0) return n;
//     if(str1[m-1] == str2[n-1]) return isKPalRec(str1,str2,m-1,n-1);
//     return 1+min(isKPalRec(str1,str2,m-1,n),isKPalRec(str1,str2,m,n-1));
// }

// dp 
int isKPalRec(string str1,string str2,int m,int n){
    int dp[m+1][n+1] = {0};
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

bool isKPal(string str,int k){
    string revStr = str;
    reverse(str.begin(),str.end());
    int len = str.size();
    return isKPalRec(str,revStr,len,len)<=2*k;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-if-string-is-k-palindrome-or-not/
	string str = "acdcb";
    int k = 2;
    isKPal(str, k)? cout << "Yes" : cout << "No";
    return 0;
}
