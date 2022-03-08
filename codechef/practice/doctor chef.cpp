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
    // https://www.codechef.com/problems/DRCHEF
    cp();
    int n,x;
    testcase{
        cin>>n>>x;
        vector<ll> arr(n);
        input(arr);
        sort(arr.begin(),arr.end());
        int res = 0;
        for (auto &i : arr) {
            if(i>x){
                while(i>x){
                    res++;
                    x*=2;
                }
                res++;
                x = 2*i;
            }else{
                if(2*i>x){
                    res++;
                    x = 2*i;
                }else res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
