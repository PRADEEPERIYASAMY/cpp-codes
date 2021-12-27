#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

void printSub(string str,string cur,int n){
    if(n == str.length()){
        cout<<cur<<" ";
        return;
    }
    
    printSub(str,cur+str[n],n+1);
    printSub(str,cur,n+1);
    
}

int main() {
	
	string str = "ABC";
    printSub(str, "", 0);
	return 0;
}

