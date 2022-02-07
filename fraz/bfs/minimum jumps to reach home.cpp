#include <iostream>
using namespace std;

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> forbi(forbidden.begin(),forbidden.end());
    vector<vector<int>> visited(2,vector<int>(6000,0));
    queue<pair<int,bool>> q; // bool to check weather the last step is backward
    q.push({0,false});
    visited[0][0] = 1;
    visited[1][0] = 1;
    int ans = 0;
    while(!q.empty()){
        int len = q.size();
        while(len--){
            auto[cur,flag] = q.front();q.pop();
            if(cur == x) return ans;
            int forward = cur+a;
            int backward = cur - b;
            if(forward<6000 && !visited[0][forward] && !forbi.count(forward)){
                q.push({forward,false});
                visited[0][forward] = 1;
            }
            if(backward>= 0 && !visited[1][backward] && !forbi.count(backward) && !flag){
                q.push({backward,true});
                visited[1][backward] = 1;
            }
        }
        ans++;
    }
    return-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-jumps-to-reach-home/discuss/935384/C%2B%2B-BFS
	return 0;
}

