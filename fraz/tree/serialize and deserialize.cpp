#include <iostream>
using namespace std;

// string serialize(TreeNode* root) {
//     if(!root) return "";
//     ostringstream os;
//     queue<TreeNode*> q({root});
//     while(!q.empty()){
//         auto t = q.front();q.pop();
//         if(!t) os<<"# ";
//         else{
//             os<<to_string(t->val)<<" ";
//             q.push(t->left);
//             q.push(t->right);
//         }
//     }
//     return os.str();
// }

// TreeNode* deserialize(string data) {
//     if(data.empty()) return nullptr;
//     istringstream is(data);
//     queue<TreeNode*> q;
//     string val;
//     is>>val;
//     TreeNode *res = new TreeNode(stoi(val)),*cur = res;
//     q.push(cur);
//     while(!q.empty()){
//         TreeNode *t = q.front();q.pop();
//         if(!(is>>val)) break;
//         if(val != "#"){
//             cur = new TreeNode(stoi(val));
//             q.push(cur);
//             t->left = cur;
//         }
//         if(!(is>>val)) break;
//         if(val != "#"){
//             cur = new TreeNode(stoi(val));
//             q.push(cur);
//             t->right = cur;
//         }
//     }
//     return res;
// }

void serialize(TreeNode *node,ostringstream &os){
    if(!node) os<<"# ";
    else{
        os<<to_string(node->val)<<" ";
        serialize(node->left,os);
        serialize(node->right,os);
    }
}

string serialize(TreeNode* root) {
    ostringstream os;
    serialize(root,os);
    return os.str();
}

TreeNode* deserialize(istringstream &is){
    string val;
    is>>val;
    if(val == "#") return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(is);
    root->right = deserialize(is);
    return root;
}

TreeNode* deserialize(string data) {
    istringstream is(data);
    return deserialize(is);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
	return 0;
}

