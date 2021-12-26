#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int findMinDiff(int arr[],int n,int m){
    if(n ==0 || m == 0) return 0;
    if(n<m) return -1;
    
    int mi = INT_MAX;
    sort(arr,arr+n);
    
    for (int i = 0; i+m-1 < n; i++) {
        int diff = arr[i+m-1]-arr[i];
        mi = min(mi,diff);
    }
    
    return mi;
    
}

int main()
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}

