#include <iostream>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for (int i = 0; i < n-3; i++) {
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
        if ((i > 0 && nums[i] == nums[i - 1]) || (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)) continue;
        for (int j = i+1; j < n-2; j++) {
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
           if ((j > i + 1 && nums[j] == nums[j - 1]) || (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)) continue;
            int k = j+1, l = n-1;
            while(k<l){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum == target){
                    res.push_back(vector<int>({nums[i],nums[j],nums[k],nums[l]}));
                    while(k<l && nums[k] == nums[k+1]) k++;
                    while(k<l-1 && nums[l] == nums[l-1])l--;
                    k++,l--;
                }
                else if(sum < target){
                    while(k<l && nums[k] == nums[k+1]) k++;
                    k++;
                }
                else{
                    while(k<l-1 && nums[l] == nums[l-1])l--;
                    l--;
                }
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/4sum/
	return 0;
}

