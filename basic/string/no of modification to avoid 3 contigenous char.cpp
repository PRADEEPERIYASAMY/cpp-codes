#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int modified(string a){
    int cur = 1, m = 0;
    for (int i = 1; i < a.length(); i++) {
        if(a[i] == a[i-1]) cur++;
        if(a[i] != a[i-1]) cur = 1;
        if(cur == 3){
            m++;
            cur = 1;
        }
    }
    return m;
}

int main() { 
    cout<<modified("aaaaa");
    return 0;
} 

