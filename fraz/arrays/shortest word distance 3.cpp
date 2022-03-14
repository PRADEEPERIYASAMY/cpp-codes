#include <bits/stdc++.h>
using namespace std;

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int idx1 = words.size(),idx2 = -words.size(),res = INT_MAX;
    for (int i = 0; i < words.size(); i++) {
        if(words[i] == word1) idx1 = word1 == word2?idx2:i;
        if(words[i] == word2) idx2 = i;
        res = min(res,abs(idx1 - idx2));
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/shortest-word-distance-iii/
    return 0;
}
