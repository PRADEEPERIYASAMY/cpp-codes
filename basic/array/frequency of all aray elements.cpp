#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void frequencyCount(int arr[],int n){
    int temp[n] = {0};
    for (int i = 0; i < n; i++) temp[arr[i]-1]++;
    for (int i = 0; i < n; i++) cout<<temp[i]<<" ";
}

int main() {
	int arr[] = {2, 3, 2, 3, 5};
    frequencyCount(arr,5);
    return 0;
}

