#include <bits/stdc++.h>
using namespace std;
#define R 3 
#define C 3

void printUtil(vector<vector<string>> &arr,int m,int n,vector<string> &outPut){
    outPut[m] = arr[m][n];
    if(m == R-1){
        for (int i = 0; i < R; i++) cout<<outPut[i]<<" ";
        cout<<endl;
        return;
    }
    for (int i = 0; i < C; i++) if(arr[m+1][i]!="") printUtil(arr,m+1,i,outPut);
}

void print(vector<vector<string>> &arr){
    vector<string> outPut(R);
    for (int i = 0; i < C; i++) if(arr[0][i] != "") printUtil(arr,0,i,outPut);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/
	vector<vector<string>> arr = {{"you", "we",""},
                        {"have", "are",""},
                        {"sleep", "eat", "drink"}};
    print(arr);
	return 0;
}


