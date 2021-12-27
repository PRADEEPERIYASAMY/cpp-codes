#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// for large values

// long long findDigits(int n){
//     if(n<0) return 0;
//     if(n<= 1) return 1;
//     double x = (n*log10(n/M_E)+log10(2*M_PI*n)/2);
//     return floor(x)+1;
// }

// for large values

long long findDigits(int n){
    if(n<0) return 0;
    if(n<= 1) return 1;
    double x = 0;
    for (int i = 2; i <=n ; i++) x+=log10(i);
    return floor(x)+1;
}


int main()
{
    cout << findDigits(1) << endl;
    cout << findDigits(5) << endl;
    cout << findDigits(10) << endl;
    cout << findDigits(120) << endl;
    
    return 0;
    
}

