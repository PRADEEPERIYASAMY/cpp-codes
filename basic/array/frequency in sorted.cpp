#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void printFreq(int arr[],int n){
    int i = 1,fre = 1;
    while(i<n){
        
        while(i<n && arr[i] == arr[i-1]){
            fre++; i++;
        }
        cout<<arr[i-1]<<"--"<<fre<<endl;
        i++;
        fre = 1;
    }
}

int main() {
    
    int arr[] = {10, 10, 20, 30, 30, 30}, n = 6;
    printFreq(arr, n);
    
    return 0;
}

