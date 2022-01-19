using namespace std;
#include <bits/stdc++.h>
#define M 6
#define N 6

void floodFillUtil(char mat[][N],int x,int y,char prevC,char newC){
    if(x<0 || x>=M || y<0 || y>=N) return;
    if(mat[x][y]!= prevC) return;
    if(mat[x][y] == newC) return;
    mat[x][y] = newC;
    floodFillUtil(mat,x+1,y,prevC,newC);
    floodFillUtil(mat,x-1,y,prevC,newC);
    floodFillUtil(mat,x,y+1,prevC,newC);
    floodFillUtil(mat,x,y-1,prevC,newC);
}

void replaceSurrounded(char mat[][N]){
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if(mat[i][j] == 'O') mat[i][j] = '-';
    for (int i = 0; i < M; i++) if(mat[i][0] == '-') floodFillUtil(mat,i,0,'-','O');
    for (int i = 0; i < M; i++) if(mat[i][N-1] == '-') floodFillUtil(mat,i,N-1,'-','O');
    for (int i = 0; i < N; i++) if(mat[0][i] == '-') floodFillUtil(mat,0,i,'-','O');
    for (int i = 0; i < M; i++) if(mat[N-1][i] == '-') floodFillUtil(mat,M-1,i,'-','O');
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if(mat[i][j] == '-') mat[i][j] = 'X';
}
int main(){
    char mat[][N] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
    replaceSurrounded(mat);
    for (int i=0; i<M; i++){
      for (int j=0; j<N; j++)cout << mat[i][j] << " ";
      cout << endl;
    }
    return 0;
}

