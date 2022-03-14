#include <bits/stdc++.h>
using namespace std;

// bool isValidSudoku(vector<vector<char>> &board){
//     if(board.empty() || board[0].empty() || board.size() != board[0].size()) return false;
//     int n = board.size();
//     vector<vector<bool>> row(n,vector<bool>(n,false)),col(n,vector<bool>(n,false)),box(n,vector<bool>(n,false));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if(board[i][j] == '.') continue;
//             int k = board[i][j] - '1';
//             if(row[i][k] || col[j][k] || box[3*(i/3)+(j/3)][k]) return false;
//             row[i][k] = col[j][k] = box[3*(i/3)+(j/3)][k] = true;
//         }
//     }
//     return true;
// }

// space optimization
bool isValidSudoku(vector<vector<char>> &board){
    if(board.empty() || board[0].empty() || board.size() != board[0].size()) return false;
    int n = board.size();
    vector<int> row(n,0),col(n,0),box(n,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == '.') continue;
            int k = 1<<board[i][j] - '1';
            if(row[i]&k || col[j]&k || box[3*(i/3)+(j/3)]&k) return false;
            row[i]|=k;
            col[j]|=k;
            box[3*(i/3)+(j/3)] |= k;
        }
    }
    return true;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/valid-sudoku/
    return 0;
}
