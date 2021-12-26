#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool pairInSortedRotated(int arr[],int n,int x){
    int i = 0;
    int l=0,h= n-1;
    
    for (i = 0; i < n-1; i++) {
        if(arr[i]>arr[i+1]) break;
    }
    
    l = (i+1)%n;
    h = i;
    
    while(l != h){
        if(arr[l]+arr[h] == x) return true;
        if(arr[l]+arr[h]<x){
            l = (l+1)%n;
        }else{
            h = (n+h-1)%n;
        }
    }
    
    return false;
}

    int main(){
    int arr[] = {11, 15, 6, 8, 9, 10};
    int sum = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    if (pairInSortedRotated(arr, n, sum))
        cout << "Array has two elements with sum 16";
    else
        cout << "Array doesn't have two elements with sum 16 ";
 
    return 0;
}

