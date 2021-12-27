#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
// smart
// int digitalRoot(int n){
//     if(n ==0 )return 0;
//     if(n%9 == 0) return 9;
//     return n%9;
// }

// recursive

int digitalRoot(int n){
    if(n<10) return n;
    return digitalRoot(n%10+digitalRoot(n/10));
}

int main() {
	cout<<digitalRoot(9999);
    return 0;
}

