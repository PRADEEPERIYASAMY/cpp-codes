using namespace std;
#include <bits/stdc++.h>

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    for (int i = n-2; i >= 0; i--) {
        if(nums[i]<nums[i+1]){
            int j;
            for (j = n-1; j > i; j--) if(nums[j]>nums[i]) break;
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
            return;
        }
    }
    reverse(nums.begin(),nums.end());
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/next-permutation/
    return 0;
}

