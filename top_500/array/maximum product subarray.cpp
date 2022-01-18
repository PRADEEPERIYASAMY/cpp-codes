using namespace std;
#include <bits/stdc++.h>

int maxSubarrayProduct(int arr[],int n){
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];
    int max_so_far = arr[0];
    for (int i = 1; i < n; i++) {
        int temp = max({arr[i],arr[i]*max_ending_here,arr[i]*min_ending_here});
        min_ending_here = min({arr[i],arr[i]*max_ending_here,arr[i]*min_ending_here});
        max_ending_here = temp;
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}

int main(){
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "<< maxSubarrayProduct(arr, n);
    return 0;
}

