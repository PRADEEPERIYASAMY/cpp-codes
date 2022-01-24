using namespace std;
#include <bits/stdc++.h>

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0,high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid]>target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/binary-search/
    return 0;
}

