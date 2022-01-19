using namespace std;
#include <bits/stdc++.h>
#define ROW 5
#define COL 5

bool isSafe(int M[][COL],int row,int col,bool visited[][COL]){
    return row>=0 && row<ROW && col>=0 && col<COL && !visited[row][col] && M[row][col];
}

void DFS(int M[][COL],int row,int col,bool visited[][COL]){
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    visited[row][col] = true;
    for (int i = 0; i < 8; i++) if(isSafe(M,row+rowNbr[i],col+colNbr[i],visited)) DFS(M,row+rowNbr[i],col+colNbr[i],visited);
}

int countIslands(int M[][COL]){
    bool visited[ROW][COL];
    memset(visited,false,sizeof(visited));
    int count = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if(M[i][j] && !visited[i][j]){
                DFS(M,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
 
    cout << "Number of islands is: " << countIslands(M);
    return 0;
}

