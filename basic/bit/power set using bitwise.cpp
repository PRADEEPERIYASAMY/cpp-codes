#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

void printPowerSet(string str){
    int n = str.length();
    int powSize = pow(2,n);
    for (int i = 0; i < powSize; i++) {
        for (int j = 0; j < n; j++) if((i&(1<<j)) != 0) cout<<str[j];
        cout<<endl;
    }
}

int main() {
	string s = "abc";
    printPowerSet(s);  
}

