#include <bits/stdc++.h>
using namespace std;

void computeLps(string str,vector<int> &lps){
    int len = 0;
    int i;
    lps[0] = 0;
    i = 1;
    int m = lps.size();
    while(i<m){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool isRepeat(string str){
    int n = str.size();
    vector<int> lps(n,0);
    computeLps(str,lps);
    int len = lps[n-1];
    return len>0 && n%(n-len) == 0;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/
	vector<string> txt = {"ABCABC", "ABABAB", "ABCDABCD", "GEEKSFORGEEKS",
                      "GEEKGEEK", "AAAACAAAAC", "ABCDABC"};
    for (auto i : txt) isRepeat(i)?cout<<"True\n":cout<<"False\n";
	return 0;
}

