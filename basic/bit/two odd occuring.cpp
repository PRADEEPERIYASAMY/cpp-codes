#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// efficient

void oddAppearing(int arr[],int n){
    int res1 = 0,res2 = 0,x = 0;
    for (int i = 0; i < n; i++) x^=arr[i];
    int sn = x&(~(x-1));
    for (int i = 0; i < n; i++) {
        if(arr[i]&sn != 0) res1^=arr[i]; // imp
        else res2^=arr[i];
    }
    cout<<res1<<" "<<res2;
}

int main() {
	
	int arr[]= {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;
    oddAppearing(arr, n);
    
}

