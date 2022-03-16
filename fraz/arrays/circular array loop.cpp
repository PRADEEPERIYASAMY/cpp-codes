#include <bits/stdc++.h>
using namespace std;

int getNextIdx(int i,const vector<int> &nums){
    int n = nums.size();
    return ((i+nums[i])%n+n)%n;
}

bool circularArrayLoop(vector<int> &nums){
    if(nums.empty()) return false;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int slow = i,fast = getNextIdx(i,nums);
        while(nums[fast]*nums[i]>0 && nums[getNextIdx(fast,nums)]*nums[i]>0){
            if(slow == fast) {
                if(slow == getNextIdx(slow,nums)) break;
                return true;
            }
            slow = getNextIdx(slow,nums);
            fast = getNextIdx(getNextIdx(fast,nums),nums);
        }
        slow = i;
        while(nums[slow]*nums[i]>0){
            int next = getNextIdx(slow,nums);
            nums[slow] = 0;
            slow = next;
        }
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/circular-array-loop/
    return 0;
}
