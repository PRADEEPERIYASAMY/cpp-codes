#include <bits/stdc++.h>
using namespace std;

bool patternMatchUtil(string str,int n,int i,string pat,int m,int j,unordered_map<char,string> &map){
    if(i == n && j == m) return true;
    if(i == n || j == m) return false;
    char ch = pat[j];
    if(map.find(ch)!= map.end()){
        string s = map[ch];
        int len = s.size();
        string substr = str.substr(i,len);
        if(substr.compare(s)) return false;
        return patternMatchUtil(str,n,i+len,pat,m,j+1,map);
    }
    for (int len = 1; len <= n-i; len++) {
        map[ch] = str.substr(i,len);
        if(patternMatchUtil(str,n,i+len,pat,m,j+1,map)) return true;
        map.erase(ch);
    }
    return false;
}

bool patternMatch(string str,string pat,int n,int m){
    if(n<m) return false;
    unordered_map<char,string> map;
    bool res = patternMatchUtil(str,n,0,pat,m,0,map);
    for (auto i : map){
        cout<<i.first<<"->"<<i.second<<"\n";
    }
    return res;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/match-a-pattern-and-string-without-using-regular-expressions/
	string str = "GeeksforGeeks", pat = "GfG";
    int n = str.size(), m = pat.size();
    if (!patternMatch(str, pat, n, m)) cout << "No Solution exists";
	return 0;
}

