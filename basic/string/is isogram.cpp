#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

bool is_isogram(string &str1){
    int n = str1.length();
    for (int i = 0; i < n; i++) str1[i] = tolower(str1[i]);
    int temp[CHAIR];
    memset(temp,0,sizeof(temp));
    for (int i = 0; i < n; i++) temp[str1[i]]++;
    int c =0;
    for (int i = 0; i < CHAIR; i++) {
        if(temp[i] == 1) c++;
    }
    
    return c == n;
}

int main() { 
    string str1 = "Machine";
    cout << is_isogram(str1) << endl;
    string str2 = "isogram";
    cout << is_isogram(str2) << endl;
    string str3 = "GeeksforGeeks";
    cout << is_isogram(str3) << endl;
    string str4 = "Alphabet";
    cout << is_isogram(str4) << endl;
    return 0;
} 

