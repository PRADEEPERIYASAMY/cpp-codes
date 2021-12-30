#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

bool palindromeCheck(string s){
    int l = 0,r = s.length()-1;
    while(l<r){
        if(s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}

int main() {
	string s = "ssabass";
	printf("%s",palindromeCheck(s)?"yes":"no");
	return 0;
}

