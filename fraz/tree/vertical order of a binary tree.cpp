#include <iostream>
using namespace std;

// vector<vector<int>> verticalTraversal(TreeNode* root) {
//     vector<vector<int>> res;
//     if(!root) return res;
//     map<int,vector<pair<int,int>>> mp;
//     int x,y;
//     x = y = 0;
//     queue<pair<TreeNode*,pair<int,int>>> q;
//     q.push({root,{x,y}});
//     while(!q.empty()){
//         auto t = q.front();q.pop();
//         auto node = t.first;
//         auto p = t.second;
//         mp[p.first].push_back({p.second,node->val});
//         if(node->left) q.push({node->left,{p.first-1,p.second+1}});
//         if(node->right) q.push({node->right,{p.first+1,p.second+1}});
//     }
//     int n = mp.size();
//     res.resize(n);
//     int idx = 0;
//     for (auto &i : mp) {
//         auto &temp = i.second;
//         sort(temp.begin(),temp.end());
//         for (auto &x : temp) {
//             res[idx].push_back(x.second);
//         }
//         idx++;
//     }
//     return res;
// }

// changed set to multiset to accomodate duplicates
void helper(TreeNode *root,int x,int y,unordered_map<int,unordered_map<int,multiset<int>>> &mp){
    if(!root) return;
    mp[x][y].insert(root->val);
    helper(root->left,x-1,y+1,mp);
    helper(root->right,x+1,y+1,mp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    unordered_map<int,unordered_map<int,multiset<int>>> mp;
    helper(root,0,0,mp);
    for (int x = -999;x<=999;x++) {
        if(!mp.count(x)) continue;
        res.push_back(vector<int>());
        for (int y = 0; y < 1000; y++) {
            if(!mp[x].count(y)) continue;
            res.back().insert(res.back().end(),mp[x][y].begin(),mp[x][y].end());
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
	return 0;
}

