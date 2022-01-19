using namespace std;
#include <bits/stdc++.h>

int longSubarrWthSumDivByK(int arr[],int n,int k){
    unordered_map<int,int> hm;
    int m = 0,cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum+=arr[i];
        int mod = cur_sum%k;
        if(mod == 0) m = i+1;
        else if(hm.find(mod) == hm.end()) hm[mod] = i;
        else m = max(m,i- hm[mod]);
    }
    return m;
}

int main(){
    int arr[] = { 2, 7, 6, 1, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "Length = "<< longSubarrWthSumDivByK(arr, n, k);
    return 0;
}

