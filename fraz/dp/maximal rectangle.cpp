#include <iostream>
using namespace std;

// Dynamic programming
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int res = 0, m = matrix.size(),n = matrix[0].size();
    vector<int> heights(n,0),left(n,0),right(n,n);
    for (int i = 0; i < m; i++) {
        int curLeft = 0, curRight = n;
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == '1') left[j] = max(left[j],curLeft);
            else{
                left[j] = 0;
                curLeft = j+1;
            }
        }
        for (int j = n-1; j >= 0; j--) {
            if(matrix[i][j] == '1') right[j] = min(right[j],curRight);
            else {
                right[j] = n;
                curRight = j;
            }
        }
        for (int j = 0; j < n; j++) {
            res = max(res,(right[j] - left[j])*heights[j]);
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximal-rectangle/
	return 0;
}

