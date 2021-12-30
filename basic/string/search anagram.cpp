#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

bool areSame(int cp[],int ct[]){
    for (int i = 0; i < CHAIR; i++) if(cp[i] != ct[i]) return false;
    return true;
}

bool isPresent(string &txt,string &pat){
    int ct[CHAIR] = {0}, pt[CHAIR] = {0};
    for (int i = 0; i < pat.length(); i++) {
        ct[txt[i]]++;
        pt[pat[i]]++;
    }
    for (int i = pat.length(); i < txt.length(); i++) {
        if(areSame(ct,pt)) return true;
        ct[txt[i]]++;
        ct[txt[i-pat.length()]]--;
    }
    return false;
}

int main() 
{ 
    string txt = "geeksforgeeks"; 
    string pat = "frog"; 
    if (isPresent(txt,pat)) cout << "Anagram search found"; 
    else cout << "Anagram search not found"; 
    return 0; 
} 

