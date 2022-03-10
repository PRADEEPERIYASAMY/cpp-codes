#include <bits/stdc++.h>
using namespace std;

void printMaxOfMin(int arr[],int n){
    stack<int> s;
    int left[n+1];
    int right[n+1];
    fill(left,left+n+1,-1);
    fill(right,right+n+1,n);
    for (int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
        if(!s.empty()) left[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i = n-1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
        if(!s.empty()) right[i] = s.top();
        s.push(i);
    }
    int ans[n+1] = {0};
    for (int i = 0; i <n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len],arr[i]);
    }
    for (int i = n-1; i >= 1; i--) ans[i] = max(ans[i],ans[i+1]);
    for (int i = 1; i <= n; i++) {
        cout<<ans[i]<<" ";
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
	int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxOfMin(arr, n);
    return 0;
}