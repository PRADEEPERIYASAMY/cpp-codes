#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// Efficient Code with Sorted Order

// void printDivisors(int n){
//     int i =1;
    
//     for (i = 1; i*i < n; i++) if(n%i == 0) cout<<i<<" ";
//     for (; i >=1; i--) if(n%i == 0) cout<<n/i<<" ";
// }

// efficient codes

void printDivisors(int n){
    for (int i = 1; i*i <= n; i++){
        if(n%i == 0){
            cout<<i<<" ";
            if(i != (n/i)) cout<<n/i<<" ";
        }
    }
}

int main() {
    
    int n = 25;
    printDivisors(n);
    return 0;
}

