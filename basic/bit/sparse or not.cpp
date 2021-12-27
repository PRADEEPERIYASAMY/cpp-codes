#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// https://media.geeksforgeeks.org/wp-content/uploads/sparseMatrix.jpg

bool checkSparse(int n){
    if(n&(n>>1)) return false;
    return true;
}

int main()
{
    cout << checkSparse(72) << endl;
    cout << checkSparse(12) << endl;
    cout << checkSparse(2) << endl;
    cout << checkSparse(3) << endl;
    return 0;
}

