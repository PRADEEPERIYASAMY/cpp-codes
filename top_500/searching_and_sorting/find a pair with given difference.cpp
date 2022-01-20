using namespace std;
#include <bits/stdc++.h>

bool findPair(int arr[],int n,int d){
    int i = 0,j = 1;
    while(i<n && j<n){
        if(i!= j && (arr[i]-arr[j] == d || arr[j]-arr[i] == d)){
            cout<<"pair found "<<arr[i]<<" "<<arr[j];
            return true;
        }
        else if((arr[j]-arr[i])<d) j++;
        else i++;
    }
    return false;
}

// for unsorted use hashing
int main(){
    int arr[] = {1, 8, 30, 40, 100}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int n = -60; 
    findPair(arr, size, n); 
    return 0;
}

