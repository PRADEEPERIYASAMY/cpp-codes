#include <bits/stdc++.h>
using namespace std;

// bool isSubsequence(string str1,string str2){
//     int m = str1.size(),n = str2.size();
//     int j = 0;
//     for (int i = 0; i < n && j<m; i++) if(str1[j] == str2[i]) j++;
//     return j == m;
// }

// string findLongestString(vector<string> dict,string str){
//     string result = "";
//     int len = 0;
//     for (auto &word : dict) {
//         if(len < word.size() && isSubsequence(word,str)){
//             result = word;
//             len = word.size();
//         }
//     }
//     return result;
// }

string res = "";
void check(string d,string s){
    int i = 0,j = 0;
    while(i<d.size() && j<s.size()){
        if(d[i] == s[j]) i++,j++;
        else j++;
    }
    if(i == d.size() && res.size()<d.size()) res = d;
}

string findLongestString(vector<string> d,string s){
    sort(d.begin(),d.end());
    for (auto &i : d) check(i,s);
    return res;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-largest-word-dictionary-deleting-characters-given-string/
	vector<string> dict = { "ale", "apple", "monkey", "plea" };
    string str = "abpcplea";
    cout << findLongestString(dict, str) << endl;
    return 0;
}

