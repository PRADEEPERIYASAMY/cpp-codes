using namespace std;
#include <bits/stdc++.h>

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(),n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int x = max(0,i-1); x < min(m,i+2); x++) for (int y = max(0,j-1); y < min(n,j+2); y++) count+=board[x][y]&1;
            // count includes current sell itself
            if(count == 3 || count - board[i][j] == 3) board[i][j] |=2;
        }
    }
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) board[i][j] >>= 1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/game-of-life/
    return 0;
}

