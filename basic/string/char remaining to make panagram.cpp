#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

void panagram(string a){
    int temp[26] = {0};
    for (auto i : a) temp[i-'a'] = 1;
    for (int i = 0; i < 26; i++) {
        char t = 'a';
        if(temp[i] != 1){
            t = 'a'+i;
            cout<<t;
        }
    }
}

int main() { 
    panagram("abc");
    return 0;
} 

