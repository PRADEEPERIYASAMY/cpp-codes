using namespace std;
#include <bits/stdc++.h>

int countNegatives(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int i = 0;
    int j = m-1;
    int count = 0;
    while(i<n && j>=0){
        if(grid[i][j]<0){
            count+=(n-i);
            j--;
        }else i++;
    }
    return count;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/1660839/O(n%2Bm)ororC%2B%2BororEasy
    return 0;
}

