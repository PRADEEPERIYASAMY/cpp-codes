#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool isPal(int n){
    int rev = 0;
    int temp = n;
    while(temp){
        rev=(rev*10)+(temp%10);
        temp/=10;
    }
    
    return rev == n;
}

int main() {
    	int number = 4554;
    	cout<<(bool)isPal(number);
    	return 0;
}

