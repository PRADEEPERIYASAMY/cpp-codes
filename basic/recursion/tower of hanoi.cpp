#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

void ToH(int n, char A,char B,char C){
    if(n == 1){
        cout<<"moves 1 from A to C"<<endl;
        return;
    }
    ToH(n-1,A,C,B);
    cout<<"moves "<<n<<" from A to C"<<endl;
    ToH(n-1,B,A,C);
}

int main() {
	
	int n = 2; 
    ToH(n, 'A', 'B', 'C'); 
	return 0;
}

