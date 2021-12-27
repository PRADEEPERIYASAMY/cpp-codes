#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// simple
// int countSetBits(int n){
//     int res = 0;
//     while(n){
//         if(n%2 == 0) res++;
//         n/=2;
//     }
//     return res;
// }

// brain and kerningham algo

int countSetBits(int n){
    int res = 0;
    while(n){
        n&=(n-1);
        res++;
    }
    return res;
}

int main() {
	int i = 9; 
	cout << countSetBits(i); 
	return 0; 
}

