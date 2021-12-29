#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int maxIndexDiff(int arr[],int n){
    int lmin[n],rmax[n];
    lmin[0] = arr[0];
    for (int i = 1; i < n; i++) lmin[i] = min(lmin[i-1],arr[i]);
    rmax[n-1] = arr[n-1];
    for (int i = n-2; i >=0; i--) rmax[i] = max(rmax[i+1],arr[i]);
    int i=0,j=0,res = -1;
    while(i<n && j<n){
        if(lmin[i]<= rmax[j]){
            res = max(res,j-i);
            j++;
        }else{
            i++;
        }
    }
    return res;
}

int main() {
	int arr[] = { 9, 2, 3, 4, 5,6, 7, 8, 18, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    cout << maxDiff;
    return 0;
}

