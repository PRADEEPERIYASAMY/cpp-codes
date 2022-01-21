using namespace std;
#include <bits/stdc++.h>

int getMax(int arr[],int n){
    return *max_element(arr,arr+n);
}

void countSort(int arr[],int n,int e){
    int outPut[n];
    int i,count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i]/e)%10]++;
    for (int i = 1; i < 10; i++) count[i]+=count[i-1];
    for (int i = n-1; i >= 0; i--) {
        outPut[count[(arr[i]/e)%10]-1] = arr[i];
        count[(arr[i]/e)%10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = outPut[i];
}

void radixsort(int arr[],int n){
    int m = getMax(arr,n);
    for (int i = 1; m/i>0;i*=10) countSort(arr,n,i);
}

void print(int arr[],int n){
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
 
int main(){
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}

