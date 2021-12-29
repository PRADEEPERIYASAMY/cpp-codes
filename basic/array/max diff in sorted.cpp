#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int maxDiff(int arr[],int n){
    int res = arr[1]-arr[0],m = arr[0];
    for (int i = 1; i < n; i++) {
        res = max(res,arr[i]-m);
        m = min(m,arr[i]);
    }
    return res;
}

int main() {
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;
    cout<<maxDiff(arr, n);
}

