#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//dp
// variation of coin change
// optimized of coin change form
int count(int n){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for (int i = 3; i <= n; i++) dp[i]+=dp[i-3];
    for (int i = 5; i <= n; i++) dp[i]+=dp[i-5];
    for (int i = 10; i <= n; i++) dp[i]+=dp[i-10];
    
    return dp[n];
}
 
int main() {
	int n = 20;
    cout << "Count for " << n << " is " << count(n) << endl;
    return 0;
}

