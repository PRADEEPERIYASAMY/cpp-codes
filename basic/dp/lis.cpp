#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// dp n^2
// int LIS(int arr[],int n){
//     int lis[n];
//     lis[0] = 1;
//     for (int i = 1; i < n; i++) {
//         lis[i] = 1;
//         for (int j = 0; j < i; j++) {
//             if(arr[j]<arr[i]) lis[i] = max(lis[i],lis[j]+1);
//         }
//     }
    
//     return *max_element(lis,lis+n);
// }

// dp nlogn (using tail array )

int ceil(int tail[],int l, int r, int key){
    while(r>l){
        int m = l+(r-l)/2;
        if(tail[m]>= key) r = m;
        else l = m+1;
    }
    
    return r;
}

int LIS(int arr[],int n){
    int tail[n];
    int len = 1;
    
    tail[0] = arr[0];
    
    for (int i = 1; i < n; i++) {
        if(arr[i]>arr[len-1]){
            tail[len] = arr[i];
            len++;
        }else{
            int c = ceil(tail,0,len-1,arr[i]);
            tail[c] = arr[i];
        }
    }
    
    return len;
}

int main() {
	
    int arr[] ={3, 4, 2, 8, 10, 5, 1};
    int n = 7;
    cout<<LIS(arr, n);
    return 0;
}

