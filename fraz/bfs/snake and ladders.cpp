#include <iostream>
using namespace std;

void getCoordinates(int n,int s,int &row, int &col){
    row = n-1-(s-1)/n;
    col = (s-1)%n;
    if((n%2==1 && row%2==1)||(n%2==0 && row%2==0)) col = n-1-col;
}

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<bool> visited(n*n+1,false);
    visited[1] = true;
    queue<pair<int,int>> q({{1,0}});
    while(!q.empty()){
        auto[s,dist] = q.front();q.pop();
        int row,col;
        if(s == n*n) return dist;
        for (int i = 1; s+i<=n*n && i <= 6; i++) {
            getCoordinates(n,s+i,row,col);
            int final = board[row][col] == -1?s+i:board[row][col]; // for snake or lader
            if(!visited[final]){
                visited[final] = true;
                q.emplace(final,dist+1);
            }
        }
    }
    return -1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/snakes-and-ladders/discuss/794701/C%2B%2B%3A-bfs-oror-detailed-explanation-oror-faster-than-99.31
	return 0;
}

