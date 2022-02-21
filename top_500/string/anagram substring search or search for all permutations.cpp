#include <bits/stdc++.h>
using namespace std;
#define MAX 256

bool compare(string arr1,string arr2){
    for (int i = 0; i < MAX; i++) {
        if(arr1[i] != arr2[i]) return false;
    }
    return true;
}

void search(string pat,string txt){
    int m = pat.size(), n = txt.size();
    string countp = string(MAX,'0'),countt = string(MAX,'0');
    for (int i = 0; i < m; i++) {
        countp[pat[i]]++;
        countt[txt[i]]++;
    }
    for (int i = m; i <n; i++) {
        if(compare(countp,countt)) cout<<"found at index "<<(i-m)<<"\n";
        countt[txt[i]]++;
        countt[txt[i-m]]--;
    }
    if(compare(countp,countt)) cout<<"found at index "<<(n - m)<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/
	string txt = "BACDGABCDA";
    string pat = "ABCD";
    search(pat, txt);
    return 0;
}

