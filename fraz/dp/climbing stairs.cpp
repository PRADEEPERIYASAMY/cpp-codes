using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

// Dynamic Programming
// int climbStairs(int n) {
//     if(n<=1)return n;
//     vector<int> dp(n+1,0);
//     dp[1] = 1;
//     dp[2] = 2;
//     for (int i = 3; i <= n; i++) dp[i] = dp[i-2]+dp[i-1];
//     return dp[n];
// }

// Space Optimized Dynamic Programming
// int climbStairs(int n) {
//     if(n<=1)return n;
//     int two = 1,one = 2,res = 2;
//     for (int i = 3; i <=n; i++) {
//         res = two+one;
//         two = one;
//         one = res;
//     }
//     return res;
// }

// Top-Down DP with Memoization
int helper(int n,vector<int> &memo){
    if(n==0) return 1;
    if(n<=2) return n;
    if(memo[n] != -1) return memo[n];
    memo[n] = helper(n-1,memo)+helper(n-2,memo);
    return memo[n];
}

int climbStairs(int n){
    vector<int> memo(n+1,-1);
    return helper(n,memo);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/maximum-subarray/
    return 0;
}

