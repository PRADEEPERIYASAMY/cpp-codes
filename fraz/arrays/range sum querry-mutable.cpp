#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> BIT;
public:
    NumArray(vector<int>& nums):BIT(nums.size()+1,0) {
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int index = i+1;
            while(index<BIT.size()){
                BIT[index]+=val;
                index +=(index&-index);
            }
        }
    }
    
    int getSum(int i){
        int sum = 0;
        int index = i+1;
        while(index>0){
            sum +=BIT[index];
            index -=(index&-index);
        }
        return sum;
    }
    
    void update(int i, int val) {
        int orig = getSum(i) - getSum(i-1);
        int diff = val - orig;
        int index = i+1;
        while(index<BIT.size()){
            BIT[index]+=diff;
            index+=(index&-index);
        }
    }
    
    int sumRange(int left, int right) {
        return getSum(right) - getSum(left-1);
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/range-sum-query-mutable/
    return 0;
}
