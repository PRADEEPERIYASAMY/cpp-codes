#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// fib using memorization - top-down - recursive optimization
// int memo[1000000];
// int fib(int n){
//     if(n == 1 || n == 0) return n;
//     if(memo[n] == -1){
//         memo[n] = fib(n-1)+fib(n-2);
//     }
//     return memo[n];
// }

// fib using tabulation - bottom - up

int fib(int n){
    int tab[n+1];
    tab[0] = 0;
    tab[1] = 1;
    for (int i = 2; i <= n; i++) {
        tab[i] = tab[i-1]+tab[i-2];
    }
    
    return tab[n];
}

int main() {
    //memset(memo,-1,sizeof(memo));
    cout<<fib(20);
    return 0;
}
