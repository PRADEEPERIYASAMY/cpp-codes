#include <bits/stdc++.h>
using namespace std;

// recursion
// int eggDrop(int n,int k){ // n = egg, k = floors
//     if(k == 1 || k == 0) return k;
//     if(n == 1) return k;
//     int m = INT_MAX,res;
//     for (int x = 1; x <=k ; x++) {
//         res = max(eggDrop(n-1,x-1),eggDrop(n,k-x));
//         m = min(m,res);
//     }
//     return m+1;
// }

// dp tabulation
int eggDrop(int n,int k){
    int dp[n+1][k+1];
    int res;
    
    for (int i = 1; i <= n; i++) {
        dp[i][1] =1;
        dp[i][0] = 0;
    }
    for (int i = 1; i <= k; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                res = 1+max(dp[i-1][x-1],dp[i][j-x]);
                dp[i][j] = min(res,dp[i][j]);
            }
        }
    }
    return dp[n][k];
}

int main(){
    int n = 2, k = 36;
    cout << "Minimum number of trials in worst case with "<< n << " eggs and " << k<< " floors is "<< eggDrop(n, k) << endl;
    return 0;
}

