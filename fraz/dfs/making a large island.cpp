#include <iostream>
using namespace std;

// solution is bit modified to handle tle 
int N;
vector<vector<int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(vector<vector<int>> &grid,int i,int j,int index){
    int area = 0;
    grid[i][j] = index;
    for (auto &p : dirs) {
        int x = i+p[0],y = j+p[1];
        if(x< 0 || x>= N || y<0 || y>=N) continue;
        if(grid[x][y] == 1) area+=dfs(grid,x,y,index);
    }
    return area+1;
}

int largestIsland(vector<vector<int>>& grid) {
    N = grid.size();
    int index = 2,res = 0;
    unordered_map<int,int> area;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(grid[i][j] == 1) {
                area[index] = dfs(grid,i,j,index);
                res = max(res,area[index++]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(grid[i][j] == 0){
                unordered_set<int> seen;
                int cur = 1;
                for (auto &p : dirs) {
                    int x = i+p[0],y = j+p[1];
                    if(x< 0 || x>= N || y<0 || y>=N) continue;
                    index = grid[x][y];
                    if(index>1 && seen.count(index) == 0){
                        seen.insert(index);
                        cur+=area[index];
                    }
                }
                res = max(res,cur);
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/making-a-large-island/discuss/127032/C%2B%2BJavaPython-Straight-Forward-O(N2)-with-Explanations
	return 0;
}

