#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// dp
int countBSTs(int n){
    int dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j <= i; j++) {
            dp[i]+=(dp[j]*dp[i-j-1]); // leftside*right side
        }
    }
    return dp[n];
}

int main() {
    
    int n = 4;
    cout<<countBSTs(n);
}

