using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if(intervals.empty()) return res;
    sort(intervals.begin(),intervals.end());
    for (auto &i : intervals) {
        if(res.empty()||res.back()[1]<i[0]) res.push_back(i);
        else res.back()[1] = max(res.back()[1],i[1]);
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/merge-intervals/
    return 0;
}

