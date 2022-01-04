#include<bits/stdc++.h>
using namespace std;

int lbs(int arr[],int n){
    int lis[n],lds[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++){
        lis[i] = 1;
        for (int j = 0; j < i; j++) if(arr[j]<arr[i]) lis[i] = max(lis[i],lis[j]+1);
    }
    lds[n-1] = 1;
    for (int i = n-2; i >=0; i--){
        lds[i] = 1;
        for (int j = n-1; j > i; j--) if(arr[j]<arr[i]) lds[i] = max(lds[i],lds[j]+1);
    }
    int res = lis[0]+lds[0] - 1; // -1 for removing count of arr[i] twice
    for (int i = 1; i < n; i++) res = max(res,lis[i]+lds[i] - 1);
    return res;
}

int main() {
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LBS is %d\n", lbs( arr, n ) );
    return 0;
}

