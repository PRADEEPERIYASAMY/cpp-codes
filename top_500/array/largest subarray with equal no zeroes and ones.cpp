using namespace std;
#include <bits/stdc++.h>

int maxLen(int arr[],int n){
    unordered_map<int,int> hm;
    int sum = 0,max_len = 0,ending_index = -1;
    for (int i = 0; i < n; i++) {
        sum = arr[i] == 1? sum+1:sum-1;
        if(sum == 0){
            max_len = i+1;
            ending_index = i;
        }
        if(hm.find(sum) != hm.end()){
            if(max_len<i-hm[sum]){
                max_len = i-hm[sum];
                ending_index=i;
            }else hm[sum] = i;
        }
    }
    cout<<ending_index - max_len+1<<" to "<<ending_index;
    return max_len;
}

int main(){
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    maxLen(arr, n);
    return 0;
}

