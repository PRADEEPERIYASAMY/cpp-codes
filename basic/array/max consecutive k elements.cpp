#include <iostream>
using namespace std;

int maxSum(int arr[],int n,int k){
    int cur = 0;
    for (int i = 0; i < k; i++) cur+=arr[i];
    int m = cur;
    
    for (int i = k; i < n; i++) {
        cur = cur-arr[i-k]+arr[i];
        m = max(cur,m);
    }
    return m;
}

int main() {
	int arr[] = {1, 8, 30, -5, 20, 7}, n = 6, k = 3;
    cout<<maxSum(arr, n, k);
	return 0;
}

