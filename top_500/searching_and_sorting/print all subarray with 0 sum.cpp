using namespace std;
#include <bits/stdc++.h>

vector<pair<int,int>> findSubArrays(int arr[],int n){
    unordered_map<int,vector<int>> mp;
    vector<pair<int,int>> out;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+=arr[i];
        if(sum == 0) out.push_back({0,i});
        if(mp.find(sum)!= mp.end()){
            auto v = mp[sum];
            for (auto &j : v) out.push_back({j+1,i});
        }
        mp[sum].push_back(i);
    }
    return out;
}

void print(vector<pair<int,int>> out){
    for (auto &i : out) cout<<i.first<<" to "<<i.second<<"\n";
}

int main(){
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int, int> > out = findSubArrays(arr, n);
    if (out.size() == 0) cout << "No subarray exists";
    else print(out);
    return 0;
}

