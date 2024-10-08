#include <iostream>
using namespace std;

vector<vector<int>> sums;

NumMatrix(vector<vector<int>> matrix) {
    int m = matrix.size(),n = m?matrix[0].size():0;
    sums = vector<vector<int>> (m+1,vector<int>(n+1,0));
    for (int i = 1; i <=m; i++) for (int j = 1; j <=n ; j++) sums[i][j] = matrix[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
}

int sumRegion(int row1, int col1, int row2, int col2) {
    return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/75350/Clean-C%2B%2B-Solution-and-Explaination-O(mn)-space-with-O(1)-time
	return 0;
}

