#include <bits/stdc++.h>
using namespace std;

void printString(int n){
    string str;
    while(n>0){
        int rem = n%26;
        if(rem == 0){
            str.push_back('Z');
            n = (n/26)-1;
        }else{
            str.push_back(rem - 1 +'A');
            n = n/26;
        }
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-excel-column-name-given-number/
	printString(26);
    printString(51);
    printString(52);
    printString(80);
    printString(676);
    printString(702);
    printString(705);
    return 0;
}

