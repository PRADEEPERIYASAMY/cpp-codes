#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void sieve(int n){
    if(n<= 1) return;
    vector<bool> isPrime(n+1,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if(isPrime[i]){
            for (int j = i*2; j <= n; j+=i) isPrime[j] = false;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if(isPrime[i]) cout<<i<<" ";
    }
}

int main() {
    
    int n = 18;
    sieve(n);
    return 0;
}

