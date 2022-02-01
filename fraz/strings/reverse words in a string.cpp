#include <iostream>
using namespace std;

//using extra space 
// string reverseWords(string s) {
//     string res;
//     int n = s.size();
//     for (int i = 0; i < n; i++) {
//         if(s[i] == ' ') continue;
//         int start = i;
//         while(i<n && s[i] != ' ') i++;
//         if(!res.empty()) res = ' '+res;
//         res = s.substr(start,i- start) + res;
//     }
//     return res;
// }

// inplace
string reverseWords(string s){
    reverse(s.begin(),s.end());
    int n = s.size(),idx = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == ' ') continue;
        if(idx>0) s[idx++] = ' ';
        int j = i;
        while(j<n && s[j] != ' ') s[idx++] = s[j++];
        reverse(s.begin()+idx-(j-i),s.begin()+idx);
        i = j;
    }
    s.resize(idx);
    return s;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reverse-words-in-a-string/
	return 0;
}

