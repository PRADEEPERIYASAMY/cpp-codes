#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// navie
// bool isPow2(int n){
//     if(n ==0) return true;
//     while(n != 1){
//         if(n%2 != 0) return false;
//         n/=2;
//     }
//     return true;
// }

// efficient

bool isPow2(int n){
    if(n == 0) return true;
    return (n&(n-1)) == 0;
}

int main() {
	int n = 4;
	printf("%s", isPow2(n)? "true": "false");
}

