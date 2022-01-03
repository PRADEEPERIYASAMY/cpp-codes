#include <bits/stdc++.h> 
using namespace std; 

void generatePrintBinary(int n){
    queue<string> q;
    q.push("1");
    while(n--){
        string s = q.front();
        q.pop();
        cout<<s<<" ";
        q.push(s+"0");
        q.push(s+"1");
    }
}

int main() {
int n = 10;
    generatePrintBinary(n);
    return 0;
}

