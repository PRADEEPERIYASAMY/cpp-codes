#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// recursion
// int maxCuts(int n,int a,int b,int c){
//     if(n<0) return -1;
//     if(n == 0) return 0;
    
//     int res = max(maxCuts(n-a,a,b,c),max(maxCuts(a-b,a,b,c),maxCuts(a-c,a,b,c)));
    
//     if(res == -1) return -1;
//     else return res+1;
// }

// dp
int maxCuts(int n,int a,int b,int c){
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <=n; i++) {
        dp[i] = -1;
        
        if(i-a >= 0) dp[i] = max(dp[i],dp[i-a]);
        if(i-b >= 0) dp[i] = max(dp[i],dp[i-b]);
        if(i-c >= 0) dp[i] = max(dp[i],dp[i-c]);
        
        if(dp[i] != -1) dp[i]++;
    }
    
    return dp[n];
}

int main() {
	
    int n = 5, a = 1, b = 2, c = 3;
    cout<<maxCuts(n, a, b, c);
    return 0;
}

