#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

int nCr(int n,int r)
{
    if(r == 1) return n;
    if(r == n) return 1;
    return nCr(n-1,r-1)+nCr(n-1,r);
}

int main() {
	cout<<nCr(5,2)<<endl;
	return 0;
} 

