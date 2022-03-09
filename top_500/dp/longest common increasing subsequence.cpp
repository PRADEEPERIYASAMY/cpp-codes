#include <bits/stdc++.h>
using namespace std;

int LCIS(int arr1[],int n,int arr2[],int m){
    int table[m];
    fill(table,table+m,0);
    for (int i = 0; i < n; i++) {
        int current = 0;
        for (int j = 0; j < m; j++) {
            if(arr1[i] == arr2[j]) table[j] = max(table[j],current+1);
            if(arr1[i]>arr2[j]) current = max(current,table[j]);
        }
    }
    return *max_element(table,table+n);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/
	int arr1[] = {3, 4, 9, 1};
    int arr2[] = {5, 3, 8, 9, 10, 2, 1};
  
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
  
    cout << "Length of LCIS is "
         << LCIS(arr1, n, arr2, m);
    return 0;
}
