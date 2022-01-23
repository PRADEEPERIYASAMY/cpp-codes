using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int countBits(int a){
    int count = 0;
    while(a){
        if(a&1) count+=1;
        a = a>>1;
    }
    return count;
}

int cmp(int a,int b){
    int count1 = countBits(a);
    int count2 = countBits(b);
    return count1>count2;
}

void sortBySetBitCount(int arr[],int n){
    sort(arr,arr+n,cmp);
}

void printArr(int arr[],int n){
    for (int i = 0; i < n; i++) cout<<arr[i]<<space;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}

