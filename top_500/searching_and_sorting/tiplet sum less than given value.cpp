using namespace std;
#include <bits/stdc++.h>

int countTriplets(int arr[],int n,int sum){
    sort(arr,arr+n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i+1,k = n-1;
        while(j<k){
            int x  = arr[i]+arr[j]+arr[k];
            if(x>=sum) k--;
            else{
                ans+=(k-j);
                j++;
            }
        }
    }
    return ans;
}

int main(){
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof arr / sizeof arr[0];
    int sum = 12;
    cout << countTriplets(arr, n, sum) << endl;
    return 0;
}

