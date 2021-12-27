#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// recrusive

// int fact(int n){
//     if(n == 0) return 1;
//     return n*fact(n-1);
// }

// iterative

int fact(int n){
    int res = 1;
    while(n>1){
        res*=n;
        n--;
    }
    return res;
}

int main() {
    
    	int number = 5;
    	cout<<fact(number);
    	return 0;
}

