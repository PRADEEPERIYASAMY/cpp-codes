#include <iostream>
using namespace std;

void dsf(vector<vector<int>> &index,unordered_set<int> &visited,int i){
    if(visited.count(i)) return;
    visited.insert(i);
    for (auto j : index[i]){ 
        if(visited.count(j)) continue;
        dsf(index,visited,j);
    }
}

int removeStones(vector<vector<int>> &stones){
    const int k = 10000;
    vector<vector<int>> index(2*k);
    for (auto &stone : stones) index[stone[0]].push_back(stone[1]+k),index[stone[1]+k].push_back(stone[0]);
    unordered_set<int> visited;
    int islands = 0;
    for (auto &stone : stones) {
        if(visited.count(stone[0])) continue;
        islands++;
        dsf(index,visited,stone[0]);
        dsf(index,visited,stone[1]+k);
    }
    return stones.size()-islands;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
	return 0;
}

