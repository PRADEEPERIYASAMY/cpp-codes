using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int count(int x,int y[],int n,int noy[]){
    if(x == 0)return 0;
    if(x == 1) return noy[0]; // no of zeroes in y
    int *idx = upper_bound(y,y+n,x);
    int ans = y+n- idx;
    ans+=(noy[0]+noy[1]);
    if(x == 2) ans-=(noy[3]+noy[4]);
    if(x == 3) ans+=noy[2];
    return ans;
}

int  countPairs(int x[],int y[],int m,int n){
    int noy[5]={0};
    for (int i = 0; i < n; i++) if(y[i]<5) noy[y[i]]++;
    sort(y,y+n);
    int total = 0;
    for (int i = 0; i < m; i++) total+=count(x[i],y,n,noy);
    return total;
}

int main(){
    int X[] = { 2, 1, 6 };
    int Y[] = { 1, 5 };
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
    cout << "Total pairs = " << countPairs(X, Y, m, n);
    return 0;
}

