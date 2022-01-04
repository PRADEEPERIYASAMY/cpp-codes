#include <bits/stdc++.h>
using namespace std;

// recursion
// int maxProd(int n){
//     if( n == 0 || n == 1) return 0;
//     int max_val = 0;
//     for (int i = 1; i < n; i++) max_val = max(max_val,max(i*(n-i),maxProd(n-i)*i));
//     return max_val;
// }

// dp 
int maxProd(int n){
    int dp[n+1];
    dp[0] = dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            int val = max((i-j)*j,j*dp[i-j]);
            dp[i] = max(dp[i],val);
        }
    }
    return dp[n];
}

int main(){
    cout << "Maximum Product is " << maxProd(10);
    return 0;
}

