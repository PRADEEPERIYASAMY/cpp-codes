#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

int getFirstSetBitPos(int n){
    if(n == 0) return 0;
    return log2(n&(~(n-1)))+1;
}

int posOfRightMostDiffBit(int m,int n){
    return getFirstSetBitPos(m^n);
}

int main()
{
    int m = 52, n = 24;
    cout << "Position of rightmost different bit:"<< posOfRightMostDiffBit(m, n)<<endl;
    return 0;
}

