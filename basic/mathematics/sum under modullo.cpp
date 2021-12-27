#include <iostream>
using namespace std;
#include <bits/stdc++.h>

long long sumUnderModulo(long long a,long long b){
    long long m = 1000000007;
    return (a%m+b%m)%m;
}

int main()
{
    long long a= 9223372036854775807;
    long long b= 9223372036854775807;
    cout << sumUnderModulo(a,b);
    return 0;
}

