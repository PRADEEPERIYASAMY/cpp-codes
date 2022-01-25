using namespace std;
#include <bits/stdc++.h>

//bfs
// vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//     vector<vector<int>> graph(numCourses);
//     vector<int> indegree(numCourses,0),res;
//     for (auto &i : prerequisites) graph[i[1]].push_back(i[0]),indegree[i[0]]++;
//     queue<int> q;
//     for (int i = 0; i < numCourses; i++) if(indegree[i] == 0) q.push(i);
//     while(!q.empty()){
//         int t = q.front();q.pop();
//         res.push_back(t);
//         for (auto &i : graph[t]) if(--indegree[i] == 0) q.push(i);
//     }
//     if(res.size() != numCourses) res.clear();
//     return res;
// }

//dfs
bool dfs(vector<vector<int>> &graph,vector<int> &visited,int i,vector<int> &res){
    if(visited[i] == -1) return false; // same cycle
    if(visited[i] == 1) return true; // visited
    visited[i] = -1;
    for (auto &a : graph[i]) if(!dfs(graph,visited,a,res)) return false;
    visited[i] = 1;
    res.push_back(i);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> visited(numCourses,0),res;
    for (auto &i : prerequisites) graph[i[1]].push_back(i[0]);
    for (int i = 0; i < numCourses; i++) if(!dfs(graph,visited,i,res)) return {};
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/course-schedule-ii/
    return 0;
}

