#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
//#define int long long
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
    // https://www.codechef.com/problems/PTMSSNG
    cp();
    int n;
    testcase{
        cin>>n;
        um<int,int> x,y;
        int a,b;
        for (int i = 0; i < 4*n-1; i++) {
            cin>>a>>b;
            x[a]++,y[b]++;
        }
        pair<int,int> ans;
        for (auto [first,second] : x) if(second &1){ans.first = first;break;}
        for (auto [first,second] : y) if(second &1){ans.second = first;break;}
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
