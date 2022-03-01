#include <bits/stdc++.h>
using namespace std;

char oper[10001];
bool flag = false;
void createExp(int arr[],int currVal,int index,int n){
    if(flag) return;
    if(index == n && currVal&101 == 0){
        flag = true;
        cout<<arr[0];
        for (int i = 1; i < n; i++) cout<<oper[i-1]<<arr[i];
        return;
    }
    else if(index == n && currVal%101 != 0) return;
    if(currVal %101 == 0){
        for (int i = index-1; i < n; i++) oper[i]='*';
        flag = true;
        cout<<arr[0];
        for (int i = 1; i < n; i++) cout<<oper[i-1]<<arr[i];
        return;
    }
    oper[index-1] = '+';
    createExp(arr,(currVal+arr[index])%101,index+1,n);
    oper[index-1] = '*';
    createExp(arr,(currVal*arr[index])%101,index+1,n);
    oper[index-1] = '-';
    createExp(arr,(currVal-arr[index])%101,index+1,n);
}

int main() {
	// pepcoding
	// https://www.hackerrank.com/rest/contests/master/challenges/arithmetic-expressions/hackers/vipram91/download_solution
	int n;
    cin>>n;
    int arr[n];
    for (int i =0; i<n;i++) cin>>arr[i];
    long int currVal=arr[0];  
    int index=1;
    flag = false;
    createExp(arr,currVal, index, n);
    return 0;
}

