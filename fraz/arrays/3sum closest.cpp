using namespace std;
#include <bits/stdc++.h>

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n = nums.size(),res = nums[0]+nums[1]+nums[2];
    for (int i = 0; i < n; i++) {
        int l = i+1,r = n-1;
        while(l<r){
            int cur = nums[i]+nums[l]+nums[r];
            if(abs(cur-target)<abs(res-target)) res = cur;
            else if(cur<target) l++;
            else r--;
        }
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/3sum-closest/
    return 0;
}

