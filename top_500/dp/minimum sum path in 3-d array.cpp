#include <bits/stdc++.h>
using namespace std;
#define l 3 
#define m 3
#define n 3

int minPathSum(int arr[][m][n]){
    int i,j,k;
    int tSum[l][m][n];
    tSum[0][0][0] = arr[0][0][0];
    for (int i = 1; i < l; i++) tSum[i][0][0] = tSum[i-1][0][0]+arr[i][0][0];
    for (int j = 1; j < m; j++) tSum[0][j][0] = tSum[0][j-1][0]+arr[0][j][0];
    for (int k = 1; k < n; k++) tSum[0][0][k] = tSum[0][0][k-1]+arr[0][0][k];
    for (int i = 1; i < l; i++) for (int j = 1; j <m; j++) tSum[i][j][0] = min(tSum[i-1][j][0],tSum[i][j-1][0])+arr[i][j][0]; 
    for (int i = 1; i < l; i++) for (int k = 1; k <n; k++) tSum[i][0][k] = min(tSum[i-1][0][k],tSum[i][0][k-1])+arr[i][0][k];
    for (int k = 1; k < n; k++) for (int j = 1; j <m; j++) tSum[0][j][k] = min(tSum[0][j-1][k],tSum[0][j][k-1])+arr[0][j][k];
    
    for (int i = 1; i < l; i++)
        for (int j = 1; j <m; j++)
            for (int k = 1; k <n; k++)
                tSum[i][j][k] = min({tSum[i-1][j][k],tSum[i][j-1][k],tSum[i][j][k-1]})+arr[i][j][k];
    return tSum[l-1][m-1][n-1];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/minimum-sum-path-3-d-array/
	int arr[l][m][n] = { { {1, 2, 4}, {3, 4, 5}, {5, 2, 1}},
    { {4, 8, 3}, {5, 2, 1}, {3, 4, 2}},
    { {2, 4, 1}, {3, 1, 4}, {6, 3, 8}}
  };
    cout << minPathSum(arr);
    return 0;
}
