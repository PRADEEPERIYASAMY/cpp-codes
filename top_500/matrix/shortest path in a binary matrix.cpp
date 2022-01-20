using namespace std;
#include <bits/stdc++.h>
#define ROW 9
#define COL 10

struct Point{
    int x,y;
};

struct Node{
    Point pt;
    int dist;
};

bool isValid(int row,int col){
    return row>= 0 && row<ROW && col>=0 && col<COL;
}

int rowNum[] = {-1,0,0,1};
int colNum[] = {0,-1,1,0};

int BFS(int mat[][COL],Point src,Point dest){
    if(!mat[src.x][src.y] || !mat[dest.x][dest.y]) return -1;
    bool visited[ROW][COL];
    memset(visited,false,sizeof(visited));
    visited[src.x][src.y] = true;
    queue<Node> q;
    q.push({src,0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        if(temp.pt.x == dest.x && temp.pt.y == dest.y) return temp.dist;
        for (int i = 0; i < 4; i++) {
            int r = temp.pt.x+rowNum[i];
            int c = temp.pt.y+colNum[i];
            if( isValid(r,c) && !visited[r][c] && mat[r][c]){
                visited[r][c] = true;
                q.push({{r,c},temp.dist+1});
            }
        }
    }
    return -1;
}

int main(){
    int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

    Point source = {0, 0};
    Point dest = {3, 4};
    int dist = BFS(mat, source, dest);
    if (dist != -1) cout << "Shortest Path is " << dist ;
    else cout << "Shortest Path doesn't exist";
    return 0;
}

