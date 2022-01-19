using namespace std;
#include <bits/stdc++.h>

int maxIndexDiff(int arr[],int n){
    int maxDiff,i,j;
    int Lmin[n],Rmax[n];
    Lmin[0] = arr[0];Rmax[n-1] = arr[n-1];
    for (int i = 1; i < n; i++) Lmin[i] = min(arr[i],Lmin[i-1]);
    for (int i = n-2; i >=0; i--) Rmax[i] = max(arr[i],Rmax[i+1]);
    i =0,j=0,maxDiff=-1;
    while(j<n&&i<n){
        if(Lmin[i]<=Rmax[j]){
            maxDiff = max(maxDiff,j-i);
            j+=1;
        }else i+=1;
    }
    return maxDiff;
}
int main(){
    int arr[] = { 9, 2, 3, 4, 5,6, 7, 8, 18, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    cout << maxDiff;
    return 0;
}

