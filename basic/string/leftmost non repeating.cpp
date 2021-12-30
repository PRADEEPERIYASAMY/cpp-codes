#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

const int CHAR = 256;
int nonRep(string &str1){
    int hash[CHAR];
    // int hash[CHAR] = {-1}; wont fill when -1 it will ONLY FILL FIRST element as -1
    fill(hash,hash+CHAR,-1);
    for (int i = 0; i < str1.length(); i++){
        if(hash[str1[i]] == -1) hash[str1[i]] = i;
        else hash[str1[i]] = -2;
    }
    int res = INT_MAX;
    for (int i = 0; i < CHAR; i++) {
        if(hash[i] >= 0) res = min(res,hash[i]);
    }
    return (res == INT_MAX)?-1:res;
}

int main() {
	string str = "geeksforgeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<nonRep(str)<<endl;
    return 0;
}

