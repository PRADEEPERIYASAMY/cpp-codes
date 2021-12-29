#include <iostream>
using namespace std;

void bonacciseries(int n,int m){
    int a[m] = {0};
    a[n-1] = 1;
    a[n] = 1;
    
    for (int i = n+1; i < m; i++) a[i] = 2*a[i-1]-a[i-1-n];
    for (int i = 0; i < m; i++) cout<< a[i]<<" ";
}

int main() {
	int N = 5, M = 15; 
	bonacciseries(N, M); 
	return 0;
}

