#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int countTrailingZeros(int n){
    int res = 0;
    for (int i = 5; i < n; i=i*5) res+=(n/i);
    return res;
}

int main() {
    
    int number = 251;
    cout<<countTrailingZeros(number);
    return 0;
}

