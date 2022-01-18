using namespace std;
#include <bits/stdc++.h>

vector<string> solve(string str){
    vector<string> v;
    unordered_map<string,vector<pair<int,int>>> mp;
    int n = str.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n-i; j++) {
            string temp = str.substr(j,i);
            sort(temp.begin(),temp.end());
            mp[temp].emplace_back(make_pair(j, i));
        }
    }
    for( auto const &[key,val]:mp) if(val.size()>1) for (auto &p : val) v.push_back(str.substr(p.first,p.second));
    sort(v.begin(),v.end());
    return v;
}

int main(){
    vector<string> arr = solve("aba");
    for (auto &i : arr ) cout<<i<<" ";
    return 0;
}

