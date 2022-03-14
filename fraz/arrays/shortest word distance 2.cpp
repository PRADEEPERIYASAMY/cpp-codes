#include <bits/stdc++.h>
using namespace std;

class WordDistance {
    unordered_map<string,vector<int>> mp;
    public:
    WordDistance(vector<string> &words){
        for (int i = 0; i < words.size(); i++) mp[words[i]].push_back(i);
    }
    int shortes(string word1,string word2){
        int res = INT_MAX,i = 0,j = 0;
        while(i<mp[word1].size() && j<mp[word2].size()){
            res = min(res,abs(mp[word1][i] - mp[word2][j]));
            mp[word1][i]<mp[word2][j]?i++:j++;
        }
        return res;
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/shortest-word-distance-ii/
    return 0;
}
