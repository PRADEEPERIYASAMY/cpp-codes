using namespace std;
#include <bits/stdc++.h>

void sort012(int arr[],int n){
    int l = 0,m = 0,h = n-1;
    while(m<=h){
        switch(arr[m]){
            case 0: swap(arr[l++],arr[m++]);
            break;
            case 1: m++;
            break;
            case 2: swap(arr[m],arr[h--]);
            break;
        }
    }
}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)cout << arr[i] << " ";
}
 
int main(){
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr, n);
    cout << "array after segregation ";
    printArray(arr, n);
    return 0;
}

