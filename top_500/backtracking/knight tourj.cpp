using namespace std;
#include <bits/stdc++.h>
#define N 8

int isSafe(int x, int y,int sol[N][N]){
    return x>= 0 && x<N && y>= 0 && y<N && sol[x][y] == -1;
}

void printSolution(int sol[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout<<" "<<setw(2)<<sol[i][j]<<" ";
        cout<<endl;
    }
}

int solveKTUtil(int x,int y,int moveI,int sol[N][N],int xMoves[],int yMoves[]){
    int next_x,next_y;
    if(moveI == N*N)return 1;
    for (int k = 0; k < 8; k++) {
        next_x = x+xMoves[k];
        next_y = y+yMoves[k];
        if(isSafe(next_x,next_y,sol)){
            sol[next_x][next_y] = moveI;
            if(solveKTUtil(next_x,next_y,moveI+1,sol,xMoves,yMoves)) return 1;
            else sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

int solveKT(){
    int sol[N][N];
    memset(sol,-1,sizeof(sol));
    int xMoves[8] = {2,1,-1,-2,-2,-1,1,2};
    int yMoves[8] = {1,2,2,1,-1,-2,-2,-1};
    sol[0][0]=0;
    if(!solveKTUtil(0,0,1,sol,xMoves,yMoves)){
        cout<<"Solve does not exists";
        return 0;
    }else printSolution(sol);
    return 1;
}

int main() {
    solveKT();
	return 0;
}

