#include <bits/stdc++.h>
using namespace std;
#define N 9

bool isValid(set<pair<int,int>> visited,pair<int,int> pt){
    return pt.first >= 0 && pt.first <N && pt.second >= 0 && pt.second<N && visited.find(pt) == visited.end();
}

void printPath(vector<pair<int,int>> path){
    for (auto &i : path) cout<<"("<<i.first<<" "<<i.second<< ") ->";
    cout<<"MID"<<endl;
}

int row[]={-1,1,0,0};
int col[]={0,0,-1,1};

int _row[]={0,0,N-1,N-1};
int _col[]={0,N-1,0,N-1};

void findPathInMazeUtil(int maze[N][N],vector<pair<int,int>> &path,set<pair<int,int>> &visited,pair<int,int> &cur){
    if(cur.first == N/2 && cur.second == N/2){
        printPath(path);
        return;
    }
    for (int i = 0; i < 4; i++) {
        auto [first,second] = cur;
        int n = maze[first][second];
        int x = first+row[i]*n;
        int y = second+col[i]*n;
        if(isValid(visited,{x,y})){
            pair<int,int> pt({x,y});
            visited.insert(pt);
            path.push_back(pt);
            findPathInMazeUtil(maze,path,visited,pt);
            path.pop_back();
            visited.erase(pt);
        }
    }
}

void findPathInMaze(int maze[N][N]){
    vector<pair<int,int>> path;
    set<pair<int,int>> visited;
    for (int i = 0; i < 4; i++) {
        int x = _row[i],y = _col[i];
        pair<int,int> pt({x,y});
        visited.insert(pt);
        path.push_back(pt);
        findPathInMazeUtil(maze,path,visited,pt);
        path.pop_back();
        visited.erase(pt);
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/
	int maze[N][N] =
    {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };
    findPathInMaze(maze);
    return 0;
}

