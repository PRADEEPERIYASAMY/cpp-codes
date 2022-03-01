#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

int rowNum[] = {-1,0,0,1};
int colNum[] = {0,-1,1,0};

bool isSafe(int mat[R][C],int visited[R][C],int x,int y){
    if(mat[x][y] == 0 || visited[x][y]) return false;
    return true;
}

bool isValid(int x,int y){
    if(x<R && y<x && x>=0 && y>= 0) return true;
    return false;
}

void markUnsafeCells(int mat[R][C]){
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(mat[i][j] == 0){
                for (int k = 0; k < 4; k++) {
                    if(isValid(i+rowNum[k],j+colNum[k])) mat[i+rowNum[k]][j+colNum[k]] = -1;
                }
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(mat[i][j] == -1) mat[i][j] = 0;
        }
    }
}

void findShortestPathUtil(int mat[R][C],int visited[R][C],int i,int j,int &minDist,int dist){
    if(j == C-1){
        minDist = min(dist,minDist);
        return;
    }
    if(dist>minDist) return;
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i+rowNum[k],y = j+colNum[k];
        if(isValid(x,y) && isSafe(mat,visited,x,y)){
            findShortestPathUtil(mat,visited,x,y,minDist,dist+1);
        }
    }
    visited[i][j] = 0;
}

void findShortestPath(int mat[R][C]){
    int minDist = INT_MAX;
    int visited[R][C];
    markUnsafeCells(mat);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            memset(visited,0,sizeof(visited));
            findShortestPathUtil(mat,visited,i,0,minDist,0);
            if(minDist == C-1) break;
        }
    }
    if(minDist != INT_MAX) cout<<"Length of shortest route is "<<minDist;
    else cout<<"Destination not reachable from given source";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/
	int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    findShortestPath(mat);
	return 0;
}

