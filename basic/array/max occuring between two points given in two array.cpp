#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int maxOcc(int l[],int r[],int n){
    int arr[100];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
        arr[l[i]]++;
        arr[r[i]+1]--;
    }
    int m = arr[0], res = 0;
    for (int i = 1; i < 100; i++) {
        arr[i]+=arr[i-1];
        if(arr[i]>m){
            m = arr[i];
            res = i;
        }
    }
    return res;
}

int main() {
	int L[] = {1, 2, 3}, R[] = {3, 5, 7}, n = 3;
    cout<<maxOcc(L, R, n);
    return 0;
}

