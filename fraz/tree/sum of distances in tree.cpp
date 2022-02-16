#include <iostream>
using namespace std;

void postOrder(vector<vector<int>> &tree,int cur,int pre,vector<int> &count,vector<int> &res){
    for (auto &i : tree[cur]) {
        if(i == pre) continue;
        postOrder(tree,i,cur,count,res);
        count[cur]+=count[i];
        res[cur]+=res[i]+count[i];
    }
    count[cur]++;
}

void preOrder(vector<vector<int>> &tree,int cur,int pre,vector<int> &count,vector<int> &res){
    for (auto &i : tree[cur]) {
        if(i == pre) continue;
        res[i] = res[cur] - count[i]+count.size() - count[i];
        preOrder(tree,i,cur,count,res);
    }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<int> res(N),count(N);
    vector<vector<int>> tree(N);
    for (auto edge : edges) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
    postOrder(tree,0,-1,count,res);
    preOrder(tree,0,-1,count,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/sum-of-distances-in-tree/
	return 0;
}

