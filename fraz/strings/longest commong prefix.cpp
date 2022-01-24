using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

string longestCommonPrefix(vector<string>& strs){
    string res;
    if(strs.empty()) return "";
    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 1; j < strs.size(); j++) if(strs[0][i] != strs[j][i]) return res;
        res+=strs[0][i];
    }
    return strs[0];
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/longest-common-prefix/
    return 0;
}

