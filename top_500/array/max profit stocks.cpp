#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int maxProfit(int arr[],int n){
    int m = 0;
    for (int i = 1; i < n; i++) {
        if(arr[i]> arr[i-1]) m+=(arr[i]-arr[i-1]);
    }
    return m;
}

int main(){
    
    int prices[] = { 100, 180, 260, 310, 40, 535, 695 };
    int N = sizeof(prices) / sizeof(prices[0]);
    cout << maxProfit(prices, N) << endl;
    return 0;
}

