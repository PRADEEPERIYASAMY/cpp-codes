#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void reverse(int arr[],int n){
    int l = 0,r = n-1;
    while(l<r){
        swap(arr[r],arr[l]);
        l++;r--;
    }
}

int main() {
    int arr[] = {1 ,1, 2 ,2 ,3};
    int n = 5;
    reverse(arr,n);
    
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    return 0;
}

