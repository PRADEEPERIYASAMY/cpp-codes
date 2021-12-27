#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// https://media.geeksforgeeks.org/wp-content/uploads/sparseMatrix.jpg

int greyConverter(int n){
    return n^(n>>1);
}

int greytoBinary(int n){
    int inv =0;
    while(n){
        inv^=n;
        n>>=1;
    }
    
    return inv;
}

int main()
{
    int n = 3;
    cout << greyConverter(n) << endl;
    n = 9;
    cout << greyConverter(n) << endl;
    
    n = 15;
    cout << greytoBinary(n) << endl;
    
    return 0;
}

