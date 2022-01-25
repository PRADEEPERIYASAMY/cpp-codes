using namespace std;
#include <bits/stdc++.h>

bool backspaceCompare(string s, string t) {
    int k,p;k = p =0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='#'){
            k--;
            k = max(0,k);
        }else s[k++] = s[i];
    }
    for (int i = 0; i < t.size(); i++) {
        if(t[i]=='#'){
            p--;
            p = max(p,0);
        }else t[p++] = t[i];
    }
    if(k!=p) return false;
    else for (int i = 0; i < k; i++) if(s[i]!=t[i]) return false;
    return true;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/backspace-string-compare/discuss/570511/C%2B%2B-Simple-And-Easy-Explanation-%3A-100-Memory-And-100-speed-0ms-O(1)-space-and-O(N)-Time
    return 0;
}

