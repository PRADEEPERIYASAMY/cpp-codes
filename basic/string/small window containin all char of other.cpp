#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

string findSubString(string str,string pat){
    int m = str.length();
    int n = pat.length();
    if(m<n) return "no possiblity";
    int hstr[CHAIR] = {0}, hptr[CHAIR] = {0};
    for (int i = 0; i < n; i++) hptr[pat[i]]++;
    
    int start = 0,start_i = -1,mi = INT_MAX;
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        hstr[str[i]]++;
        if(hstr[str[i]]<= hptr[str[i]]) count++;
        if(count == n){
            while(hstr[str[start]]> hptr[str[start]] || hptr[str[start]] == 0){
                if(hstr[str[start]]> hptr[str[start]]) hstr[str[start]]--;
                start++;
            }
            int len = i-start+1;
            if(len<mi){
                mi = len;
                start_i = start;
            }
        }
    }
    
    if(start_i == -1) return "no possiblity";
    return str.substr(start_i,mi);
}

int main() { 
    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest window is : "<< findSubString(str, pat);
    return 0;
} 

