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
    // https://www.codechef.com/problems/ADAKING
    cp();
    int k;
    testcase{
        cin>>k;
        vector<string> board(8,string(8,'X'));
        int count = 0;
        for (auto &row : board) {
            for (auto &cell : row) {
                cell = '.';
                count++;
                if(count == k) break;
            }
            if(count == k) break;
        }
        board[0][0] = 'O';
        for (auto &row : board) cout<<row<<endl;
        cout<<endl;
    }
    return 0;
}
