using namespace std;
#include <bits/stdc++.h>

bool helper(vector<vector<char>> &board,string &word,int idx,int i,int j,vector<vector<bool>> &visited){
    if(idx == word.size()) return true;
    int m = board.size(),n = board[0].size();
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || board[i][j] != word[idx]) return false;
    visited[i][j] = true;
    bool res = helper(board,word,idx+1,i-1,j,visited) || helper(board,word,idx+1,i+1,j,visited) || helper(board,word,idx+1,i,j-1,visited) || helper(board,word,idx+1,i,j+1,visited);
    visited[i][j] = false;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    if(board.empty() || board[0].empty()) return false;
    int m = board.size(),n = board[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(helper(board,word,0,i,j,visited)) return true;
        }
    }
    return false;
}

// If the input 2D grids are allowed to modify, the additional boolean 2D array is not necessary by marking the original grid to some character such as '#' during searching.

int main(){
    //leet code solutions
    //https://leetcode.com/problems/word-search/
    return 0;
}

