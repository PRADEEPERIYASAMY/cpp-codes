#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n,vector<int>(n,0));
    int val = 1,i = 0;
    while(val<=n*n){
        int j = i;
        while(j<n-i) res[i][j++] = val++;
        j = i+1;
        while(j<n-i) res[j++][n-i-1] = val++;
        j = n - i - 2;
        while(j>i) res[n-i-1][j--] = val++;
        j = n-i-1;
        while(j>i) res[j--][i] = val++;
        i++;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/spiral-matrix-ii/
    return 0;
}
