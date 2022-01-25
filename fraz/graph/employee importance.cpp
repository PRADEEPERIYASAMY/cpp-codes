using namespace std;
#include <bits/stdc++.h>

// bfs
// int getImportance(vector<Employee*> employees, int id) {
//     unordered_map<int,Employee*> mp;
//     for (auto &i : employees) mp[i->id] = i;
//     queue<int> q({id});
//     int res = 0;
//     while(!q.empty()){
//         auto t = mp[q.front()];q.pop();
//         res+=t->importance;
//         for (auto &i : t->subordinates) q.push(i);
//     }
//     return res;
// }

//dfs
void helper(unordered_map<int,Employee*> &mp,int id,int &res){
    if(!mp.count(id)) return;
    auto t = mp[id];
    for (auto &i : t->subordinates) helper(mp,i,res);
    res+= t->importance;
}

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int,Employee*> mp;
    for (auto &i : employees) mp[i->id] = i;
    int res =  0;
    helper(mp,id,res);
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/employee-importance/
    return 0;
}

