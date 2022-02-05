#include <iostream>
using namespace std;

// bool searchMatrix(vector<vector<int>>& matrix, int target) { // time: O(m + n)
//     if(matrix.empty() || matrix[0].empty() || matrix[0][0]>target || matrix.back().back()<target) return false;
//     int m = matrix.size(),n = matrix[0].size();
//     int row = 0,col = n -1;
//     while(row<m && col>= 0){
//         if(matrix[row][col]>target) col--;
//         else if(matrix[row][col]<target) row++;
//         else return true;
//     }
//     return false;
// }

bool searchMatrix(vector<vector<int>>& matrix, int target) { // time: O(log(mn));
    if(matrix.empty() || matrix[0].empty() || matrix[0][0]>target || matrix.back().back()<target) return false;
    int m = matrix.size(),n = matrix[0].size(),low = 0,high = n*m-1;
    while(low<=high){
        int mid = low+(high-low)/2,row = mid/n,col = mid%n;
        if(matrix[row][col]>target) high = mid - 1;
        else if(matrix[row][col]<target) low = mid+1;
        else return true;
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/search-a-2d-matrix/submissions/
	return 0;
}

