#include <bits/stdc++.h>
using namespace std;
#define N 12

int dfs(vector<int> tree[N],int visited[N],int &ans,int node){
    int num = 0,temp = 0;
    visited[node] = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        if(visited[tree[node][i]] == 0){
            temp = dfs(tree,visited,ans,tree[node][i]);
            temp%2?num+=temp:ans++;
        }
    }
    return num+1;
}

int minEdge(vector<int> tree[N],int n){
    int visited[n+2] = {0};
    int ans = 0;
    dfs(tree,visited,ans,1);
    return ans;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/convert-tree-forest-even-nodes/
	int n = 10;
    vector<int> tree[n+2];
    tree[1].push_back(3);
    tree[3].push_back(1);
    tree[1].push_back(6);
    tree[6].push_back(1);
    tree[1].push_back(2);
    tree[2].push_back(1);
    tree[3].push_back(4);
    tree[4].push_back(3);
    tree[6].push_back(8);
    tree[8].push_back(6);
    tree[2].push_back(7);
    tree[7].push_back(2);
    tree[2].push_back(5);
    tree[5].push_back(2);
    tree[4].push_back(9);
    tree[9].push_back(4);
    tree[4].push_back(10);
    tree[10].push_back(4);
    cout << minEdge(tree, n) << endl;
    return 0;
}
