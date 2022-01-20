using namespace std;
#include <bits/stdc++.h>
#define N 5

int  findMaxValue(int mat[N][N]){
    int max_value = INT_MIN;
    int maxArr[N][N];
    maxArr[N-1][N-1] = mat[N-1][N-1];
    int maxv = mat[N-1][N-1];
    for (int i = N-2; i >=0; i--) {
        maxv = max(maxv,mat[N-1][i]);
        maxArr[N-1][i] = maxv;
    }
    maxv = mat[N-1][N-1];
    for (int i = N-2; i >=0; i--) {
        maxv = max(maxv,mat[i][N-1]);
        maxArr[i][N-1] = maxv;
    }
    for (int i = N-2; i >= 0; i--) {
        for (int j = N-2; j >= 0; j--) {
            max_value = max(max_value,maxArr[i+1][j+1]-mat[i][j]);
            maxArr[i][j] = max({mat[i][j],maxArr[i][j+1],maxArr[i+1][j]});
        }
    }
    return max_value;
}

int main(){
    int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is "<< findMaxValue(mat);
    return 0;
}

