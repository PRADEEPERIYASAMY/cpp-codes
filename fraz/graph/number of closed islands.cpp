#include <iostream>
using namespace std;

bool dfs(vector<vector<int>> &g,int i,int j){
    if(i<0 || i>= g.size() || j<0 || j>= g[0].size()) return false;
    if(g[i][j] == 1) return true;
    g[i][j] = 1;
    bool d1 = dfs(g,i+1,j);
    bool d2 = dfs(g,i,j+1);
    bool d3 = dfs(g,i-1,j);
    bool d4 = dfs(g,i,j-1);
    /* IMPORTANT NOTE: 
        WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
    */
    return d1 && d2 && d3 && d4;
}

int closedIsland(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) for (int j = 0; j < grid[0].size(); j++) if(grid[i][j] == 0) res+=dfs(grid,i,j)?1:0;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/number-of-closed-islands/discuss/546884/C%2B%2B-easy-DFS-(faster-than-99.81-memory-less-than-100)
	return 0;
}

