#include <bits/stdc++.h>
using namespace std;

// recuresive
// bool isSubSequence(string str1,string str2,int m,int n){
//     if(m == 0) return true;
//     if(n == 0) return false;
//     if(str1[m-1] == str2[n-1]) return isSubSequence(str1,str2,m-1,n-1);
//     return isSubSequence(str1,str2,m,n-1);
// }

// dp 
// int dp[1001][1001];
// int isSubSequence(string str1,string str2,int i,int j){
//     if(i == 0 || j == 0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     if(str1[i-1] == str2[j-1]) return dp[i][j] = 1+isSubSequence(str1,str2,i-1,j-1);
//     else return dp[i][j] = isSubSequence(str1,str2,i,j-1);
// }

bool isSubSequence(string str1,string str2,int m,int n){
    int j = 0;
    for (int i = 0; i < n && j<m; i++) if(str1[j] == str2[i]) j++;
    return j == m;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/given-two-strings-find-first-string-subsequence-second/
    string str1 = "gksrek";
    string str2 = "geeksforgeeks";
    int m = str1.size();
    int n = str2.size();
    //isSubSequence(str1, str2, m, n) ? cout << "Yes ": cout << "No";
    // memset(dp,-1,sizeof(dp));
    // isSubSequence(str1, str2, m, n) == m ? cout << "Yes ": cout << "No";
    isSubSequence(str1, str2, m, n) ? cout << "Yes ": cout << "No";
    return 0;
}

