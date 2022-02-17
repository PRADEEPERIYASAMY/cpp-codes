#include <iostream>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(),wordList.end());
    queue<string> q({beginWord});
    int res = 1;
    while(!q.empty()){
        for (int k = q.size()-1; k >= 0; k--) {
            string word = q.front();q.pop();
            if(word == endWord) return res;
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (char ch= 'a'; ch <= 'z'; ch++) {
                    newWord[i] = ch;
                    if(words.count(newWord) && newWord != word){
                        q.push(newWord);
                        words.erase(newWord);
                    }
                }
            }
        }
        res++;
    }
    return 0;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/word-ladder/
	return 0;
}

