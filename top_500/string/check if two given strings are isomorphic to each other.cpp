#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string str1,string str2){
    int m =  str1.size(),n = str2.size();
    if(m != n) return false;
    vector<bool> marked(MAX_CHARS,false);
    vector<int> map(MAX_CHARS,-1);
    for (int i = 0; i < n; i++) {
        if(map[str1[i]] == -1){
            if(marked[str2[i]]) return false;
            marked[str2[i]] = true;
            map[str1[i]] = str2[i];
        }else if(map[str1[i]] != str2[i]) return false;
    }
    return true;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/check-if-two-given-strings-are-isomorphic-to-each-other/
	cout << areIsomorphic("aab", "xxy") << endl;
    cout << areIsomorphic("aab", "xyz") << endl;
	return 0;
}

