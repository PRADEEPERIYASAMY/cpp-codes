#include <bits/stdc++.h> 
using namespace std; 

#define ROW 5
#define COL 5

struct Cell{
  int x,y,dist;
  Cell(int i,int j,int dist){
      this->x = i;
      this->y = j;
      this->dist = 0;
  }
};

bool operator<(const Cell& a, const Cell& b){
    if (a.dist == b.dist){
        if (a.x != b.x) return (a.x < b.x);
        else return (a.y < b.y);
    }
    return (a.dist < b.dist);
}

bool isInside(int x,int y){
    if(x >= 0 && x < ROW && y>= 0 && y< COL) return true;
    return false;
}

// using bfs
int shortest(int grid[ROW][COL],int row,int col){
    int dist[row][col];
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) dist[i][j] = INT_MAX;
    int dx[] ={-1,0,1,0};
    int dy[] ={0,1,0,-1};
    set<Cell> q;
    q.insert(Cell(0,0,0));
    
    dist[0][0] = grid[0][0];
    while(!q.empty()){
        Cell t = *q.begin();
        q.erase(q.begin());
        for (int i = 0; i < 4; i++) {
            int x = t.x+dx[i];
            int y = t.y+dy[i];
            if(!isInside(x,y)) continue;
            if(dist[x][y] > dist[t.x][t.y]+grid[x][y]){
                //if(dist[x][y] != INT_MAX) q.erase(q.find(Cell(x,y,dist[x][y]))); // removing it's previous entry if found
                dist[x][y] = dist[t.x][t.y]+grid[x][y];
                q.insert(Cell(x,y,dist[x][y]));
            }
        }
    }
    return dist[row-1][col-1];
}

// done using dijkstra algo
int main(){
    int grid[ROW][COL] =
    {
        31, 100, 65, 12, 18,
        10, 13, 47, 157, 6,
        100, 113, 174, 11, 33,
        88, 124, 41, 20, 140,
        99, 32, 111, 41, 20
    };

    cout << shortest(grid, ROW, COL) << endl;
    return 0;
}

