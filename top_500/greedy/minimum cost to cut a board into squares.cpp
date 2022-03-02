#include <bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(int x[],int y[],int m,int n){
    int res = 0;
    sort(x,x+m,greater<int>());
    sort(y,+y+n,greater<int>());
    int hz = 1,vt = 1;
    int i = 0,j = 0;
    while(i<m && j<n){
        if(x[i]>y[j]){
            res+=x[i]*vt;
            hz++;
            i++;
        }else{
            res+=y[j]*hz;
            vt++;
            j++;
        }
    }
    int total = 0;
    while(i<m) total+=x[i++];
    res+=total*vt;
    total = 0;
    while(j<n) total+=y[j++];
    res+=total*hz;
    return res;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
	int m = 6, n = 4;
    int X[m-1] = {2, 1, 3, 1, 4};
    int Y[n-1] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m-1, n-1);
    return 0;
}

