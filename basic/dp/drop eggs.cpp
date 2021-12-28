#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursion
// int eggs(int e,int f){
//     if(f == 1 || f == 0) return f;
//     if(e == 1) return f;
    
//     int m = INT_MAX,x,res;
    
//     for (int i = 1; i <=f; i++) {
//         res = max(eggs(e-1,i-1),eggs(e,f-i)); // break and not break
//         m = min(m,res);
//     }
    
//     return m+1;
// }

// dp
int eggs(int e,int f){
    int dp[f+1][e+1];
    
    for (int i = 1; i <= e; i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    
    for (int i = 1; i <= f; i++) dp[i][1] = i;
    
    for (int i = 2; i <= f; i++) {
        for (int j = 2; j <= e; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++) dp[i][j] = min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
        }
    }
    return dp[f][e];
}

int main() {
    
    int n = 2, k = 10; 
	cout << "Minimum number of trials in worst case with "<< n << " eggs and " << k << " floors is "<< eggs(n, k) << endl; 
	return 0; 
}

