#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

int main() {
    
    int a = 4, b = 6;
    cout<<lcm(a, b);
    return 0;
}

