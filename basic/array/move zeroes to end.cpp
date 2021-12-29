#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void moveZeroes(int arr[],int n){
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] != 0){
            swap(arr[ind],arr[i]);
            ind++;
        }
    }
}

int main() {
    int arr[] = {0,1, 0 ,2 ,3};
    int n = 5;
    moveZeroes(arr,n);
    
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    return 0;
}

