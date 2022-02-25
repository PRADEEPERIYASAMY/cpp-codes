#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256

int fact(int n){
    return (n<=1) ? 1: n*fact(n-1);
}

void populateAndIncreaseCount(vector<int> &count,string str){
    int i;
    for (int i = 0; i < str.size(); i++) count[str[i]]++;
    for (int i = 1; i < MAX_CHAR; i++) count[i]+=count[i-1];
}

void updateCount(vector<int> &count,char ch){
    for (int i = ch; i < MAX_CHAR; i++) count[i]--;
}

int findRank(string str){
    int len = str.size();
    int mul = fact(len);
    int rank = 1,i;
    vector<int> count(MAX_CHAR,0);
    populateAndIncreaseCount(count,str);
    for (int i = 0; i < len; i++) {
        mul/=len-i;
        rank+=count[str[i]-1]*mul;
        updateCount(count,str[i]);
    }
    return rank;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
	string str = "string";
    cout << findRank(str);
    return 0;
}

