#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int countDigits(int n){
    int count = 0;
    while(n){
        count++;
        n/=10;
    }
    return count;
}

int main() {
    
    	int number = 789;
    	cout<<countDigits(number);
    	return 0;
}

