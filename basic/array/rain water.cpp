#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int getWater(int arr[],int n){
    int res = 0;
    int lm[n],rm[n];
    lm[0] = arr[0];
    for (int i = 1; i < n; i++) lm[i] = max(lm[i-1],arr[i]);
    
    rm[n-1] = arr[n-1];
    for (int i = n-2; i>= 0; i--) rm[i] = max(rm[i+1],arr[i]);
    
    for (int i = 1; i < n-1 ; i++) {
        res+=(min(lm[i],rm[i]) - arr[i]);
    }
    
    return res;
}

int main() {
    int arr[] = {5, 0, 6, 2, 3}, n = 5;
    cout<<getWater(arr, n);
}

