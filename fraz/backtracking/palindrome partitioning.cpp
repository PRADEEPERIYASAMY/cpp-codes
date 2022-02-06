#include <iostream>
using namespace std;

bool isPalindrome(const string &s,int start,int end){
    while(start<=end) if(s[start++] != s[end--]) return false;
    return true;
}

void dfs(int index,string &s,vector<string>& path,vector<vector<string>> &res){
    if(index == s.size()){
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); i++) {
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i - index+1));
            dfs(i+1,s,path,res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    if(s.empty()) return res;
    vector<string> path;
    dfs(0,s,path,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/palindrome-partitioning/discuss/41964/Clean-C%2B%2B-backtracking-solution
	return 0;
}

