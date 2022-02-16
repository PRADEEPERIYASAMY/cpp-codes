#include <iostream>
using namespace std;

struct cluster{
    set<pair<int,int>> cont,uncont;
    int walls = 0;
};

void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &visited,cluster &c){
    if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size() || visited[i][j] || grid[i][j] == -1) return;
    if(grid[i][j] == 0){
        c.walls++;
        c.uncont.insert({i,j});
        return;
    }
    c.cont.insert({i,j});
    visited[i][j] = true;
    dfs(grid,i+1,j,visited,c);
    dfs(grid,i-1,j,visited,c);
    dfs(grid,i,j-1,visited,c);
    dfs(grid,i,j+1,visited,c);
}

int containVirus(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size(),ans = 0;
    while(1){
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        auto comp = [](const cluster& A, const cluster &B){return A.uncont.size()<B.uncont.size();};
        priority_queue<cluster,vector<cluster>,decltype(comp)> pq(comp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visited[i][j]&& grid[i][j] == 1){
                    cluster c;
                    dfs(grid,i,j,visited,c);
                    pq.push(c);
                }
            }
        }
        if(pq.empty()) break;
        cluster k = pq.top();pq.pop();
        for (auto &i : k.cont) grid[i.first][i.second] = -1;
        ans+=k.walls;
        while(!pq.empty()){
            cluster t = pq.top();pq.pop();
            for (auto &i : t.uncont) grid[i.first][i.second] = 1;
        }
    }
    return ans;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/contain-virus/discuss/847507/CPP-DFS-solution-explained
	return 0;
}

