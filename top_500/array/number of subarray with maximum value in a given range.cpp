using namespace std;
#include <bits/stdc++.h>

int countTotalSubarray(int n){
    return n*(n+1)/2;
}

int countSubarrays(int arr[],int n,int l,int r){
    int res = 0;
    int exc = 0,inc = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i]>r){
            res+=(countTotalSubarray(inc)- countTotalSubarray(exc));
            inc = 0;
            exc = 0;
        }else if(arr[i]<l){
            inc++;
            exc++;
        }else{
            res-=countTotalSubarray(exc);
            exc = 0;
            inc++;
        }
    }
    res+=(countTotalSubarray(inc)- countTotalSubarray(exc));
    return res;
}

int main(){
    int a[] = { 2, 0, 11, 3, 0 };
    int n = sizeof(a) / sizeof(a[0]);
    int l = 1, r = 10;
    cout << countSubarrays(a, n, l, r);
    return 0;
}

