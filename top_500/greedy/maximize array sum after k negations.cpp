#include <bits/stdc++.h>
using namespace std;

// without sort
// int maximumSum(int arr[],int n,int k){
//     for (int i = 1; i <= k; i++) {
//         int m = INT_MAX;
//         int index = -1;
//         for (int j = 0; j < n; j++){
//             if(arr[j]<m){
//                 m = arr[j];
//                 index = j;
//             }
//         }
//         if(m == 0) break;
//         arr[index] = -arr[index];
//     }
//     int sum = 0;
//     sum = accumulate(arr,arr+n,0);
//     return sum;
// }

// with sort 
int maximumSum(int arr[],int n,int k){
    int sum = 0;
    int i = 0;
    sort(arr,arr+n);
    while(k>0){
        if(arr[i]>= 0) k = 0;
        else arr[i] = -arr[i],k--;
        i++;
    }
    sum = accumulate(arr,arr+n,0);
    return sum;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/
	int arr[] = { -2, 0, 5, -1, 2 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumSum(arr, n, k);
    return 0;
}

