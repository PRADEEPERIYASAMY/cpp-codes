#include <iostream>
using namespace std;

// Dynamic Programming + Backtracking
// void backtracking(int pos,vector<vector<string>> &dp,vector<string> &tmp,vector<string> &res){
//     if(pos == dp.size() -1){
//         ostringstream ss;
//         for (int i = 0; i < tmp.size()-1; i++) ss<<tmp[i]<<" "
//         ss<<tmp.back();
//         res.push_back(ss.str());
//         return ;
//     }
//     for (auto &word : dp[pos]) {
//         tmp.push_back(word);
//         backtracking(pos+word.size(),dp,tmp,res);
//         tmp.pop_back();
//     }
// }

// vector<string> wordBreak(string s, vector<string>& wordDict) {
//     vector<vector<string>> dp(s.size()+1);
//     dp.back().push_back("");
//     for (int pos = s.size()-1; pos>= 0; pos--) {
//         for (int i = 0; i < wordDict.size(); i++) {
//             bool match = true;
//             for (int j = 0; j < wordDict[i].size(); j++) {
//                 if(pos+j >= s.size() || wordDict[i][j] != s[pos+j]){
//                     match = false;
//                     break;
//                 }
//             }
//             if(match)if(!dp[pos+wordDict[i].size()].empty()) dp[pos].push_back(wordDict[i]);
//         }
//     }
//     vector<string> res;
//     vector<string> tmp;
//     backtracking(0,dp,tmp,res);
//     return res;
// }

// dfs with hashmap
vector<string> helper(const string &s,vector<string> &wordDict,unordered_map<string,vector<string>> &memo){
    if(memo.count(s)) return memo[s];
    if(s.empty()) return {""};
    vector<string> res;
    for (auto &word : wordDict) {
        if(s.substr(0,word.size()) != word) continue;
        vector<string> next = helper(s.substr(word.size()),wordDict,memo);
        for (auto &str : next) res.emplace_back(word+(str.empty()?"":" ")+str);
    }
    return memo[s] = res;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,vector<string>> memo;
    return helper(s,wordDict,memo);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/word-break-ii/
	return 0;
}

