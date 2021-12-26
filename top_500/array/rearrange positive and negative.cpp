#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void rearrange(int arr[],int n){
    
    int i =0;
    
    for (int j = 0; j < n; j++) {
        if(arr[j]<0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    
    int pos = i,neg = 0;
    
    while(pos<n && neg < pos && arr[neg] <0){
        swap(arr[neg],arr[pos]);
        pos++;
        neg+=2;
    }
    
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}

