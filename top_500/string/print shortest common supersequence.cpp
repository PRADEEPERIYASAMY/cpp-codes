#include <bits/stdc++.h>
using namespace std;

string printShortestSuperSeq(string X, string Y){
    int m = X.size();
    int n = Y.size();
    int dp[m+1][n+1]; // for storing length of shortest common subsequence
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) i;
            else if(X[i-1] == Y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = m,j = n;
    string str;
    while(i>0 && j>0){
        if(X[i-1] == Y[j-1]){
            str.push_back(X[i-1]);
            j--,i--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            str.push_back(Y[j-1]);
            j--;
        }else{
            str.push_back(X[i-1]);
            i--;
        }
    }
    while(i>0){
        str.push_back(X[i-1]);
        i--;
    }
    while(j>0){
        str.push_back(Y[j-1]);
        j--;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-shortest-common-supersequence/
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << printShortestSuperSeq(X, Y);
    return 0;
}

