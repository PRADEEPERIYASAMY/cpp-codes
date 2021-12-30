#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

string concatenetedString(string &str1,string str2){
    int m = str1.length();
    int n = str2.length();
    int temp[CHAIR];
    memset(temp,-1,sizeof(temp));
    string res = "";
    for (int i = 0; i < n; i++){
        if(temp[str2[i]] == -1) temp[str2[i]] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        if(temp[str1[i]] == 0) temp[str1[i]] = 2;
        else res+=str1[i];
    }
    
    for (int i = 0; i < n; i++) {
        if(temp[str2[i]] == 0) res+=str2[i];
    }
    
    return res;
}

int main() { 
    string s1 = "abcs";
    string s2 = "cxzca";
    cout << concatenetedString(s1, s2);
    return 0;
} 

