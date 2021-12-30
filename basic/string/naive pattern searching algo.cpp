#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// naive patter searching algo O((m+n-1)*m)
void patSearchinng(string &txt,string &pat){
    int m = txt.length();
    int n = pat.length();
    for (int i = 0; i <= (m-n); i++) {
        int j;
        for (j = 0; j < n; j++) {
            if(txt[i+j] != pat[j]) break;
        }
        if(j == n) cout<<i<<" ";
    }
}

int main() {
	string txt = "ABCABCD";string pat="ABCD";
    cout<<"All index numbers where pattern found:"<<" ";
    patSearchinng(txt,pat);
    return 0; 
}

