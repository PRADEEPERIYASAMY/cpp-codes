#include <iostream>
using namespace std;

// use dp wordbreak
// bool helper(string word,unordered_set<string> &dict){
//     if(dict.empty()) return false;
//     int n = word.size();
//     vector<bool> dp(n+1,false);
//     dp[0] = true;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j < i; j++) {
//             if(dp[j] && dict.count(word.substr(j,i-j))){
//                 dp[i] = true;
//                 break;
//             }
//         }
//     }
//     return dp[n];
// }

// vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//     unordered_set<string> dict;
//     vector<string> res;
//     sort(words.begin(),words.end(),[](string &w1,string &w2){return w1.size()<w2.size();});
//     for (auto &word : words) {
//         if(helper(word,dict)) res.push_back(word);
//         dict.insert(word);
//     }
//     return res;
// }

// DFS
bool helper(string &word,unordered_set<string> &dict,int pos,int cnt){
    if(pos>= word.size() &&cnt >= 2) return true;
    for (int len = 1; len <= word.size()- pos; len++) {
        string t = word.substr(pos,len);
        if(dict.count(t) && helper(word,dict,pos+len,cnt+1)) return true;
    }
    return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string> &words){
    vector<string> res;
    unordered_set<string> dict(words.begin(),words.end());
    for (auto &word : words) {
        if(word.empty()) continue;
        if(helper(word,dict,0,0)) res.push_back(word);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/concatenated-words/
	return 0;
}

