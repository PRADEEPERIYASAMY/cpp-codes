#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str){
    int len = str.size();
    len--;
    for (int i = 0; i < len; i++) {
        if(str[i] != str[len]) return false;
        len--;
    }
    return true;
}

void printSolution(vector<vector<string>> partitions){
    for (int i = 0; i < partitions.size(); i++) {
        for (int j = 0; j < partitions[i].size(); j++) cout<<partitions[i][j]<<" ";
        cout<<"\n";
    }
    return;
}

void addStrings(vector<vector<string>> &v,string &s,vector<string> tmp,int index){
    int len = s.size();
    string str;
    if(index == len){
        v.push_back(tmp);
        return;
    }
    for (int i = index; i < len; i++) {
        str = str+s[i];
        if(checkPalindrome(str)){
            tmp.push_back(str);
            addStrings(v,s,tmp,i+1);
            tmp.pop_back();
        }
    }
}

void partition(string s,vector<vector<string>> &v){
    vector<string> tmp;
    addStrings(v,s,tmp,0);
    printSolution(v);
    return;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-palindromic-partitions-string/
	string s = "geeks";
    vector<vector<string> > partitions;
    partition(s, partitions);
	return 0;
}

