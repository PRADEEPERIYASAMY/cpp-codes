#include <iostream>
using namespace std;

// Hashmap + greedy + heap
// string reorganizeString(string S) { 
//     int len = S.size();
//     vector<int> count(26,0);
//     for (auto &i : S) {
//         if(count[i-'a']>(len+1)/2) return "";
//         count[i-'a']++;
//     }
//     priority_queue<pair<int,char>> pq;
//     for (int i = 0; i < 26; i++) {
//         if(!count[i]) continue;
//         pq.push({count[i],(char)('a'+i)});
//     }
//     string res;
//     while(!pq.empty()){
//         auto t = pq.top();pq.pop();
//         if(res.empty() || t.second != res[res.size()-1]){
//             res+=t.second;
//             if(--t.first>0) pq.push(t);
//         }else if(!pq.empty()){
//             auto u = pq.top();pq.pop();
//             res+=u.second;
//             if(--u.first>0) pq.push(u);
//             pq.push(t);
//         }else{
//             return "";
//         }
//     }
//     return res;
// }

// Hashmap + greedy + heap
string reorganizeString(string S) {
    vector<int> count(26,0);
    for (auto &i : S) if(++count[i-'a']> (S.size()+1)/2) return "";
    priority_queue<pair<int,char>> pq;
    for (int i = 0; i < 26; i++) {
        if(!count[i]) continue;
        pq.push({count[i],(char)('a'+i)});
    }
    string res;
    while(pq.size()>=2){
        auto t = pq.top();pq.pop();
        auto u = pq.top();pq.pop();
        res.push_back(t.second);
        res.push_back(u.second);
        if(--t.first>0) pq.push(t);
        if(--u.first>0) pq.push(u);
    }
    if(!pq.empty()) res.push_back(pq.top().second);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reorganize-string/
	return 0;
}

