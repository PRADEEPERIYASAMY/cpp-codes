#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256

bool isPalindrome(string str,int l,int h){
    while(h>l)if(str[l++] != str[h--]) return false;
    return true;
}

int check(string str){
    int n = str.size();
    vector<int> freq(MAX_CHAR,0);
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
        if(freq[str[i]]>2) return true;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if(freq[str[i]] >1) str[k++] = str[i];
    }
    str[k] = '\n';
    if(isPalindrome(str,0,k-1)){
        if(k&1) return str[k/2] == str[k/2-1];
        return false;
    }
    return true;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/longest-repeating-subsequence/
	string str = "ABCABD";
    if (check(str)) cout << "Repeated Subsequence Exists";
    else cout << "Repeated Subsequence Doesn't Exists";
	return 0;
}

