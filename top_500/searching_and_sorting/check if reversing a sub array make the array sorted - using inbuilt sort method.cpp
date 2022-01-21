using namespace std;
#include <bits/stdc++.h>

bool checkReverse(int arr[],int n){
    int temp[n];
    copy(arr,arr+n,temp);
    sort(arr,arr+n);
    int front;
    for (int front = 0; front < n; front++) if(arr[front] != temp[front]) break;
    int back;
    for (int back = n-1; back >= 0; back--) if(arr[back] != temp[back]) break;
    if(front>=back) return true;
    do{
        front++;
        if(arr[front-1]<arr[front]) return false;
    }while(front != back);
    return true;
}

int main(){
    int arr[] = {1, 3, 4, 10, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    checkReverse(arr, n)? cout << "Yes" : cout << "No";
    return 0;
}

