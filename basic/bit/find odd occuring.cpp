#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// efficient

int findOdd(int arr[],int n){
    int res = 0;
    for (int i = 0; i < n; i++) res^=arr[i];
    return res;
}

int main() {
	int arr[]= {4, 3, 4, 4, 4, 5, 5, 3, 3}, n = 9;
    cout<<findOdd(arr, n);
}

