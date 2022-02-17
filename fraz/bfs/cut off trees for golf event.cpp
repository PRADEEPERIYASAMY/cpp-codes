#include <iostream>
using namespace std;

int nextStep(vector<vector<int>> &forest,int srcRow,int srcCol,int endRow,int endCol,vector<vector<int>> &dirs){
    if(srcRow == endRow && srcCol == endCol) return 0;
    int m = forest.size(),n = forest[0].size();
    queue<pair<int,int>> q({{srcRow,srcCol}});
    vector<vector<int>> visited(m,vector<int>(n,0));
    visited[srcRow][srcCol] = 1;
    int step = 0;
    while(!q.empty()){
        step++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto[row,col] = q.front();q.pop();
            for (auto &dir : dirs) {
                int r = dir[0]+row,c = dir[1]+col;
                if(r<0 || r>= m || c<0 || c>= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                if(r == endRow && c == endCol) return step;
                visited[r][c] = 1;
                q.push({r,c});
            }
        }
    }
    return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
    if(forest.empty() || forest[0].empty()) return 0;
    int m = forest.size(),n = forest[0].size();
    vector<vector<int>> trees;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(forest[i][j]>1) trees.push_back({forest[i][j],i,j});
        }
    }
    sort(trees.begin(),trees.end());
    vector<vector<int>> dirs({{-1,0},{1,0},{0,-1},{0,1}});
    int ans = 0,curRow = 0,curCol = 0;
    for (int i = 0; i < trees.size(); i++) {
        int step = nextStep(forest,curRow,curCol,trees[i][1],trees[i][2],dirs);
        if(step == -1) return -1;
        ans+=step;
        curRow = trees[i][1];
        curCol = trees[i][2];
    }
    return ans;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/cut-off-trees-for-golf-event/discuss/107403/C%2B%2B-Sort-%2B-BFS-with-explanation
	return 0;
}

