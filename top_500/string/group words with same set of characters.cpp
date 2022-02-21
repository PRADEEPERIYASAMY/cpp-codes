#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

string getKey(string &str){
    bool visited[MAX_CHAR] = {false};
    for (int i = 0; i < str.size(); i++) visited[str[i] - 'a'] = true;
    string key = "";
    for (int i = 0; i < MAX_CHAR; i++) if(visited[i]) key+=(char)('a'+i);
    return key;
}

void wordsWithSameCharSet(string words[],int n){
    unordered_map<string,vector<int>> mp;
    for (int i = 0; i < n; i++) {
        string key = getKey(words[i]);
        mp[key].push_back(i);
    }
    for (auto i : mp) {
        for (auto w : i.second) cout<<words[w]<<" ";
        cout<<"\n";
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-words-together-set-characters/
	string words[] = { "may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act", "tab",
                 "bat", "flow", "wolf", "lambs", "amy", "yam",
                 "balms", "looped", "poodle"};
    int n = sizeof(words)/sizeof(words[0]);
    wordsWithSameCharSet(words, n);
    return 0;
}

