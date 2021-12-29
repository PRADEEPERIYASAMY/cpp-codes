#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// similar to alternate max maxSum
int maxSum(int arr[], int n)
{
	if(n==0) return arr[0];
	int prev_prev = arr[0];
	int prev = max(arr[0], arr[1]);
	int res = prev;
	for(int i=3; i<=n; i++){
		res = max(prev, prev_prev + arr[i-1]);
		prev_prev = prev;
		prev = res;
	}
	if(res<0) return *max_element(arr,arr+n);
	return res;
}

int main() {
    int n = 5, arr[]= {-9,-8,8,3,-4};
    cout<<maxSum(arr, n);
    return 0;
}

