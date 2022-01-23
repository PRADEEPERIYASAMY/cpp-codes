using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int minSwapsToSort(int arr[],int n){
    pair<int,int> pos[n];
    for (int i = 0; i < n; i++) pos[i] = {arr[i],i};
    sort(pos,pos+n);
    vector<bool> vis(n,false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(vis[i] || pos[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while(!vis[j]){
            vis[j] = true;
            j = pos[j].second;
            cycle_size++;
        }
        ans+=(cycle_size-1);
    }
    return ans;
}

int minSwapToMakeArraySame(int a[],int b[],int n){
    map<int,int> mp;
    for (int i = 0; i < n; i++) mp[b[i]] = i;
    for (int i = 0; i < n; i++) b[i] = mp[a[i]];
    return minSwapsToSort(b,n);
}

int main(){
    int a[] = {3, 6, 4, 8};
    int b[] = {4, 6, 8, 3};
    int n = sizeof(a) / sizeof(int);
    cout << minSwapToMakeArraySame(a, b, n);
    return 0;
}

