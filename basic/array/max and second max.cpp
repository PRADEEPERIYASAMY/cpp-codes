#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void maxAndSecondMax(int arr[],int n){
    int m = arr[0],sm = INT_MIN;
    for (int i = 1; i < n; i++) {
        if(arr[i]>m){
            swap(sm,m);
            swap(m,arr[i]);
        }else if(arr[i]> sm) swap(sm,arr[i]);
    }
    
    cout<<m<<" "<<sm;
    return;
}

int main() {
	int arr[] = {1,2,3,4,5};
    maxAndSecondMax(arr,5);
    return 0;
}

