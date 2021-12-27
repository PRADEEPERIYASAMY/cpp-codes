#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int modInverse(int a, int m){
    for(int i = 1;i<m;i++){
        if(a*i%m==1)
            return i;
    }
    return -1;
}

int main()
{
    long long a= 3;
    long long b= 11;
    cout << modInverse(a,b);
    return 0;
}

