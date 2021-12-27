#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// using left shift
// void isKthBitSet(int n,int k){
//     if(n&(1<<(k-1))) cout<<"Set";
//     else cout<<"Not set";
// }

// using right shift

void isKthBitSet(int n,int k){
    if(n>>(k-1)&1) cout<<"Set";
    else cout<<"Not set";
}

int main() 
{ 
	int n = 5, k = 1; 
	isKthBitSet(n, k); 
	return 0; 
}
