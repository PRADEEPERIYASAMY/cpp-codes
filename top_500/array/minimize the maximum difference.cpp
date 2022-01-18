using namespace std;
#include <bits/stdc++.h>

int getMinDiff(int arr[],int n,int k){
    if(n == 1) return 0;
    sort(arr,arr+n);
    vector<pair<int,int>> t;
    map<int,int> mp;
    int c = 1;
    t.push_back({arr[0]-k,arr[0]});
    t.push_back({arr[0]+k,arr[0]});
    for (int i = 1; i < n; i++) {
        if(arr[i] != arr[i-1]){
            t.push_back({arr[i]-k,arr[i]});
            t.push_back({arr[i]+k,arr[i]});
            mp[arr[i]] = 0;
            c++;
        }
    }
    sort(t.begin(),t.end());
    int l = 0,r = 0;
    int ans =  t[t.size()-1].first - t[0].second;
    int count = 0;
    while(r<t.size()){
        while(r<t.size() && count <c){
            if(mp[t[r].second] == 0) count++;
            mp[t[r].second]++;r++;
        }
        if(r == t.size() && count<c) break;
        ans = min(ans,t[r-1].first-t[l].first);
        while(l<=r && count>= c){
            if(mp[t[l].second] == 1) count--;
            mp[t[l].second]--;
            ans = min(ans,t[r-1].first-t[l].first);
            l++;
        }
    }
    return ans;
}

int main(){
    int k = 5, n = 10;
    int arr[n] = { 8, 1, 5, 4, 7, 5, 7, 9, 4, 6 };
    cout << getMinDiff(arr, n, k);
    return 0;
}

