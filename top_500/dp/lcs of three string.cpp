#include<bits/stdc++.h>
using namespace std;

// dp tabularation
// int lcsOf3(string x,string y, string z,int m,int n,int o){
//     int L[m+1][n+1][o+1];
//     for (int i = 0; i <=m; i++) {
//         for (int j = 0; j <= n; j++) {
//             for (int k = 0; k <=o ; k++) {
//                 if( i == 0 || j == 0 || k == 0) L[i][j][k] = 0;
//                 else if(x[i-1] == y[j-1] && y[j-1]==z[k-1]) L[i][j][k] = L[i-1][j-1][k-1]+1;
//                 else L[i][j][k] = max(max(L[i-1][j][k],L[i][j-1][k]),L[i][j][k-1]);
//             }
//         }
//     }
//     return L[m][n][o];
// }

// dp memorization
int dp[100][100][100];
string X = "AGGT12";
string Y = "12TXAYB";
string Z = "12XBA";
int lcsOf3(int i,int j,int k){
    if(i == -1 || j == -1 || k == -1) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(X[i-1] == Y[j-1] && Y[j-1]==Z[k-1]) return dp[i][j][k] = 1+lcsOf3(i-1,j-1,k-1);
    else return dp[i][j][k] = max(max(lcsOf3(i-1,j,k),lcsOf3(i,j-1,k)),lcsOf3(i,j,k-1));
}

int main() {
    memset(dp, -1,sizeof(dp));
    
    int m = X.length();
    int n = Y.length();
    int o = Z.length();
    //cout << "Length of LCS is " << lcsOf3(X, Y,Z, m, n, o);
    cout << "Length of LCS is " << lcsOf3(m-1,n-1,o-1);
    return 0;
}

