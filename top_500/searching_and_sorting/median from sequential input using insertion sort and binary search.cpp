using namespace std;
#include <bits/stdc++.h>

int binarySearch(int arr[],int item,int low,int high){
    if(low>=high) return (item>arr[low])?low+1 : low;
    int mid = (high+low)/2;
    if(item == arr[mid]) return mid+1;
    if(item > arr[mid]) return binarySearch(arr,item,mid+1,high);
    return binarySearch(arr,item,low,mid-1);
}

void printMedian(int arr[],int n){
    int i,j,pos,num;
    int count = 1;
    cout<<"Median after reading 1 "<<arr[0]<<"\n";
    for (int i = 1; i < n; i++) {
        float median;
        j = i-1;
        num = arr[i];
        pos = binarySearch(arr,num,0,j);
        while(j>=pos){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = num;
        count++;
        if(count%2 != 0) median = arr[count/2];
        else median = (arr[count/2]+arr[count/2-1])/2;
        cout<<"Median after reading "<<num<<" "<<median<<"\n";
    }
}
 
int main(){
    int arr[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printMedian(arr, n);
    return 0;
}

