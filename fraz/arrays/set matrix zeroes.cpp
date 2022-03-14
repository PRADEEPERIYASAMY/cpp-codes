#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return;
    bool row,col;
    int m = matrix.size(),n = matrix[0].size();
    row = col = false;
    for (int i = 0; i < n; i++) if(matrix[0][i] == 0) row = true;
    for (int i = 0; i < m; i++) if(matrix[i][0] == 0) col = true;
    for (int i = 1; i < m; i++) for (int j = 1; j < n; j++) if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
    for (int i = 1; i < m; i++) for (int j = 1; j < n; j++) if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
    if(row) for (int i = 0; i < n; i++) matrix[0][i] = 0;
    if(col) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/set-matrix-zeroes/
    return 0;
}
