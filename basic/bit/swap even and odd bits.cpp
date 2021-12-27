#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

unsigned int swapBits(unsigned int x){
    unsigned int ev = x & 0xAAAAAAAA;
    unsigned int odd = x & 0X55555555;
    
    ev>>=1;
    odd<<=1;
    
    return ev|odd;
}

// navie

// unsigned int swapBits(unsigned int x)
// {
//     for(int i=0; i<32; i+=2){
//         int i_bit = ( x >> i ) & 1; // find i th bit
//         int i_1_bit = (x >> ( i+1 )) & 1;  // find i+1 th bit
        
//         x = x - ( i_bit << i) // remove i_bit
//               - ( i_1_bit << ( i+1 ) ) // remove i+1 th bit
//               + ( i_bit << ( i+1 ) ) // put i_bit at i+1 location
//               + ( i_1_bit << i );  // put i+1 bit at i location
//     }
//     return x;
// }

int main() { 
    unsigned int x = 23; // 00010111
    cout<<swapBits(x); 
    return 0; 
} 

