#include <iostream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> mp;
    for (auto &i : strs) {
        string word = i;
        sort(word.begin(),word.end());
        mp[word].push_back(i);
    }
    vector<vector<string>> res;
    for(auto it = mp.begin();it != mp.end();it++) res.push_back(it->second);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/group-anagrams/
	return 0;
}

