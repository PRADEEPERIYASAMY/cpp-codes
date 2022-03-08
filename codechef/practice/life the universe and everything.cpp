#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long
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
    // https://www.codechef.com/problems/TEST
    cp();
    int t;
    while(cin>>t){
        if(t != 42) cout<<t<<endl;
        else break;
    }
    return 0;
}
