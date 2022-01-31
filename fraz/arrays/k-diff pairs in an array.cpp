#include <iostream>
using namespace std;

int findPairs(vector<int> &nums,int k){
    if(k<0) return 0;
    unordered_map<int,int> m;
    for (auto &i : nums) m[i]++;
    int cnt = 0;
    for (auto &i : m) if((!k && i.second >1) || (k && m.find(i.first+k) != m.end())) cnt++; // corner cases
    return cnt;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/k-diff-pairs-in-an-array/
	return 0;
}

