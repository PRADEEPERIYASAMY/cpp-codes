using namespace std;
#include <bits/stdc++.h>

void find4Numbers(int arr[],int n,int x){
    int l,r;
    sort(arr,arr+n);
    for (int i = 0; i < n-3; i++) {
        for (int j = i+1; j < n-2; j++) {
            l = j+1,r = n-1;
            while(l<r){
                int sum = arr[i]+arr[j]+arr[l]+arr[r];
                if(sum == x){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<" "<<arr[r];
                    return;
                }
                else if(sum<x) l++;
                else r--;
            }
        }
    }
}

int main(){
    int A[] = {1, 4, 45, 6, 10, 12}; 
    int X = 21; 
    int n = sizeof(A) / sizeof(A[0]); 
    find4Numbers(A, n, X); 
    return 0; 
}

