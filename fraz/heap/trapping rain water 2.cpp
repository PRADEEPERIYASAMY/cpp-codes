#include <iostream>
using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    if(heightMap.empty()) return 0;
    int res = 0,sealevel = 0,m = heightMap.size(),n = heightMap[0].size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<vector<int>> dirs ({{-1,0},{1,0},{0,-1},{0,1}});
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(i == 0 || i == m-1 || j == 0 || j == n-1){
                pq.push({heightMap[i][j],i*n+j});
                visited[i][j] = true;
            } 
        }
    }
    while(!pq.empty()){
        auto t = pq.top();pq.pop();
        int h = t.first, r = t.second/n,c = t.second%n;
        sealevel = max(sealevel,h);
        for (auto &dir : dirs) {
            int x = r+dir[0],y = c+dir[1];
            if(x<0 || x>= m || y<0 || y>= n || visited[x][y]) continue;
            visited[x][y] = true;
            if(heightMap[x][y]<sealevel) res+=(sealevel-heightMap[x][y]);
            pq.push({heightMap[x][y],x*n+y});
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/trapping-rain-water-ii/
	return 0;
}

