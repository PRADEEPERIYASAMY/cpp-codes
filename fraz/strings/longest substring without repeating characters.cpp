#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> record(128,-1);
    int start = -1,res = 0;
    for (int end = 0; end < s.size(); end++) {
        start = max(start,record[s[end]]);
        record[s[end]] = end;
        res = max(res,end-start);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-substring-without-repeating-characters/
	return 0;
}

