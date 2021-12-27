#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

void permutate(string str,int n){
    if(n == str.length()-1){
        cout<<str<<" "<<endl;
        return;
    }
    
    for (int i = n; i < str.length(); i++) {
        swap(str[n],str[i]);
        permutate(str,n+1);
        swap(str[n],str[i]);
    }
}

int main() {
	permutate("abcd",0);
    return 0;
}

