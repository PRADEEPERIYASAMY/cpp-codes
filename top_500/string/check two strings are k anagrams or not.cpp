#include <bits/stdc++.h>
using namespace std;
#define MAX 26

bool areKAnagrams(string str1,string str2,int k){
    int n = str1.size();
    if(str2.size() != n) return false;
    vector<int> hash(MAX,0);
    for (int i = 0; i < n; i++) hash[str1[i] - 'a']++;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(hash[str2[i] - 'a']>0) hash[str2[i] - 'a']--;
        else count++;
        if(count>k) return false;
    }
    return true;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/check-two-strings-k-anagrams-not/
	string str1 = "fodr";
    string str2 = "gork";
    int k = 2;
    if (areKAnagrams(str1, str2, k)) cout << "Yes";
    else cout << "No";
    return 0;
}

