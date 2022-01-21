using namespace std;
#include <bits/stdc++.h>

int computeCost(int arr[],int n,int x){
    int cost = 0;
    for (int i = 0; i < n; i++) cost+=abs(arr[i]-x);
    return cost;
}

int minCostToMakeElementEqual(int arr[],int n){
    int low,high;
    low = high = arr[0];
    for (int i = 0; i < n; i++) {
        low = min(low,arr[i]);
        high = max(high,arr[i]);
    }
    while((high-low)>2){
        int mid1 = low+(high-low)/3;
        int mid2 = high-(high-low)/3;
        int cost1 = computeCost(arr,n,mid1);
        int cost2 = computeCost(arr,n,mid2);
        if(cost1<cost2) high = mid2;
        else low = mid2;
    }
    return computeCost(arr,n,(high+low)/2);
}

//uses ternary search
// if array is sorted take median as element need to be subtracted
int main(){
    int arr[] = { 1, 100, 101 };
    int N = sizeof(arr) / sizeof(int);
    cout << minCostToMakeElementEqual(arr, N);
    return 0;
}

