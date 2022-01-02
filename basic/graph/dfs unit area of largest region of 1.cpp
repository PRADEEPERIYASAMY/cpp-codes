#include <bits/stdc++.h> 
using namespace std; 
#define ROW 4
#define COL 5

int isSafe(int M[][COL], int row, int col,bool visited[][COL]){
    return (row >= 0) && (row < ROW) && (col >= 0)&& (col < COL)&& (M[row][col] && !visited[row][col]);
}

void DFS(int M[ROW][COL],int row,int col, bool visited[ROW][COL], int &count){
    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};
    visited[row][col] = true;
    for (int i = 0; i < 8; i++) {
        if(isSafe(M,row+dx[i],col+dy[i],visited)){
            count++;
            DFS(M,row+dx[i],col+dy[i],visited,count);
        }
    }
}

int largestRegion(int M[ROW][COL]){
    bool visited[ROW][COL];
    memset(visited,false,sizeof(visited));
    int res = INT_MIN;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if(M[i][j] == 1 && !visited[i][j] ){
                int count = 1;
                DFS(M,i,j,visited,count);
                res= max(res,count);
            }
        }
    }
    return res;
}

// using dfs
int main(){
    int M[ROW][COL] = { { 0, 0, 1, 1, 0 },
                     { 1, 0, 1, 1, 0 },
                     { 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 0, 1 } };

    cout << largestRegion(M);
    return 0;
}

