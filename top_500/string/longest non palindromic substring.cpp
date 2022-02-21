#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string str){
    int n = str.size();
    for (int i = 0; i < n/2; i++) {
        if(str[i] != str[n-i-1]) return false;
    }
    return true;
}

int maxLengthNonPalinSubstring(string str){
    int n =  str.size();
    char ch = str[0];
    int i = 1;
    for (i = 1; i <n; i++) if(str[i]!=ch) break;
    if(i == n) return 0;
    if(ispalindrome(str)) return n-1;
    return n;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/lexicographically-first-palindromic-string/
	string str = "abba";
    cout << "Maximum length = "<< maxLengthNonPalinSubstring(str);
    return 0;
}

