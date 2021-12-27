#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// n&(~(n-1)) gives righmost bit set number eg 10100 -> 100
// int getFirstSetBitPos(int n){
//     return log2(n&(~(n-1)))+1;
// }

// normal

int getFirstSetBitPos(int n){
    int res = 1;
    while(n){
        if(n&1) return res;
        res++;
        n>>=1;
    }
    
    return -1;
}

int main()
{
    int n = 12;
    cout << getFirstSetBitPos(n);
    return 0;
}

