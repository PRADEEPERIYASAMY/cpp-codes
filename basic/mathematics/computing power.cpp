#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// recursive

// int power(int x, int n){
//     if(n == 0) return 1;
//     int temp = power(x,n/2);
//     temp*=temp;
//     if(n%2 == 0) return temp;
//     else return temp*x;
// }

// iterative

int power(int x,int n){
    int res = ;
    while(n){
        if(n%2 != 0) res*=x;
        x*=x;
        n/=2;
    }
    return res;
}

int main() {
    
    int x = 3, n = 5;
	cout<<power(x, n);
    return 0;
}

