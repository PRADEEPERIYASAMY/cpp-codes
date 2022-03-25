#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// iterative 
// int bSearch(int arr[],int n,int x){
//     int left = 0,right = n-1;
//     while(left<=right){
//         int mid = left + (right - left)/2;
//         if(arr[mid] == x) return mid;
//         else if(arr[mid]<x) left = mid+1;
//         else right = mid-1;
//     }
//     return -1;
// }

// recursive
int bSearch(int arr[],int left,int right,int x){
    if(left > right) return -1;
    int mid = left + (right - left)/2;
    if(arr[mid] == x) return mid;
    else if(arr[mid] > x) return bSearch(arr,left,mid-1,x);
    else return bSearch(arr,mid+1,right,x);
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60}, n = 6;
	int x = 20;
	//cout<<bSearch(arr, n, x);
	cout<<bSearch(arr,0,n-1,x);
    return 0;
}
