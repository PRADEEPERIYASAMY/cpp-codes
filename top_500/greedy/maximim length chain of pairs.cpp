#include <bits/stdc++.h>
using namespace std;

int maxChainLength(pair<int,int> arr[],int n){
    int i,j,m = 0;
    int lis[n]={1};
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if(arr[i].first > arr[j].second && lis[i]<lis[j]+1) lis[i] = lis[j]+1;
        }
    }
    
    for (int i = 0; i < n; i++) m = max(m,lis[i]);
    return m;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
	pair<int,int> arr[] = { {5, 24}, {15, 25},{27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of maximum size chain is "<< maxChainLength( arr, n );
    return 0;
}

