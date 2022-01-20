using namespace std;
#include <bits/stdc++.h>

int ceilSearch(int arr[],int n,int x){
    int mid,l = 0,r = n-1;
    while(l<r){
        mid = (l+r)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]<x){
            if(mid+1 <= r && x<= arr[mid+1]) return mid+1;
            else l = mid+1;
        } 
        else {
            if(mid-1 >= l && x>= arr[mid-1]) return mid-1;
            else r = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int index = ceilSearch(arr, n,x);
    if(index == -1) cout << "Ceiling of " << x << " doesn't exist in array ";
    else cout << "ceiling of " << x << " is " << arr[index];
    return 0;
}

