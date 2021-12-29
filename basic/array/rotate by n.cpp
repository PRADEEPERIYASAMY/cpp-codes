#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void reverse(int arr[],int l,int r){
    while(l<r){
        swap(arr[r],arr[l]);
        l++;r--;
    }
}

int rotate(int arr[],int n,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}

int main() {
    int arr[] = {1 ,1, 2 ,2 ,3};
    int n = 5;
    rotate(arr,n,3);
    
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    return 0;
}

