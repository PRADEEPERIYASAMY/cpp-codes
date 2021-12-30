#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int longestDistinct(string &str){
    int n = str.length();
    int res = 0;
    vector<int> prev(CHAIR,-1);
    int i = 0;
    for (int j = 0; j < n; j++) {
        i = max(i,prev[str[j]]+1); // to update old index of chair with new one
        int m = j-i+1;
        res = max(res,m);
        prev[str[j]] = j;
    }
    return res;
}

int main() { 
    string str = "geeksforgeeks"; 
	int len = longestDistinct(str); 
	cout << "The length of the longest distinct characters substring is "<< len; 
	return 0;
} 

