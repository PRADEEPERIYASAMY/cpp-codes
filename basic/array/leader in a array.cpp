#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void leaders(int arr[],int n){
    int l = arr[n-1];
    cout<<l<<" ";
    for (int i = n-2; i >= 0; i--) {
        if(arr[i]>l){
            l = arr[i];
            cout<<l<<" ";
        }
    }
}

int main() {
    
    int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;
    leaders(arr, n);
    
    return 0;
}

