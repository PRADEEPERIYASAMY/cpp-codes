#include<bits/stdc++.h>
using namespace std;

bool commpare(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int maxBridges(pair<int,int> arr[],int n){
    int lis[n];lis[0] = 1;
    sort(arr,arr+n,commpare);
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) if(arr[j].first <= arr[i].first) lis[i] = max(lis[i],1+lis[j]);
    }
    return *max_element(lis,lis+n);
}

int main() {
    struct pair<int,int> values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    int n = 4;
    cout << "Maximum number of bridges = "<< maxBridges(values, n);   
    return 0;
}

