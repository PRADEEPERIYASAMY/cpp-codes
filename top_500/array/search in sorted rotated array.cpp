#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int search(int arr[],int n,int x){
    int l=0,h=n-1;
    while(l<h){
        int mid = (l+h)/2;
        
        if(arr[mid] == x) return mid;
        else if( arr[l] < arr[mid]){
            if(x >= arr[l] && x < arr[mid]) h = mid-1;
            else l = mid+1;
        }else{
            if(x > arr[mid] && x<= arr[h]){
                if(x > arr[mid] && x<= arr[h]) l = mid+1;
                else h= mid -1;
            }
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int i = search(arr,n, key);
 
    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
}

