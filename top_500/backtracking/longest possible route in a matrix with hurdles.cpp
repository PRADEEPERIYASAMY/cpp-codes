#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10

pair<bool,int> findLongestPathUtil(int mat[R][C],int i,int j,int x,int y,bool visited[R][C]){
    if(i == x && j == y)return pair<bool,int> ({true,0});
    
    if(i<0 || i>= R || j<0 || j>=C || mat[i][j] == 0 || visited[i][j]) return pair<bool,int> ({false,INT_MAX});
    
    visited[i][j] = true;
    int res = INT_MIN;
    auto sol = findLongestPathUtil(mat,i,j-1,x,y,visited);
    if(sol.first) res = max(res,sol.second);
    sol = findLongestPathUtil(mat,i,j+1,x,y,visited);
    if(sol.first) res = max(res,sol.second);
    sol = findLongestPathUtil(mat,i-1,j,x,y,visited);
    if(sol.first) res = max(res,sol.second);
    sol = findLongestPathUtil(mat,i+1,j,x,y,visited);
    if(sol.first) res = max(res,sol.second);
    visited[i][j] = false;
    if(res!=INT_MIN) return pair<bool,int> ({true,1+res});
    else return pair<bool,int> ({false,INT_MAX});
}

void findLongestPath(int mat[R][C],int i,int j,int x,int y){
    bool visited[R][C];
    memset(visited,false,sizeof(visited));
    pair<bool,int> p = findLongestPathUtil(mat,i,j,x,y,visited);
    if(p.first) cout<<"Length of longest route is "<<p.second;
    else cout<<"destination not reachable form given source";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/
	int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
    findLongestPath(mat, 0, 0, 1, 7);
	return 0;
}

