using namespace std;
#include <bits/stdc++.h>

//bfs 
// void solve(vector<vector<char>>& board) {
//     if(board.empty() || board[0].empty()) return;
//     int m = board.size(),n = board[0].size();
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if(i != 0 && i != m-1 && j!=0 && j != n-1) continue;
//             if(board[i][j] != 'O') continue;
//             board[i][j] = '$';
//             queue<pair<int,int>> q;
//             q.push({i,j});
//             while(!q.empty()){
//                 auto t = q.front();q.pop();
//                 int x = t.first,y = t.second;
//                 if(x>=1 && board[x-1][y] == 'O'){
//                     board[x-1][y] = '$';
//                     q.push({x-1,y});
//                 }
//                 if(x<m-1 && board[x+1][y] == 'O'){
//                     board[x+1][y] = '$';
//                     q.push({x+1,y});
//                 } 
//                 if(y>= 1 && board[x][y-1] == 'O'){
//                     board[x][y-1];
//                     q.push({x,y-1});
//                 }
//                 if(y<n-1 && board[x][y+1] == 'O'){
//                     board[x][y+1] = '$';
//                     q.push({x,y+1});
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if(board[i][j] == 'O') board[i][j] = 'X';
//             if(board[i][j] == '$') board[i][j] = 'O';
//         }
//     }
// }

//dfs 
void helper(vector<vector<char> >& board, int i, int j) {
    if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != 'O') return;
    board[i][j] = '$';
    helper(board,i-1,j);
    helper(board,i+1,j);
    helper(board,i,j-1);
    helper(board,i,j+1);
}

void solve(vector<vector<char>>& board) {
    if(board.empty() || board[0].empty()) return;
    const int m = board.size(),n = board[0].size();
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if((i ==0 || i == m-1 || j == 0 || j == n-1) && board[i][j] =='O' ) helper(board,i,j);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if(board[i][j] == '$') board[i][j] = 'O';
        }
    }
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/surrounded-regions/
    return 0;
}

