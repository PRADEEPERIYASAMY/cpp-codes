#include <bits/stdc++.h>
using namespace std;

int maxSumWithK(int a[],int n,int k){
    int maxSum[n];
    maxSum[0] = a[0];
    int curMax = a[0];
    for (int i = 1; i < n; i++) {
        curMax = max(a[i],curMax+a[i]);
        maxSum[i] = curMax;
    }
    int sum = 0;
    sum = accumulate(a,a+k,0);
    int result = sum;
    for (int i = k; i <n; i++) {
        sum = sum+a[i] - a[i-k];
        result = max({result,sum,sum+maxSum[i-k]});
    }
    return result;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/
	int a[] = {1, 2, 3, -10, -3};
    int k = 4;
    int n = sizeof(a)/sizeof(a[0]);
    cout << maxSumWithK(a, n, k);
    return 0;
}