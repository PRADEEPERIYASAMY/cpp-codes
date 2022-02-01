#include <iostream>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(),wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0] = true;
    for (int i = 1; i <=n; i++) {
        for (int j = 0; j < i; j++) {
            if(dp[j] && words.find(s.substr(j,i-j))!= words.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/word-break/
	return 0;
}

