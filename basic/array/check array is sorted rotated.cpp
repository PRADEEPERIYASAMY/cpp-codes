#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

bool checkRotatedAndSorted(int arr[],int n){
    bool inc = true;
    if(arr[0]<arr[n-1]) inc = false;
    if(inc){
            int i;
            for(i = 1;i < n;i++){
                if(arr[i] < arr[i - 1])
                break;
            }
            i++;
            for(;i<n;i++){
                if(arr[i] < arr[i - 1])
                break;
            }
            if(i == n)
            return true;
            return false;
        }else{
            int i;
            for(i = 1;i < n;i++){
                if(arr[i] > arr[i - 1])
                break;
            }
            i++;
            for(;i<n;i++){
                if(arr[i] > arr[i - 1])
                break;
            }
            if(i == n) return true;
            return false;
        }
    return false;
}

int main() {
	int arr[] = {3,4,1,2};
    cout << checkRotatedAndSorted(arr,4);
    return 0;
}

