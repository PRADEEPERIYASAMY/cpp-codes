#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

const int CHAR = 256;
bool areAnagram(string str1,string str2){
    int m = str1.length(),n = str2.length();
    int hash[CHAR] = {0};
    for (int i = 0; i < m; i++) hash[str1[i]]++;
    for (int i = 0; i < n; i++) hash[str2[i]]--;
    
    for (int i = 0; i < CHAR; i++) if(hash[i] != 0) return false;
    return true;
}

int main() {
	string str1 = "abaac"; 
    string str2 = "aacba"; 
    if (areAnagram(str1, str2)) cout << "The two strings are anagram of each other"; 
    else cout << "The two strings are not anagram of each other"; 
    return 0; 
}

