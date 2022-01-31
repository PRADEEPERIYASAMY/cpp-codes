using namespace std;
#include <bits/stdc++.h>

// void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     for (int i = 0; i < n/2; i++) {
//         for (int j = i; j < n-1-i; j++) {
//             int temp = matrix[i][j];
//             matrix[i][j] = matrix[n-1-j][i];
//             matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
//             matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
//             matrix[j][n-1-i] = temp;
//         }
//     }
// }

void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    reverse(matrix.begin(),matrix.end());
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) swap(matrix[i][j],matrix[j][i]);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/rotate-image/
    return 0;
}

