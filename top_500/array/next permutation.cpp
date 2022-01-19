using namespace std;
#include <bits/stdc++.h>

void nextPermutation(vector<int> &nums){
    int n = nums.size(),k = n-2,l=n-1;
    while(k>=0 && nums[k+1]<=nums[k]) k--;
    if(k>= 0){
        while(nums[l]<=nums[k]) l--;
        swap(nums[k],nums[l]);
    }
    reverse(nums.begin()+k+1,nums.end());
}

int main(){
    vector<int> arr {1,2,3};
    nextPermutation(arr);
    for (auto &i : arr) cout<<i<<" ";
    return 0;
}

