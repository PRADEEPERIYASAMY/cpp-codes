using namespace std;
#include <bits/stdc++.h>

//bfs
// int findCircleNum(vector<vector<int> >& M) {
//     int n = M.size(),res = 0;
//     vector<bool> visited(n,false);
//     queue<int> q;
//     for (int i = 0; i < n; i++) {
//         if(visited[i]) continue;
//         q.push(i);
//         while(!q.empty()){
//             int t = q.front();q.pop();
//             visited[t]  = true;
//             for (int j = 0; j < n; j++) {
//                 if(M[t][j] == 0 || visited[j]) continue;
//                 q.push(j);
//             }
//         }
//         res++;
//     }
//     return res;
// }

//dfs
void dfs(vector<vector<int>> &M,vector<bool> &visited,int i){
    visited[i] = true;
    for (int j = 0; j < M.size(); j++) {
        if(M[i][j] != 1 || visited[j]) continue;
        dfs(M,visited,j);
    }
}

int findCircleNum(vector<vector<int> >& M) {
    int n = M.size(),res =0;
    vector<bool> visited(n,false);
    for (int i = 0; i < n; i++) {
        if(visited[i]) continue;
        dfs(M,visited,i);
        res++;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/number-of-provinces/
    return 0;
}

