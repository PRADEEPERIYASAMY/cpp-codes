#include <iostream>
using namespace std;

// Binary Search - time limit exceeded
// vector<int> countSmaller(vector<int>& nums) {
//     vector<int> tmp,res(nums.size());
//     for (int i = nums.size()-1; i >= 0; i--) {
//         int left = 0,right = tmp.size();
//         while(left<right){
//             int mid = left + (right - left) / 2;
//             if(tmp[mid]>=nums[i]) right = mid;
//             else left = mid+1;
//         }
//         res[i] = left;
//         tmp.insert(tmp.begin()+left,nums[i]);
//     }
//     return res;
// }

// stl - time limit exceeded
// vector<int> countSmaller(vector<int> &nums){
//     vector<int> tmp,res(nums.size());
//     for (int i = nums.size()-1; i >= 0; i--) {
//         int d = distance(tmp.begin(),lower_bound(tmp.begin(),tmp.end(),nums[i]));
//         res[i] = d;
//         tmp.insert(tmp.begin()+d,nums[i]);
//     }
//     return res;
// }


// Build a binary search tree with an additional variable -- time limit exceeded
struct Node {
    int val, smaller;
    Node *left, *right;
    Node(int v, int s = 0) : val(v), smaller(s), left(nullptr), right(nullptr) {} 
};

int insert(Node*& root,int val){
    if(!root) {
        root = new Node(val);
        return 0;
    }else if(root->val>val){
        root->smaller++;
        return insert(root->left,val);
    }else return insert(root->right,val)+root->smaller+(val>root->val?1:0);
}

vector<int> countSmaller(vector<int> &nums){
    vector<int> res(nums.size(),0);
    Node *root = nullptr;
    for (int i = nums.size()-1; i>= 0; i--) res[i] = insert(root,nums[i]);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
	return 0;
}

