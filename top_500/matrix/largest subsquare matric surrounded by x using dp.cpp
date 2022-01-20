using namespace std;
#include <bits/stdc++.h>
#define N 6

int findSubSquare(int mat[][N]){
    pair<int,int> dp[N][N];
    int x = 0,y = 0;
    for (int i = 0; i < N; i++) {
        x = 0;
        y = 0;
        for (int j = 0; j < N; j++) {
            if(mat[i][j] == 'X') x++;
            else x = 0;
            dp[i][j].first = x;
            
            if(mat[j][i] == 'X') y++;
            else y = 0;
            dp[j][i].second = y;
        }
    }
    int val = 0,maxVal = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            val = min(dp[i][j].first,dp[i][j].second);
            if(dp[i][j-val+1].second >= val && dp[i-val+1][j].first >= val) maxVal = max(val,maxVal);
        }
    }
    return maxVal;
}

int main(){
    int mat[][N] = {
        { 'X', 'O', 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'X', 'X', 'O', 'X' },
        { 'X', 'X', 'X', 'O', 'O', 'X' },
        { 'O', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'O', 'X', 'O' },
        { 'O', 'O', 'X', 'O', 'O', 'O' },
    };
    cout << findSubSquare(mat);
    return 0;
}

