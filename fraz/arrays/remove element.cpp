#include <bits/stdc++.h>
using namespace std;

// int removeElement(vector<int> &nums,int val){
//     int pos = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         if(nums[i] == val) continue;
//         nums[pos++] = nums[i];
//     }
//     return pos;
// }

int removeElement(vector<int> &nums,int val){
    int n = nums.size(),pos = n-1;
    for (int i = n-1; i >= 0; i--) if(nums[i] == val) swap(nums[i],nums[pos--]);
    return pos+1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-element/
    return 0;
}
