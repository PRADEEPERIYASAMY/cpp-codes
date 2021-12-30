#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int printMinIndexChar(string str,string patt){
    bool temp[CHAIR];
    memset(temp,false,sizeof(temp));
    for (auto i : patt) temp[i] = true;
    for (int i = 0; i < str.length(); i++) {
        if(temp[str[i]]) return i;
    }
    return -1;
}

int main() { 
    string str = "geeksforgeeks";
    string patt = "set";
    cout<<printMinIndexChar(str, patt);
    return 0;
} 

