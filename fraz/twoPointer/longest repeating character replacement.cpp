#include <iostream>
using namespace std;

// Sliding window
int characterReplacement(string s, int k) { 
    int start = 0,end = 0,maxCount = 0,d = 0;
    vector<int> count(128,0);
    while(end<s.size()){
        maxCount = max(maxCount,++count[s[end++]]);
        while(end - start - maxCount >k) --count[s[start++]];
        d = max(d,end - start);
    }
    return d;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-repeating-character-replacement/
	return 0;
}

