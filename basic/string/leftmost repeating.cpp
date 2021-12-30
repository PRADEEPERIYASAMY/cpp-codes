#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

const int CHAR = 256;
bool leftMost(string str1){
    bool hash[CHAR];
    fill(hash,hash+CHAR,false);
    int res = -1;
    for (int i = str1.length()-1; i >= 0; i--) {
        if(hash[str1[i]]) res = i;
        else hash[str1[i]] = true;
    }
    return res;
}

int main() {
	string str = "geeksforgeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<leftMost(str)<<endl;
    return 0;
}

