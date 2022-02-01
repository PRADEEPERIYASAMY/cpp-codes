#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    if(s.empty()) return "";
    int n = s.size(),i = 0;
    vector<string> tmp(numRows,"");
    while(i<n){
        for (int j = 0; j < numRows && i<n; j++) tmp[j].push_back(s[i++]);
        for (int j = numRows-2;j>=1 && i<n;j--) tmp[j].push_back(s[i++]);
    }
    string res;
    for (auto &i : tmp) res+=i;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/zigzag-conversion/
	return 0;
}

