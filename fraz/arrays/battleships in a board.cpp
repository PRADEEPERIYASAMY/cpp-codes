#include <bits/stdc++.h>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
    int m = board.size(),n = board[0].size(),res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == '.' || (i>0 && board[i-1][j] == 'X') || (j>0 && board[i][j-1] == 'X')) continue;
            res++;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/battleships-in-a-board/
    return 0;
}
