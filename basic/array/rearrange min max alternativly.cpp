#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void rearrange(int arr[],int n){
    int mi = n-1,si = 0;
    int me = arr[n-1]+1;
    
    for (int i = 0; i < n; i++) {
        if(i%2 == 0){
            arr[i]+=(arr[mi]%me)*me;
            mi--;
        }else{
            arr[i]+=(arr[si]%me)*me;
            si++;
        }
    }
    
    for (int i = 0; i < n; i++) arr[i]/=me;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Arrayn";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    rearrange(arr, n);
    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

