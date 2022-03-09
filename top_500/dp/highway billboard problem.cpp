#include <bits/stdc++.h>
using namespace std;

int maxRevenue(int m,int x[],int revenue[],int n,int t){
    int maxRev[m+1] = {0};
    int nxtBB = 0;
    for (int i = 1; i <= m; i++) {
        if(nxtBB<n){
            if(x[nxtBB] != i) maxRev[i] = maxRev[i-1];
            else{
                if(i<=t) maxRev[i] = (maxRev[i-1],revenue[nxtBB]);
                else maxRev[i] = max(maxRev[i-t-1]+revenue[nxtBB],maxRev[i-1]);
                nxtBB++;
            }
        }else maxRev[i] = maxRev[i-1];
    }
    return maxRev[m];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/highway-billboard-problem/
	int m = 20;
    int x[] = {6, 7, 12, 13, 14};
    int revenue[] = {5, 6, 5, 3, 1};
    int n = sizeof(x)/sizeof(x[0]);
    int t = 5;
    cout << maxRevenue(m, x, revenue, n, t) << endl;
    return 0;
}
