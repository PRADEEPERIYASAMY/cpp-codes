using namespace std;
#include <bits/stdc++.h>

int solve(int a){
    if(a == 1) return 1;
    int n = 1;
    while(a>1){
        if(a%n) return -1;
        a/=n;
        n++;
    }
    return a == 1?n-1:-1;
}

int main(){
    cout<<solve(6);
    cout<<endl;
    cout<<solve(10);
    return 0;
}

