#include <bits/stdc++.h>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length,0);
    for (auto &update : updates) {
        int startidx = update[0],endidx = update[1],val = update[2];
        res[startidx]+=val;
        if(endidx<length-1) res[endidx+1]-=val;
    }
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum+=res[i];
        res[i] = sum;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/range-addition/
    return 0;
}
