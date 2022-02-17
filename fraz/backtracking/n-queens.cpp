#include <iostream>
using namespace std;

// naive
// bool isvalid(vector<string> &cur,int row,int col){
//     int n = cur.size();
//     for (int i = 0; i < row; i++) if(cur[i][col] == 'Q') return false;
//     for (int i = row -1,j = col-1; i >=0 && j>= 0; --i,--j) if(cur[i][j] == 'Q') return false;
//     for (int i = row-1,j = col+1;i>=0 && j<n;--i,++j) if(cur[i][j] == 'Q') return false;
//     return true;
// }

// void helper(vector<vector<string>> &res,vector<string> &cur, int row){
//     int n = cur.size();
//     if(row == n) res.push_back(cur);
//     else{
//         for (int col = 0; col <n; col++) {
//             if(isvalid(cur,row,col)){
//                 cur[row][col] = 'Q';
//                 helper(res,cur,row+1);
//                 cur[row][col] = '.';
//             }
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> res;
//     vector<string> cur(n,string(n,'.'));
//     helper(res,cur,0);
//     return res;
// }

void helper(vector<vector<string>> &res,vector<string> &cur,vector<int> &flag, int row){
    int n = cur.size();
    if(row == n) res.push_back(cur);
    else{
        for (int col = 0; col < n; col++) {
            if(flag[col] && flag[n+row+col] && flag[n+ 2*n-1 + n-1 + col - row]){
                flag[col] = flag[n+row+col] = flag[n+ 2*n-1 + n-1 + col - row] = 0;
                cur[row][col] = 'Q';
                helper(res,cur,flag,row+1);
                cur[row][col] = '.';
                flag[col] = flag[n+row+col] = flag[n+ 2*n-1 + n-1 + col - row] = 1;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> cur(n,string(n,'.'));
    vector<int> flag(5*n-2,1);
    helper(res,cur,flag,0);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/n-queens/
	// https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.
	return 0;
}

