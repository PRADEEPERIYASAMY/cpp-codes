using namespace std;
#include <bits/stdc++.h>

vector<int> maxSumOfThreeSubrrays(vector<int> &nums,int k){
    int n = nums.size(),maxSum = 0;
    vector<int> sum = {0},posLeft(n,0),posRight(n,n-1),ans(3,0);
    for (auto &i : nums) sum.push_back(sum.back()+i);
    for (int i = k,tot = sum[k]-sum[0]; i < n; i++) {
        if(sum[i+1]-sum[i+1-k]>tot){
            posLeft[i] = i+1-k;
            tot = sum[i+1]-sum[i+1+k];
        }else posLeft[i] = posLeft[i-1];
    }
    for (int i = n-k-1,tot = sum[n]-sum[n-k]; i>=0; i--) { //tot is >= unlike lefr
        if(sum[i+k]-sum[i]>=tot){
            posRight[i] = i;
            tot = sum[i+k]-sum[i];
        }else{
            posRight[i] = posRight[i+1];
        }
    }
    for (int i = k; i <= n-2*k; i++) {
        int l = posLeft[i-1],r = posRight[i+k];
        int tot = sum[i+k]-sum[i] + sum[l+k]-sum[l] + sum[r+k]-sum[r];
        if(tot>maxSum){
            maxSum = tot;
            ans = {l,i,r};
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,1,2,6,7,5,1};
    for (auto &i : maxSumOfThreeSubrrays(arr,2)) cout<<i<<" ";
    return 0;
}

