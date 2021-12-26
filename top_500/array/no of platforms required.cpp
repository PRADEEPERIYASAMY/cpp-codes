#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// navie

// int findPlatform(int arr[],int dep[],int n){
//     int platNeeded = 1, res = 1;
    
//     for (int i = 0; i < n; i++) {
        
//         platNeeded = 1;
        
//         for (int j = i+1; j < n; j++) {
//             if((arr[i]>= arr[j] && arr[i]<= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])) platNeeded++;
//         }
        
//         res = max(res,platNeeded);
//     }
    
//     return res;
// }

// efficient

int findPlatform(int arr[],int dep[],int n){
    int platNeeded = 1,res = 1;
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i = 1,j = 0;
    
    while(i<n && j<n){
        if(arr[i]<= dep[j]){
            platNeeded++;
            i++;
        }else if(arr[i]> dep[j]){
            platNeeded--;
            j++;
        }
        
        res = max(res,platNeeded);
    }
    
    return res;
}

int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}

