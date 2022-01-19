using namespace std;
#include <bits/stdc++.h>

int maxSumWithK(int arr[],int n,int k){
    int maxSum[n];maxSum[0] = arr[0];
    int cur_max = arr[0];
    for (int i = 1; i < n; i++) {
        cur_max = max(arr[i],cur_max+arr[i]);
        maxSum[i] = cur_max;
    }
    int sum = 0;
    for (int i = 0; i < k; i++) sum+=arr[i];
    int result=sum;
    for (int i = k; i < n; i++) {
        sum+=(arr[i]-arr[i-k]);
        result = max(result,sum+maxSum[i-k]);
    }
    return result;
}

int main(){
    int a[] = {1, 2, 3, -10, -3};
    int k = 4;
    int n = sizeof(a)/sizeof(a[0]);
    cout << maxSumWithK(a, n, k);
    return 0;
}

