#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int missingNumber(int arr[],int n){
    int temp[n+1] = {0};
    for (int i = 0; i <= n; i++){
        if(arr[i]>0 && arr[i]<= n) temp[arr[i]]++;
    }
    int res = INT_MAX;
    for (int i = 1; i <= n; i++){
        if(temp[i] == 0){
            res = i;
            break;
        }
    }
    return min(res,n+1);
}

int main() {
	int arr[] = {1,2,3,4,5};
    cout<<missingNumber(arr,5);
    return 0;
}

