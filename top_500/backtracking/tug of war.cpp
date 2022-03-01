#include <bits/stdc++.h>
using namespace std;

void tugOfWarUtil(int arr[],int n,bool curElemnts[],int noOfSelectedElements,bool soln[],int &minDiff,int sum,int curSum,int curPosition){
    if(curPosition == n) return;
    if((n/2 - noOfSelectedElements)>(n - curPosition)) return;
    tugOfWarUtil(arr,n,curElemnts,noOfSelectedElements,soln,minDiff,sum,curSum,curPosition+1);
    noOfSelectedElements++;
    curSum = curSum + arr[curPosition];
    curElemnts[curPosition] = true;
    if(noOfSelectedElements == n/2){
        if(abs(sum/2 - curSum)<minDiff){
            minDiff = abs(sum/2 - curSum);
            for (int i = 0; i < n; i++) soln[i] = curElemnts[i];
        }
    }else{
        tugOfWarUtil(arr,n,curElemnts,noOfSelectedElements,soln,minDiff,sum,curSum,curPosition+1);
    }
    curElemnts[curPosition] = false;
}

void tugOfWar(int arr[],int n){
    bool curElemnts[n];
    memset(curElemnts,false,sizeof(curElemnts));
    bool soln[n];
    int minDiff = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++) sum+=arr[i];
    tugOfWarUtil(arr,n,curElemnts,0,soln,minDiff,sum,0,0);
    cout<<"The first subset is: ";
    for (int i = 0; i < n; i++) if(soln[i] == true) cout<<arr[i]<<" ";
    cout<<"\n The second subset is: ";
    for (int i = 0; i < n; i++) if(soln[i] == false) cout<<arr[i]<<" ";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/tug-of-war/
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}

