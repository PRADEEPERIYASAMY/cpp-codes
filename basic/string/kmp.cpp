#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define d 256
const int q=101;

// proper prefix abc = "",a,ab
// sufix = "",c,bc,abc
// lps = proper prefix which is also a suffix
void fillLPS(string str,int lps[]){
    int n = str.length(),len = 0;
    lps[0] = 0;
    int i =1;
    while(i<n){
        if(str[i] == str[len]){ // case 2
            lps[i] = len+1;
            len++;i++;
        }else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }else len = lps[len -1]; // case 1
        }
    }
}

void KMP(string pat,string txt){
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    fillLPS(pat,lps);
    int i =0,j = 0;
    while(i<n){
        if(pat[j] == txt[i]){
            j++;i++;
        }
        if(j == m){
            cout<<i-j<<" ";
            j = lps[j-1];
        }
        else if(i< n && pat[j] != txt[i]){
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }
}

int main() 
{ 
    string txt = "ababcababaad",pat="ababa";
    KMP(pat,txt);
    return 0; 
} 

