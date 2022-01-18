using namespace std;
#include <bits/stdc++.h>

int maxDiff(int arr[],int n){
    int max_diff = arr[1]-arr[0];
    int min_element = arr[0];
    for (int i = 1; i < n; i++) {
        max_diff = max(max_diff,arr[i]-min_element);
        min_element = min(min_element,arr[i]);
    }
    return max_diff;
}

int main(){
    int arr[] = {1, 2, 90, 10, 110};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum difference is " << maxDiff(arr, n);
    return 0;
}

