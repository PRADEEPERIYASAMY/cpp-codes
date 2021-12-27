#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// starts from k = 2

bool isLucky(int n,int k){
    if(n<k) return true;
    if(n%k == 0) return false;
    return isLucky(n-n/k,k+1);
}

int main() {
	cout<<isLucky(19,2);
    return 0;
}

