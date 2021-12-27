#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

int checkBit(int pattern,int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if((pattern&arr[i]) == pattern) count++;
    }
    return count;
}

int maxAND(int arr[],int n){
    int res = 0,count = 0;
    for (int i = 31; i >=0; i--) {
        count = checkBit(res|(1<<i),arr,n);
        if(count>=2) res|=(1<<i);
    }
    
    return res;
}

int main() { 
    int arr[] = {4, 8, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum AND Value = " << maxAND(arr,n);
    return 0;
} 


