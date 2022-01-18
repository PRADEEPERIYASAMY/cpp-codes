using namespace std;
#include <bits/stdc++.h>

vector<int> solve(vector<int> &nums){
    int m = min(nums[0],nums[1]);
    nums[1] = nums[0];
    nums[0] = 0;
    for (int i = 2; i < nums.size(); i++) {
        int temp = m;
        m = min(m,nums[i]);
        nums[i] = temp;
    }
    return nums;
}

int main(){
    vector<int> arr = { 10, 5, 7, 9 }; 
    solve(arr);
    for (auto &i : arr ) cout<<i<<" ";
    return 0;
}

