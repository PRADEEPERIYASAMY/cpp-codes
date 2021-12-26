#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// lcs recursive

// int lis_(int arr[],int n,int *max){
    
//     if(n == 1) return 1;
//     int curmax = 1,res;
    
//     for (int i = 1; i < n; i++) {
//       res = lis_(arr,i,max);
//       if(arr[i-1]<arr[n-1] && res+1 > curmax) curmax = res+1;
//     }
    
//     if(*max<curmax) *max = curmax;
    
//     return curmax;
    
// }

// int lis(int arr[], int n){
//     int max = 1;
//     lis_(arr,n,&max);
    
//     return max;
// }

// lis using decltype

int lis(int arr[],int n){
    int lis[n];
    lis[0] = 1;
    
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j<i; j++) {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1) lis[i] = lis[j]+1;
        }
    }
    
    return *max_element(lis,lis+n);
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}

