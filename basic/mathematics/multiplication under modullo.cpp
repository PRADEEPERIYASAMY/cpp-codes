#include <iostream>
using namespace std;
#include <bits/stdc++.h>

long long mulUnderModulo(long long a,long long b){
    long long m = 1000000007;
    return ((a%m)*(b%m))%m;
}

int main()
{
    long long a= 92233720368547758;
    long long b= 92233720368547758;
    cout << mulUnderModulo(a,b);
    return 0;
}

