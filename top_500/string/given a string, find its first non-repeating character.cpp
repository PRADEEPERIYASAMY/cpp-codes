#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// void getCharCountArray(string str,vector<int> &count){
//     for (int i = 0; i < str.size(); i++) count[str[i]]++;
// }

// int firstNonRepeating(string str){
//     vector<int> count(NO_OF_CHARS,0);
//     getCharCountArray(str,count);
//     int index = -1,i;
//     for (int i = 0; i < str.size(); i++) {
//         if(count[str[i]] == 1){
//             index = i;
//             break;
//         }
//     }
//     return index;
// }

int firstNonRepeating(string str){
    vector<int> count(NO_OF_CHARS,-1);
    for (int i = 0; i < str.size(); i++) {
        if(count[str[i]] == -1) count[str[i]] = i;
        else count[str[i]] = -2;
    }
    int res = INT_MAX;
    for (int i = 0; i < NO_OF_CHARS; i++) {
        if(count[i]>=0) res = min(res,count[i]);
    }
    if(res == INT_MAX) return -1;
    else return res;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/
	string str = "geeksforgeeks";
	int index = firstNonRepeating(str);
	if(index == -1) cout<<"Either all characters are repeating or stirng is empty";
	else cout<<"First non-repeating character is "<<str[index];
    return 0;
}

