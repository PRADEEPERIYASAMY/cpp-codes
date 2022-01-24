using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

string convertToTitle(int n) {
    string res;
    while(n){
        res=char('A'+(n-1)%26)+res;
        n=(n-1)/26;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/excel-sheet-column-title/
    return 0;
}

