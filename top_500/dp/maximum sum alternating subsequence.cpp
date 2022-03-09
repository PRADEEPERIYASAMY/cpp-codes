#include <bits/stdc++.h>
using namespace std;

int maxAlternateSum(int arr[],int n){
    if(n == 1) return arr[0];
    int m = *min_element(arr,arr+n);
    if(m == arr[0]) return arr[0];
    int dec[n],inc[n];
    memset(dec,0,sizeof(dec));
    memset(inc,0,sizeof(inc));
    dec[0] = inc[0] = arr[0];
    int flag = 0;
    for (int i = 1; i <n; i++) {
        for (int j = 0; j <i; j++) {
            if(arr[j]>arr[i]) dec[i] = max(dec[i],inc[j]+arr[i]),flag = 1;
            else if(arr[j]<arr[i] && flag == 1) inc[i] = max(inc[i],dec[j]+arr[i]);
        }
    }
    return max(*max_element(dec,dec+n),*max_element(inc,inc+n));
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/maximum-sum-alternating-subsequence-sum/
	int arr[] = { 8, 2, 3, 5, 7, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum = " << maxAlternateSum(arr, n)<< endl;
    return 0;
}
