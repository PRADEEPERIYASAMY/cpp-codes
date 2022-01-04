#include<bits/stdc++.h>
using namespace std;

int lbs(int arr[],int n){
    int lis[n],lds[n];
    lis[0] = arr[0];
    for (int i = 1; i < n; i++){
        lis[i] = arr[i];
        for (int j = 0; j < i; j++) if(arr[j]<arr[i]) lis[i] = max(lis[i],lis[j]+arr[i]);
    }
    lds[n-1] = arr[n-1];
    for (int i = n-2; i >=0; i--){
        lds[i] = arr[i];
        for (int j = n-1; j > i; j--) if(arr[j]<arr[i]) lds[i] = max(lds[i],lds[j]+arr[i]);
    }
    int res = lis[0]+lds[0] - arr[0]; // -1 for removing count of arr[i] twice
    for (int i = 1; i < n; i++) res = max(res,lis[i]+lds[i] - arr[i]);
    return res;
}

int main() {
    int arr[] = {80, 60, 30, 40, 20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LBS is %d\n", lbs( arr, n ) );
    return 0;
}

