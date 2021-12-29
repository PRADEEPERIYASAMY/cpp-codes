#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// order dosen't matter
// using fib or recursion
// int countWays(int s){
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     return fib(n-1)+fib(n-2);
// }

// dp
int countWays(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i-1]+dp[i-2];
    return dp[n];
}
 
int main() {
    int n = 10;
    cout << countWays(n+1);
    return 0;
}
