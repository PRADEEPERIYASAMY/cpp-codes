#include <iostream>
using namespace std;

void helper(vector<double> &nums,const double &eps,bool &res){
    if(res) return;
    if(nums.size() == 1){
        if(abs(nums[0] - 24)<eps) res = true;
        return;
    }
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j <i; j++) {
            double p = nums[i],q = nums[j];
            vector<double> t({p+q,p - q,q - p,p*q});
            if(p>eps) t.push_back(q/p);
            if(q>eps) t.push_back(p/q);
            nums.erase(nums.begin()+i);
            nums.erase(nums.begin()+j);
            for (auto &i : t) {
                nums.push_back(i);
                helper(nums,eps,res);
                nums.pop_back();
            }
            nums.insert(nums.begin()+j,q);
            nums.insert(nums.begin()+i,p);
        }
    }
}

bool judgePoint24(vector<int>& nums) {
    vector<double> numArr(nums.begin(),nums.end());
    bool res = false;
    double eps = 1e-6;
    helper(numArr,eps,res);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/24-game/
	return 0;
}

