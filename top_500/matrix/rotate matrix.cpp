using namespace std;
#include <bits/stdc++.h>
#define R 4 
#define C 4 

void rotatematrix(int m,int n,int mat[R][C]){
    int row = 0,col = 0;
    int prev,cur;
    while(row<m && col<n){
        if(row+1 == m || col+1 == n) break;
        prev = mat[row+1][col];
        for (int i = col; i < n; i++) {
            cur = mat[row][i];
            mat[row][i] = prev;
            prev = cur;
        }
        row++;
        for (int i = row; i < m; i++) {
            cur = mat[i][n-1];
            mat[i][n-1] = prev;
            prev = cur;
        }
        n--;
        if(row<m){
            for (int i = n-1; i >= col; i--){
                cur = mat[m-1][i];
                mat[m-1][i] = prev;
                prev = cur;
            }
        }
        m--;
        if(col<n){
            for (int i = m-1; i >= row; i--) {
                cur = mat[i][col];
                mat[i][col] = prev;
                prev = cur;
            }
        }
        col++;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    int a[R][C] = { {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} }; 
    rotatematrix(R, C, a); 
    return 0; 
}

