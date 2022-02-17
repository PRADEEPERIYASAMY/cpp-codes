#include <iostream>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(),wordList.end());
    vector<vector<string>> res;
    queue<vector<string>> paths({{beginWord}});
    unordered_set<string> visited;
    int level = 1,minLevel = INT_MAX;
    while(!paths.empty()){
        for (int k = paths.size() - 1; k>= 0; k--) {
            vector<string> path = paths.front();paths.pop();
            string lastWord = path.back();
            for (int i = 0; i < lastWord.size(); i++) {
                string newWord = lastWord;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    newWord[i] = ch;
                    if(words.count(newWord)){
                        vector<string> newPath = path;
                        newPath.push_back(newWord);
                        visited.insert(newWord);
                        if(newWord == endWord){
                            minLevel = level;
                            res.push_back(newPath);
                        }else{
                            paths.push(newPath);
                        }
                    }
                }
            }
        }
        if(++level>minLevel) break;
        else{
            for (auto &str : visited) words.erase(str);
            visited.clear();
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/word-ladder-ii/
	return 0;
}

