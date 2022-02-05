#include <iostream>
using namespace std;

int minDeletions(string s) {
    vector<int> cache(26);
    for (auto &i : s) cache[i-'a']++;
    sort(cache.begin(),cache.end(),greater<int>());
    int res = 0;
    for (int i = 1; i < cache.size(); i++) {
        if(cache[i-1]<=1){
            res+=cache[i];
            cache[i] = 0;
        }else if(cache[i-1]<=cache[i]){
            res+=cache[i]-cache[i-1]+1;
            cache[i] = cache[i-1]-1;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/1573356/C%2B%2B-straightforward-O(n)-solution-with-explanation
	return 0;
}

