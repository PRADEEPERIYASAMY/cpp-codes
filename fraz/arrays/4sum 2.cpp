#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) { 
    int res = 0;
    unordered_map<int,int> mp;
    for (auto a : A) {
        for (auto b : B) {
            mp[a+b]++;
        }
    }
    for (auto c : C) {
        for (auto d : D) {
            int target = -1*(c+d);
            res+=mp[target];
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/4sum-ii/
    return 0;
}
