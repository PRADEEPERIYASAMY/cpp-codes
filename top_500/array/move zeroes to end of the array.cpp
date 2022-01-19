using namespace std;
#include <bits/stdc++.h>

void pushZerosToEnd(int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i]!= 0){
            swap(arr[count],arr[i]);
            count++;
        }
    }
}

int main(){
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    pushZerosToEnd(arr, n);
    printf("%s\n", "Array after pushing all zeros to end of array:");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

