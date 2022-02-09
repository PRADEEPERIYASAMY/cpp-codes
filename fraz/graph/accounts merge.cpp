#include <iostream>
using namespace std;

void dfs(unordered_map<string,unordered_set<string>> & graph, unordered_set<string> & visited, string s, vector<string> & ans){
    ans.push_back(s);
    visited.insert(s);
    for (auto str : graph[s]) {
        if(visited.find(str) == visited.end()) dfs(graph,visited,str,ans);
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,unordered_set<string>> graph;
    vector<vector<string>> res;
    for (auto &ls : accounts) {
        for (int i = 1; i < ls.size(); i++) {
            graph[ls[i]].insert(ls[1]);
            graph[ls[1]].insert(ls[i]);
        }
    }
    unordered_set<string> visited;
    for (auto &ls : accounts) {
        if(visited.find(ls[1]) == visited.end()){
            vector<string> ans;
            dfs(graph,visited,ls[1],ans);
            sort(ans.begin(),ans.end());
            ans.insert(ans.begin(),ls[0]);
            res.push_back(ans);
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/accounts-merge/discuss/1208053/Simple-DFS-with-step-by-step-detailed-explanation(by-taking-string-as-an-integer).
	return 0;
}

