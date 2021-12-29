#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// recurcion
// int ncr(int n,int r){
//     if(n == r) return 1;
//     if(r == 1) return n;
//     return ncr(n-1,r-1)+ncr(n-1,r);
// }

//dp
int ncr(int n,int r){
    int dp[n+1][r+1];
    for (int i = 1; i <= r; i++) dp[i][i]=1;
    for(int i = 1; i <= n; i++) dp[i][1]=i;
    
    for (int i = 2; i <=n; i++) {
        for (int j = 2; j <= r; j++) {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    
    return dp[n][r];
}
 
int main() {
    int n = 4,r = 2;
    cout << ncr(n,r);
    return 0;
}

