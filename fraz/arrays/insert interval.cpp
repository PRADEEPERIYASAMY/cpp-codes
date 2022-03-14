#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    bool insertNew = false;
    for (auto &i : intervals) {
        if(insertNew || i[1]<newInterval[0]) res.push_back(i);
        else if(i[0]>newInterval[1]){
            if(!insertNew){
                res.push_back(newInterval);
                insertNew = true;
            }
            res.push_back(i);
        }else{
            newInterval[0] = min(newInterval[0],i[0]);
            newInterval[1] = max(newInterval[1],i[1]);
        }
    }
    if(!insertNew) res.push_back(newInterval);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/insert-interval/
    return 0;
}
