#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int maxProfit(int arr[],int n){
    int prof = 0;
    for (int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) prof+=(arr[i]-arr[i-1]);
    }
    return prof;
}

int main() {
    int arr[] = {1, 5, 3, 8, 12}, n = 5;
    cout<<maxProfit(arr, n);
}

