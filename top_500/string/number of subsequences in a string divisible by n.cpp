#include <bits/stdc++.h>
using namespace std;

int countDivisibleSubseq(string str,int n){
    int len = str.size();
    int dp[len][n];
    memset(dp,0,sizeof(dp));
    dp[0][(str[0]-'0')%n]++;
    for (int i = 1; i < len; i++) {
        dp[i][(str[i]-'0')%n]++;
        for (int j = 0; j <n ; j++) {
            dp[i][j]+=dp[i-1][j];
            dp[i][(j*10+(str[i]-'0'))%n] +=dp[i-1][j];
        }
    }
    return dp[len-1][0];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
	string str = "1234";
    int n = 4;
    cout << countDivisibleSubseq(str, n);
	return 0;
}

