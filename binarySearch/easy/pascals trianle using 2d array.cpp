using namespace std;
#include <bits/stdc++.h>

vector<int> solve(int n){
    vector<vector<int>> ans;
    ans.push_back({1});
    ans.push_back({1,1});
    if(n == 0) return {1};
    if( n == 1) return {1,1};
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        res.push_back(1);
        for (int j = 1; j < i; j++) res.push_back(ans[i-1][j-1]+ans[i-1][j]);
        res.push_back(1);
        ans.push_back(res);
        res.clear();
    }
    return ans[n];
}

int main(){
    for (auto &i : solve(3)) cout<<i<<" ";
    return 0;
}

