#include <bits/stdc++.h>
using namespace std;

// recursion
// int findMinInsertions(string str,int l,int h){
//     if(l > h) return INT_MAX;
//     if( l == h) return 0;
//     if(l+1 == h) return str[l] == str[h]?0:1;
//     if(str[l] == str[h]) return findMinInsertions(str,l+1,h-1);
//     return min(findMinInsertions(str,l,h-1),findMinInsertions(str,l+1,h))+1;
// }

// dp
// int findMinInsertions(string str,int n){
//     int dp[n][n],l,h;
//     memset(dp,0,sizeof(dp));
//     for (int gap = 1; gap < n; gap++) {
//         for (l = 0,h = gap; h < n; l++,h++) {
//             if(str[l] == str[h]) dp[l][h] = dp[l+1][h-1];
//             else dp[l][h] = min(dp[l][h-1],dp[l+1][h])+1;
//         }
//     }
//     return dp[0][n-1];
// }

// using lis
int findMinInsertions(string str,int n){
    string x = str;
    reverse(str.begin(),str.end());
    string y = str;
    int L[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) L[i][j] = 0;
            else if(x[i-1] == y[j-1]) L[i][j] = L[i-1][j-1]+1;
            else L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[n][n];
}

int main(){
    string str = "geeks";
    //cout << findMinInsertions(str, 0, str.length()-1);
    //cout << findMinInsertions(str,str.length());
    cout <<str.length()-findMinInsertions(str,str.length());
    return 0;
}

