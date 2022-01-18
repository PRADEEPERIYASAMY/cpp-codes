using namespace std;
#include <bits/stdc++.h>

int merge(int arr[],int l,int m,int r){
    int n1 = m-l+1,n2=r-m;
    int left[n1],right[n2];
    for (int i = 0; i < n1; i++) left[i] = arr[l+i];
    for (int i = 0; i < n2; i++) right[i] = arr[m+i+1];
    int inv_count = 0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]) arr[k++] = left[i++];
        else{
            arr[k++] = right[j++];
            inv_count+=(n1-i);
        }
    }
    while(i<n1) arr[k++] = left[i++];
    while(j<n2) arr[k++] = right[j++];
    return inv_count;
}

int _mergeSort(int arr[],int left,int right){
    int mid,inv_count = 0;
    if(left<right){
        mid = (left+right)/2;
        inv_count+=_mergeSort(arr,left,mid);
        inv_count+=_mergeSort(arr,mid+1,right);
        inv_count+=merge(arr,left,mid,right);
    }
    return inv_count;
}

int mergeSort(int arr[],int n){
    return _mergeSort(arr,0,n-1);
}

int main(){
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}

