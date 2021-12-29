#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int maxSumSubarrar(int arr[],int n){
    int maxF[n],maxB[n],m,cur;
    cur = m = maxF[0] = arr[0];
    
    for (int i = 1; i < n; i++){
        cur= max(cur+arr[i],arr[i]);
        m = max(cur,m);
        maxF[i] = cur;
    }
    cur = m = maxB[n-1] = arr[n-1];

    for (int i = n-2; i >= 0; i--) {
        cur= max(cur+arr[i],arr[i]);
        m = max(cur,m);
        maxB[i] = cur;
    }
    
    int res = m;
    
    for (int i = 1; i < n-1; i++) res = max(res,max(0,maxF[i-1])+max(0,maxB[i+1]));
    
    // all are negative
    if(res == 0) return *max_element(arr,arr+n);
    
    return res;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxSumSubarrar(arr,sizeof(arr)/sizeof(arr[0])) << endl;
    return 0;
}

