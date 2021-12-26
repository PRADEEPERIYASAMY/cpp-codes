#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int maxSum(int arr[],int n){
    int cSum = 0;
    for (int i = 0; i < n; i++) cSum+=arr[i];
    
    int curSum = 0;
    for (int i = 0; i < n; i++) curSum+=(i*arr[i]);
    
    int res = curSum;
    
    for (int i = 1; i < n; i++) {
        curSum = curSum -(cSum - arr[i-1]) + arr[i-1]*(n-1);
        res = max(curSum,res);
    }
    
    return res;
}

int main()
{
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}

