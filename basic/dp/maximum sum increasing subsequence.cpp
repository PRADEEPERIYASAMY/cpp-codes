#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

int MSIS(int arr[],int n){
    int msis[n];
    
    for (int i = 0; i < n; i++) {
        msis[i] = arr[i];
        for (int j = 0; j <i; j++) {
            if(arr[j]<arr[i]) msis[i] = max(msis[i],msis[j]+arr[i]);
        }
    }
    
    return *max_element(msis,msis+n);
}

int main() {
    
    int n = 3;
    int arr[] = {5, 10, 20};	
    cout<<MSIS(arr, n);
    return 0;
}

