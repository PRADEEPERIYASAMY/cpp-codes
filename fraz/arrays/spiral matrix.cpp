using namespace std;
#include <bits/stdc++.h>

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    vector<int> res(m*n,0);
    int idx = 0,up = 0,down = m-1,left = 0,right = n-1;
    while(true){
        for (int col = left; col<=right; col++) res[idx++] = matrix[up][col];
        up++;
        if(up>down) break;
        for (int row = up; row <= down; row++) res[idx++] = matrix[row][right];
        right--;
        if(right<left) break;
        for (int col = right; col >= left; col--) res[idx++] = matrix[down][col];
        down--;
        if(down<up) break;
        for (int row = down; row>= up; row--) res[idx++] = matrix[row][left];
        left++;
        if(left>right) break;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/spiral-matrix/
    return 0;
}

