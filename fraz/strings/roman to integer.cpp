using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int romanToInt(string s) {
    unordered_map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0,n = s.size();
    for (int i = 0; i < n; i++) {
        if(i != n-1 && mp[s[i]]<mp[s[i+1]]) res-=mp[s[i]];
        else res+=mp[s[i]];
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/roman-to-integer/
    return 0;
}

