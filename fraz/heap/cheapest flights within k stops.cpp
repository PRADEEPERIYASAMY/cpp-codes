#include <iostream>
using namespace std;

//dfs - time limit exceeded
// void helper(vector<vector<vector<int>>> &graph,vector<bool> &visited,int cur,int dst,int K,int out,int &res){
//     if(cur == dst){
//         res = out;
//         return;
//     }
//     if(K<0) return;
//     visited[cur] = true;
//     for (auto &i : graph[cur]) {
//         if(visited[i[0]]|| out+i[1]>res) continue;
//         helper(graph,visited,i[0],dst,K-1,out+i[1],res);
//     }
//     visited[cur] = false;
// } 

// int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//     int res = INT_MAX;
//     vector<vector<vector<int>>> graph(n);
//     vector<bool> visited(n,false);
//     visited[src] = true;
//     for (auto &i : flights) graph[i[0]].push_back({i[1],i[2]});
//     helper(graph,visited,src,dst,K,0,res);
//     return res == INT_MAX?-1:res;
// }

// BFS -- time limit exceeded
// int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) { 
//     int res = INT_MAX,count = 0;
//     vector<vector<vector<int>>> graph(n);
//     for (auto &i : flights) graph[i[0]].push_back({i[1],i[2]});
//     queue<vector<int>> q({{src,0}});
//     while(!q.empty()){
//         for (int i = q.size()-1; i >= 0; i--) {
//             auto t = q.front();q.pop();
//             if(t[0] == dst) res = min(res,t[1]);
//             for (auto &i : graph[t[0]]) {
//                 if(t[1]+i[1]>res) continue;
//                 q.push({i[0],t[1]+i[1]});
//             }
//         }
//         if(count++>K) break;
//     }
//     return res == INT_MAX?-1:res;
// }

// Bellman Ford Algorithm + DP
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<int>> dp(K+2,vector<int>(n,1e9));
    dp[0][src] = 0;
    for (int i = 1; i <= K+1; i++) {
        dp[i][src] = 0;
        for (auto &flight : flights) dp[i][flight[1]] = min(dp[i][flight[1]],dp[i-1][flight[0]]+flight[2]);
    }
    return (dp[K+1][dst]>= 1e9)?-1:dp[K+1][dst];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/cheapest-flights-within-k-stops/
	return 0;
}


