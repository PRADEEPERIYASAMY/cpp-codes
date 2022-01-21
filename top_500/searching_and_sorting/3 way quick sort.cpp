using namespace std;
#include <bits/stdc++.h>

void printarr(int arr[],int n){
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void partition(int arr[],int low,int high,int &i,int &j){
    if(high-low <= 1){
        if(arr[high]<arr[low]) swap(arr[high],arr[low]);
        i = low;
        j = high;
        return;
    }
    int mid = low;
    int pivot = arr[high];
    while(mid<=high){
        if(arr[mid]<pivot) swap(arr[low++],arr[mid++]);
        else if(arr[mid] == pivot) mid++;
        else if(arr[mid]>pivot) swap(arr[mid],arr[high--]);
    }
    i = low-1;
    j = mid;
}

void  quicksort(int arr[],int low,int high){
    if(low>=high) return;
    int i,j;
    partition(arr,low,high,i,j);
    quicksort(arr,low,i);
    quicksort(arr,j,high);
}

int main(){
    int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
    int size = sizeof(a) / sizeof(int);
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    return 0;
}

