#include <iostream>
using namespace std;

// One Pass
// void sortColors(vector<int>& nums) {
//     int left = 0,right = nums.size()-1;
//     for (int i = 0; i <= right; i++) {
//         if(nums[i] == 0 && i!=left) swap(nums[i--],nums[left++]);
//         else if(nums[i] == 2 && i!=right) swap(nums[i--],nums[right--]);
//     }
// }

void sortColors(vector<int>& nums) {
    int i = 0,j = 0,k = nums.size() -1;
    while(j<=k){
        if(nums[j] == 0) swap(nums[i++],nums[j++]);
        else if(nums[j] == 2) swap(nums[j],nums[k--]);
        else j++;
    }
}

int main() {
	// leetcode
	// https://leetcode.com/problems/sort-colors/
	return 0;
}

