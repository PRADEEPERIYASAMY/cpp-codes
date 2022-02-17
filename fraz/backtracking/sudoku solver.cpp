#include <iostream>
using namespace std;

// bool isvalid(vector<vector<char>> &board,int r,int c){
//     for (int i = 0; i < 9; i++) {
//         if(i != c && board[r][i] == board[r][c]) return false;
//         if(i != r && board[i][c] == board[r][c]) return false;
//         int boxRow = 3*(r/3)+(i/3), boxCol = 3*(c/3)+(i%3);
//         if((boxRow != r || boxCol != c) && board[boxRow][boxCol] == board[r][c]) return false;
//     }
//     return true;
// }

// bool helper(vector<vector<char>> &board,int i,int j){
//     if(i == 9) return true;
//     if(j == 9) return helper(board,i+1,0);
//     if(board[i][j] == '.'){
//         for (char c = '1'; c <= '9'; c++) {
//             board[i][j] = c;
//             if(isvalid(board,i,j) && helper(board,i,j+1)) return true;
//             board[i][j] = '.';
//         }
//     }
//     else return helper(board,i,j+1);
//     return false;
// }

// void solveSudoku(vector<vector<char>>& board) {
//     if(board.size() != 9 || board[0].size() != 9) return;
//     helper(board,0,0);
// }

bool isvalid(vector<vector<char>> &board,int r,int c){
    for (int i = 0; i < 9; i++) {
        if(i != c && board[r][i] == board[r][c]) return false;
        if(i != r && board[i][c] == board[r][c]) return false;
        int boxRow = 3*(r/3)+(i/3), boxCol = 3*(c/3)+(i%3);
        if((boxRow != r || boxCol != c) && board[boxRow][boxCol] == board[r][c]) return false;
    }
    return true;
}

bool helper(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(board[i][j] != '.') continue;
            for (char c = '1'; c <= '9'; c++) {
                board[i][j] = c;
                if(isvalid(board,i,j) && helper(board)) return true;
                board[i][j] = '.';
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board){
    if(board.size() != 9 || board[0].size() != 9) return;
    helper(board);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/sudoku-solver/
	return 0;
}

