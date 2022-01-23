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

void sortBySetBitCount(int arr[],int n){
    vector<vector<int>> count(32);
    int setbitcount = 0;
    for (int i = 0; i < n; i++) {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }
    int ind = 0;
    for (int i = 31; i >= 0; i--) for (int j = 0; j < count[i].size(); j++) arr[ind++] = count[i][j];
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

