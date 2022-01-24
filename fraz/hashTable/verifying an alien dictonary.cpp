using namespace std;
#include <bits/stdc++.h>

bool isAlienSorted(vector<string>& words, string order) {
    vector<int> mp(256,0);
    for (int i = 0; i < order.size(); i++) mp[order[i]] = i;
    for (int i = 0; i < words.size()-1; i++) {
        int cur = words[i].size();
        int next = words[i+1].size();
        int len = min(cur,next);
        int j = 0;
        for (j = 0; j < len; j++) if(words[i][j] != words[i+1][j]) break;
        if(j == len && cur>next) return false;
        if(mp[words[i][j]]>mp[words[i+1][j]]) return false;
    }
    return true;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/verifying-an-alien-dictionary/
    return 0;
}

