#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Nth_of_GP(int a,int r,int N){
    return (a*pow(r,N-1));
}

int main()
{
    int a = 2;
    int r = 3;
    int N = 5;
    cout << "The "<< N <<"th term of the series is : "<< Nth_of_GP(a, r, N);
    return 0;
}

