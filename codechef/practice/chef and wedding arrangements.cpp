#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define um unordered_map
#define endl '\n'
#define input(a) \
    for (int i = 0; i < a.size(); i++) cin >> a[i];
#define output(a) \
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
#define testcase \
    int t;       \
    cin >> t;    \
    while (t--)

inline void cp() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



signed main() {
    // codechef
    // https://www.codechef.com/problems/CHEFWED
    cp();
    int n,k;
    testcase{
       cin>>n>>k;
       vi arr(n);
       input(arr);
       vi dp(n+1);
       dp[0] = 0;
       for (int i = 1; i <= n; i++) {
           dp[i] = dp[i-1]+k;
           um<int,int> mp;
           int clash = 0;
           for (int j = i; j >= 1; j--) {
               mp[arr[j-1]]++;
               if(mp[arr[j-1]] == 2) clash+=2;
               else if(mp[arr[j-1]]>2) clash+=1;
               dp[i] = min(dp[i],dp[j-1]+k+clash);
           }
       }
       cout<<dp[n]<<endl;
    }
    return 0;
}
