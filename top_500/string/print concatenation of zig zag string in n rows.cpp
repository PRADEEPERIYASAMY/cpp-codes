#include <bits/stdc++.h>
using namespace std;

void printZigZagConcat(string str,int n){
    if(n == 1){
        cout<<str;
        return;
    }
    int len = str.size();
    vector<string> arr(n);
    int row = 0;
    bool down;
    for (int i = 0; i < len; i++) {
        arr[row].push_back(str[i]);
        if(row == n-1) down = false;
        else if(row == 0) down = true;
        down?row++:row--;
    }
    for (int i = 0; i < n; i++) cout<<arr[i];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-concatenation-of-zig-zag-string-form-in-n-rows/
	string str = "GEEKSFORGEEKS";
    int n = 3;
    printZigZagConcat(str, n);
	return 0;
}

