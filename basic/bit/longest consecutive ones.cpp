#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// https://media.geeksforgeeks.org/wp-content/uploads/sparseMatrix.jpg

int maxConsecutiveOnes(int x){
    int count = 0;
    while(x){
        x=(x&(x<<1));
        count++;
    }
    return count;
    
}

int main()
{
    cout << maxConsecutiveOnes(14) << endl;
    cout << maxConsecutiveOnes(222) << endl;
    return 0;
}

