using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int sortK(int arr[],int n,int k){
    int i,j,key;
    for (int i = 1; i < n; i++) {
        j = i-1;
        key = arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++) cout << arr[i] <<space;
}

int main(){
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);
    cout << "Following is sorted array" << endl;
    printArray(arr, n);
    return 0;
}

