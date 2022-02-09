#include <iostream>
using namespace std;

double dfs(unordered_map<string,unordered_map<string,double>> &graph,string a,string b,unordered_set<string> &visited){
    if(graph[a].find(b) != graph[a].end()) return graph[a][b];
    for (auto &v : graph[a]) {
        if(visited.find(v.first) == visited.end()){
            visited.insert(v.first);
            double dist = dfs(graph,v.first,b,visited);
            if(dist){
                graph[a][b] = v.second*dist;
                return graph[a][b];
            }
        }
    }
    return 0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> result;
    unordered_map<string,unordered_map<string,double>> graph;
    for (int i = 0; i < equations.size(); i++) {
        graph[equations[i][0]][equations[i][1]] = (values[i]);
        graph[equations[i][1]][equations[i][0]] = (double) 1/(values[i]);
    }
    for (int i = 0; i < queries.size(); i++) {
        unordered_set<string> visited;
        double val = dfs(graph,queries[i][0],queries[i][1],visited);
        result.push_back(val == 0?(double(-1.0)):val);
    }
    return result;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/evaluate-division/discuss/1387800/C%2B%2B-0ms-DFS
	return 0;
}

