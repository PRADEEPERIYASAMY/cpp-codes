#include <bits/stdc++.h>
using namespace std;

void computeLps(string pat,vector<int> &lps){
    int len = 0;
    int m = pat.size();
    int i = 1;
    lps[0] = 0;
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0) len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(string pat,string txt){
    int m = pat.size();
    int n = txt.size();
    vector<int> lps(m,0);
    computeLps(pat,lps);
    int i,j;
    i = j = 0;
    while(i<n){
        if(pat[j] == txt[i]) j++,i++;
        if(j == m){
            cout<<"Found pattern at index "<<i-j<<"\n";
            j = lps[j-1];
        }else if(i<n && pat[j] != txt[i]){
            if(j!=0) j = lps[j-1];
            else i = i+1;
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
	string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    kmpSearch(pat, txt);
	return 0;
}


