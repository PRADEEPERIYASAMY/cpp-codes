using namespace std;
#include <bits/stdc++.h>

int bitonic(int arr[],int n){
    int inc[n],desc[n];
    inc[0] = 1;
    desc[n-1] = 1;
    for (int i = 1; i < n; i++) inc[i] = arr[i]>=arr[i-1]?inc[i-1]+1:1;
    for (int i = n-2; i >=0; i--) desc[i] = arr[i]>= arr[i+1]?desc[i+1]+1:1;
    int m = inc[0]+desc[0]-1;
    for (int i = 1; i < n; i++) m = max(desc[i]+inc[i]-1,m);
    return m;
}

int main(){
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "nLength of max length Bitonic Subarray is " << bitonic(arr, n);
    return 0;
}

