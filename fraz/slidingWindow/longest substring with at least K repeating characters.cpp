#include <iostream>
using namespace std;

int longestSubstring(string s, int k) {
    int begin = 0,d = 0,n = s.size();
    while(begin+k <= n){
        vector<int> count(26,0);
        int mask = 0,maxLast = begin;
        for (int  end = begin; end < n; end++) {
            int idx = s[end] - 'a';
            count[idx]++;
            if(count[idx]<k) mask |= (1<<idx);
            else mask &= (~(1<<idx));
            if(mask == 0){
                d = max(d,end - begin+1);
                maxLast = end;
            }
        }
        begin = maxLast+1;
    }
    return d;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
	return 0;
}

