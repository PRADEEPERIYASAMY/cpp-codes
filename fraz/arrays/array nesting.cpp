#include <bits/stdc++.h>
using namespace std;

// int arrayNesting(vector<int>& nums) {
//     if(nums.empty()) return 0;
//     int n = nums.size(),res = 0;
//     vector<bool> visited(n,false);
//     for (int i = 0; i < n; i++) {
//         if(visited[i]) continue;
//         int cnt = 0,j = i;
//         while(cnt == 0 || j!=i){
//             visited[j] = true;
//             j = nums[j];
//             cnt++;
//         }
//         res = max(res,cnt);
//     }
//     return res;
// }

// space optimized
int arrayNesting(vector<int> &nums){
    int n = nums.size(),res = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while(nums[i] != i && nums[i] != nums[nums[i]]) {
            swap(nums[i],nums[nums[i]]);
            cnt++;
        }
        res = max(res,cnt);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/array-nesting/
    return 0;
}
