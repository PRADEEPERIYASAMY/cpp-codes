#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursive
// int knapSack(int w,int wt[],int val[],int n){
//     if(n ==0 || w == 0) return 0;
//     if(wt[n-1] > w) return knapSack(w,wt,val,n-1);
//     else return max(knapSack(w,wt,val,n-1),val[n-1]+knapSack(w-wt[n-1],wt,val,n-1));
// }

// dp
int knapSack(int w,int wt[],int val[],int n){
    int dp[n+1][w+1];
    for (int i = 0; i <= w; i++) dp[0][i] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if(wt[i-1]> j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}

int main() {
	int val[] = { 10, 40, 30, 50 }; 
    int wt[] = { 5, 4, 6, 3 }; 
    int W = 10; 
    int n = 4;
    cout<<knapSack(W, wt, val, n);
	return 0;
}

