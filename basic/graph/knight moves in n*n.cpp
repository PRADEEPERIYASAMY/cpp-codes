#include <bits/stdc++.h> 
using namespace std; 

struct Cell{
  int x,y,dist;
  Cell(int i,int j){
      this->x = i;
      this->y = j;
      dist = 0;
  }
};

bool isInside(int x,int y,int N){
    if(x >= 1 && x <= N && y>= 1 && y<= N) return true;
    return false;
}

// using bfs
int minStepToReachTarget(int knightPos[],int targetPos[],int N){
    int dx[] ={-2,-1,1,2,-2,-1,1,2};
    int dy[] ={-1,-2,-2,-1,1,2,2,1};
    queue<Cell> q;
    q.push(Cell(knightPos[0],knightPos[1]));
    bool visited[N+1][N+1];
    memset(visited,false,sizeof(visited));
    visited[knightPos[0]][knightPos[1]] = true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(t.x == targetPos[0] && t.y == targetPos[1]) return t.dist;
        for (int i = 0; i < 8; i++) {
            int x = t.x+dx[i];
            int y = t.y+dy[i];
            if(isInside(x,y,N) && !visited[x][y]){
                visited[x][y] = true;
                Cell c =  Cell(x,y);
                c.dist = t.dist+1;
                q.push(c);
            }
        }
    }
}

int main(){
    int N = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}

