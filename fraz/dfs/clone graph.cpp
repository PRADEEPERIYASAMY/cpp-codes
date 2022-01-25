using namespace std;
#include <bits/stdc++.h>

//bfs
// Node* cloneGraph(Node* node) {
//     if(!node) return nullptr;
//     unordered_map<Node*,Node*> mp;
//     Node* copy = new Node(node->val,vector<Node*>());
//     mp[node] = copy;
//     queue<Node*> q({node});
//     while(!q.empty()){
//         auto cur = q.front();q.pop();
//         for (auto &i : cur->neighbors) {
//             if(!mp.count(i)){
//                 Node *newNode = new Node(i->val,vector<Node*>());
//                 mp[i] = newNode;
//                 q.push(i);
//             }
//             mp[cur]->neighbors.push_back(mp[i]);
//         }
//     }
//     return copy;
// }

//dfs
Node* helper(Node* node, unordered_map<Node*, Node*>& mp){
    if(!node) return nullptr;
    if(mp.count(node)) return mp[node];
    Node* newNode = new Node(node->val,vector<Node*>());
    mp[node] = newNode;
    for (auto &i : node->neighbors) {
        newNode->neighbors.push_back(helper(i,mp));
    }
    return newNode;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*,Node*> mp;
    return helper(node,mp);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/clone-graph/
    return 0;
}

