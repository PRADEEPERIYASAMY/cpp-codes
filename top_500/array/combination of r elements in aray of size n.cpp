using namespace std;
#include <bits/stdc++.h>

void printCombinationUtil(int arr[],int data[],int start,int end,int index,int r){
    if(index == r) {
        for (int i = 0; i < r; i++) cout<<data[i]<<" ";
        cout<<endl;
        return;
    }
    for ( int i = start;i<= end && end-i+1>=r-index;i++) {
        data[index] = arr[i];
        printCombinationUtil(arr,data,i+1,end,index+1,r);
    }
}

void printCombination(int arr[],int n,int r){
    int data[r];
    printCombinationUtil(arr,data,0,n-1,0,r);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
    return 0;
}

