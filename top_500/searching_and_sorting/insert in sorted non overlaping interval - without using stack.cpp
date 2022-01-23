using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

bool overlap(pair<int,int> a,pair<int,int>b){
    return (min(a.second,b.second)>=max(a.first,b.first));
}

vector<pair<int,int>> mergeInterval2(pair<int,int> arr[],int n,pair<int,int> newPair){
    vector<pair<int,int>> ans;
    if(n == 0){
        ans.push_back(newPair);
        return ans;
    }
    if(newPair.second<arr[0].first || newPair.first>arr[n-1].second){
        if(newPair.second<arr[0].first) ans.push_back(newPair);
        for (int i = 0; i < n; i++) ans.push_back(arr[i]);
        if(newPair.first>arr[n-1].second) ans.push_back(newPair);
        return ans;
    }
    if(newPair.first<=arr[0].first && newPair.second>= arr[n-1].second){
        ans.push_back(newPair);
        return ans;
    }
    bool olp = true;
    for (int i = 0; i < n; i++) {
        olp = overlap(arr[i],newPair);
        if(!olp){
            ans.push_back(arr[i]);
            if(i<n && newPair.first > arr[i].second && newPair.second< arr[i+1].first) ans.push_back(newPair);
            continue;
        }
        pair<int,int> temp;
        temp.first = min(arr[i].first,newPair.first);
        while(i<n && olp){
            temp.second = max(newPair.second,arr[i].second);
            if(i == n-1) olp = false;
            else olp = overlap(arr[i+1],newPair);
            i++;
        }
        i--;
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    pair<int, int> arr2[] = {
        { 1, 2 }, { 3, 5 }, { 6, 7 },
                 { 8, 10 }, { 12, 16 }
    };
    pair<int, int> newPair{ 4, 9 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<pair<int,int>> ans = mergeInterval2(arr2, n2, newPair);
    for (auto &i : ans) cout<<i.first<<space<<i.second<<" --- ";
    return 0;
}

