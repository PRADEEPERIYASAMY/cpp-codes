#include <iostream>
using namespace std;

// DFS + Hashmap + Hashset
// void buildParent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent){
//     if(!root) return;
//     if(root->left) parent[root->left] = root;
//     if(root->right) parent[root->right] = root;
//     buildParent(root->left,parent);
//     buildParent(root->right,parent);
// }

// void helper(TreeNode *root,int K,unordered_map<TreeNode*,TreeNode*> &parent,unordered_set<TreeNode*> &visited,vector<int> &res){
//     if(visited.find(root) != visited.end()) return;
//     visited.insert(root);
//     if(K == 0){
//         res.push_back(root->val);
//         return;
//     }
//     if(root->left) helper(root->left,K-1,parent,visited,res);
//     if(root->right) helper(root->right,K-1,parent,visited,res);
//     if(parent[root]) helper(parent[root],K-1,parent,visited,res);
// }

// vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//     unordered_map<TreeNode*,TreeNode*> parent;
//     unordered_set<TreeNode*> visited;
//     vector<int> res;
//     buildParent(root,parent);
//     helper(target,K,parent,visited,res);
//     return res;
// }

// BFS Level Order Traversal
void buildMap(TreeNode *root,TreeNode* pre,unordered_map<TreeNode*,vector<TreeNode*>> &mp){
    if(!root || mp.find(root) != mp.end()) return;
    if(pre){
        mp[root].push_back(pre);
        mp[pre].push_back(root);
    }
    buildMap(root->left,root,mp);
    buildMap(root->right,root,mp);
}

vector<int> distanceK(TreeNode* root,TreeNode *target,int K){
    if(!root) return{};
    unordered_map<TreeNode*,vector<TreeNode*>> mp;
    vector<int> res;
    queue<TreeNode*> q({target});
    unordered_set<TreeNode*> visited({target});
    buildMap(root,nullptr,mp);
    while(!q.empty()){
        if(K == 0){
            for (int i = q.size()-1; i >= 0; i--) {res.push_back(q.front()->val);q.pop();}
            break;
        }
        for (int i = q.size()-1; i >= 0; i--) {
            TreeNode *t = q.front();q.pop();
            for (auto &x : mp[t]) {
                if(visited.find(x)!= visited.end()) continue;
                q.push(x);
                visited.insert(x);
            }
        }
        K--;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/binary-tree-right-side-view/
	return 0;
}

