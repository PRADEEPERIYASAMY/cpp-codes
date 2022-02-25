#include <bits/stdc++.h>
using namespace std;

int countSubsequences(string s){
    int aCount,bCount,cCount;
    aCount = bCount = cCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') aCount = 1+2*aCount;
        if(s[i] == 'b') bCount = aCount+2*bCount;
        if(s[i] == 'c') cCount = bCount+2*cCount;
    }
    return cCount;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/
	string s = "abbc";
    cout << countSubsequences(s) << endl;
    return 0;
}

