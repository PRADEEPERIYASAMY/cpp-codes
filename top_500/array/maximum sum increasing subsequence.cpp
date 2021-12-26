#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int maxSumIS(int arr[],int n){
    int msis[n];
    copy(arr,arr+n,msis);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j<i; j++) {
            if(arr[i]>arr[j] && msis[i]<msis[j]+arr[i]) msis[i] = msis[j]+arr[i];
        }
    }
    
    return *max_element(msis,msis+n);
}

int main()
{
   int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum of maximum sum increasing "
            "subsequence is " << maxSumIS( arr, n ) << endl;
    return 0;
}

