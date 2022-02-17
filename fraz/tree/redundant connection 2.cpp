#include <iostream>
using namespace std;

int getRoot(vector<int> &root,int i){
    return root[i] == i?i:root[i] = getRoot(root,root[i]);
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> root(n+1,0),sz(n+1,0),first,second;
    for (auto &edge : edges) {
        if(root[edge[1]] == 0) root[edge[1]] = edge[0];
        else{
            first = {root[edge[1]],edge[1]};
            second = edge;
            edge[1] = 0;
            break;
        }
    }
    for (int i = 0; i <= n; i++) root[i] = i;
    for (auto &edge : edges) {
        if(edge[1] == 0) continue;
        int r1 = getRoot(root,edge[0]),r2 = getRoot(root,edge[1]);
        if(r1 == r2) return first.empty()?edge:first;
        if(sz[r1]<sz[r2]){
            root[r1] = r2;
            sz[r2]+=sz[r1];
        }else{
            root[r2] = r1;
            sz[r1]+=sz[r2];
        }
    }
    return second;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/redundant-connection-ii/
	return 0;
}

