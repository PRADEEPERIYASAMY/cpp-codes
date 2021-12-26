#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void kSmallestPair(int arr1[],int n1,int arr2[],int n2,int k){
    if(n2*n2<k){
        cout<<"No such thing is possible";
        return;
    }
    
    int index2[n1];
    memset(index2,0,sizeof(index2));
    
    while(k>0){
        int minSum = INT_MAX;
        int minIndex = 0;
        
        for (int i = 0; i < n1; i++) {
            if(index2[i]< n2 && arr1[i]+arr2[index2[i]]< minSum){
                minSum = arr1[i]+arr2[index2[i]];
                minIndex = i;
            }
        }
        
        cout<<arr1[minIndex]<<" "<<arr2[index2[minIndex]]<<endl;
        index2[minIndex]++;
        k--;
    }
}

int main(){
    
    int arr1[] = {1, 3, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    int arr2[] = {2, 4, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int k = 4;
    kSmallestPair( arr1, n1, arr2, n2, k);
 
    return 0;
}

