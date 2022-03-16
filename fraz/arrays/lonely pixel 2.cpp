#include <bits/stdc++.h>
using namespace std;

int findBlackPixel(vector<vector<char>>& picture, int N) {
    if(picture.empty() || picture[0].empty()) return 0;
    int m = picture.size(),n = picture[0].size();
    vector<int> col(n,0);
    unordered_map<string,int> mp;
    for (int i = 0; i < m; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if(picture[i][j] == 'B') col[j]++,cur++;
        }
        if(cur == N) mp[string(picture[i].begin(),picture[i].end())]++;
    }
    int res = 0;
    for (auto &a : mp) {
        if(a.second != N) continue;
        for (int j = 0; j < n; j++) {
            if(a.first[j] == 'B' && col[j] == N) res+=N;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/lonely-pixel-ii/
    return 0;
}
