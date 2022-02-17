#include <iostream>
using namespace std;

int reachableNodes(vector<vector<int>>& edges, int M, int N) {
    vector<int> dist(N,INT_MAX);
    unordered_map<int,unordered_map<int,int>> graph;
    for (auto &edge : edges) graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = edge[2]+1;
    auto cmp = [](const pair<int,int> &a,const pair<int,int> &b){return a.second>b.second;};
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        auto u = pq.top().first;pq.pop();
        if(dist[u]>=M) break;
        for (auto [v,w] : graph[u]) {
            if(dist[u]+w<dist[v]){
                dist[v] = w+dist[u];
                pq.push({v,dist[v]});
            }
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) if(dist[i]<=M) res++;
    for (auto &e : edges) {
        int a = dist[e[0]]>=M?0:min(M - dist[e[0]],e[2]);
        int b = dist[e[1]]>=M?0:min(M - dist[e[1]],e[2]);
        res+=min(a+b,e[2]);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/discuss/1458975/C%2B%2B-%3A-Directly-applying-dijkstra-for-shortest-paths
	return 0;
}

