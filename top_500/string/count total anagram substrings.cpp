#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

int toNum(char c){
    return (c - 'a');
}

int countOfAnagramSubstring(string str){
    int n = str.size();
    map<vector<int>,int> mp;
    for (int i = 0; i < n; i++) {
        vector<int> freq(MAX_CHAR,0);
        for (int j = i; j < n; j++) {
            freq[toNum(str[j])]++;
            mp[freq]++;
        }
    }
    int result = 0;
    for (auto &i : mp) {
        int freq = i.second;
        result +=(freq * (freq - 1))/2;
    }
    return result;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-total-anagram-substrings/
    string str = "xyyx";
    cout << countOfAnagramSubstring(str) << endl;
    return 0;
}

