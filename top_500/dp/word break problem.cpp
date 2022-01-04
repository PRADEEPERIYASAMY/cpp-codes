#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

int dictionaryContains(string word){
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++) if(dictionary[i].compare(word) == 0) return true;
    return false;
}

// recursive
// bool wordBreak(string str){
//     int n = str.length();
//     if(n == 0) return true;
//     for (int i = 1; i <=n; i++) {
//         if(dictionaryContains(str.substr(0,i)) && wordBreak(str.substr(i,n-1))) return true;
//     }
//     return false;
// }
// dp 
bool wordBreak(string str){
    int n = str.size();
    if(n == 0) return true;
    bool dp[n+1]={false};
    for (int i = 1; i <= n; i++) {
        if(!dp[i] && dictionaryContains(str.substr(0,i))) dp[i] = true;
        if(dp[i]){
            if( i==n) return true;
            for (int j = i+1; j <= n; j++) {
                if(!dp[j] && dictionaryContains(str.substr(i,j-i))) dp[j] = true;
                if(j == n && dp[j]) return true;
            }
        }
    }
}

int main() {
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}

