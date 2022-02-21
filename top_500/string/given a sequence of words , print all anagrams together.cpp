#include <bits/stdc++.h>
using namespace std;

void printAnagramsTogether(string arr[],int size){
    unordered_map<string,vector<string>> map;
    for (int i = 0; i < size; i++) {
        string word = arr[i];
        string letter = word;
        sort(letter.begin(),letter.end());
        if(map.find(letter) != map.end()) map[letter].push_back(word);
        else map[letter] = vector<string>({word});
    }
    for (auto &i : map) {
        if(i.second.size()>1){
            for (int j = 0; j < i.second.size(); j++) cout<<i.second[j]<<" ";
            cout<<"\n";
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
	string wordArr[] = { "cat", "dog", "tac", "god", "act" };
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}

