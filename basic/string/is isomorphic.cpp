#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

bool areIsomorphic(string str1,string str2){
    int m = str1.length(),n = str2.length();
    if(m != n) return false;
    int temp[CHAIR];
    memset(temp,-1,sizeof(temp));
    bool mask[CHAIR] = {false};
    for (int i = 0; i < str1.length(); i++) {
        if(temp[str1[i]] == -1){
            if(mask[str2[i]]) return false;
            mask[str2[i]] = true;
            temp[str1[i]] = str2[i];
        }
        else if(temp[str1[i]] != str2[i]) return false;
    }
    return true;
}

int main() { 
    cout << areIsomorphic("aab", "xxy") << endl;
    cout << areIsomorphic("aab", "xyz") << endl;
    return 0;
} 

