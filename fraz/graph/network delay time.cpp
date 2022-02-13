#include <iostream>
using namespace std;

// Floyd–Warshall Algorithm
// int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//     vector<vector<double>> dist(N+1,vector<double>(N+1,INT_MAX));
//     for (int i = 1; i <= N; i++) dist[i][i] = 0;
//     for (auto &t : times) dist[t[0]][t[1]] = t[2];
//     for (int k = 1; k <= N; k++) {
//         for (int i = 1; i <= N; i++) {
//             for (int j = 1; j <= N; j++) {
//                 if(dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j] = dist[i][k]+dist[k][j];
//             }
//         }
//     }
//     double res = 0;
//     for (int i = 1; i <= N; i++) {
//         if(dist[K][i] == INT_MAX) return -1;
//         res = max(res,dist[K][i]);
//     }
//     return (int)res;
// }

// Bellman-Ford Algortihm
// int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//     vector<int> dist(N+1,INT_MAX);
//     dist[K] = 0;
//     for (int i = 1; i < N; i++) {
//         for (auto &t : times) {
//             int u = t[0],v = t[1],w = t[2];
//             if(dist[u] != INT_MAX && dist[v]>dist[u]+w) dist[v] = dist[u]+w;
//         }
//     }
//     int res = *max_element(dist.begin()+1,dist.end());
//     return res == INT_MAX?-1:res;
// }

// Dijkstra Algorithm
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<int>> edges(N+1,vector<int>(N+1,-1));
    for (auto &t : times) edges[t[0]][t[1]] = t[2];
    vector<int> dist(N+1,INT_MAX);
    dist[K] = 0;
    queue<int> q({K});
    while(!q.empty()){
        for (int i = q.size()-1; i >= 0; i--) {
            int u = q.front();q.pop();
            for (int v = 1; v <= N; v++) {
                if(edges[u][v] != -1 && dist[u] != INT_MAX && dist[v]>dist[u]+edges[u][v]){
                    q.push(v);
                    dist[v] = dist[u]+edges[u][v];
                }
            }
        }
    }
    int res = *max_element(dist.begin()+1,dist.end());
    return res == INT_MAX?-1:res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/network-delay-time/
	return 0;
}

