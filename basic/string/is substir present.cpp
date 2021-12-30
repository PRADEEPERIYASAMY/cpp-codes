#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int Substr(string s2, string s1){
    int c = 0;
    int i = 0;
    for (; i < s1.length(); i++) {
        if(c == s2.length()) break;
        if(s2[c] == s1[i]) c++;
        else{
            if(c>0) i-=c;
            c = 0;
        }
    }
    return c<s2.length()?-1:i-c;
}

int main() { 
    string s1 = "geeksfffffoorrfoorforgeeks";
    cout << Substr("for", s1);
    return 0;
} 

