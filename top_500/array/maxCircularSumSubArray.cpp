#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// maximum circular sum

int maxSumSubArray(int arr[],int n){
    int max_ = arr[0];
    int curMax = arr[0];
    
    for (int i = 1; i < n; i++) {
        curMax = max(curMax+arr[i],arr[i]);
        max_ = max(max_,curMax);
    }
    
    return max_;
}

int circularSumSubArray(int arr[],int n){
    int normalMax = maxSumSubArray(arr,n);
    
    if(normalMax < 0) return normalMax;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+=arr[i];
        arr[i] = -1*arr[i];
    }
    
    sum+=maxSumSubArray(arr,n);
    
    return max(sum,normalMax);
    
}

int main(){
    
    int a[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum circular sum is " << circularSumSubArray(a, n) << endl;
    return 0;
    
}


