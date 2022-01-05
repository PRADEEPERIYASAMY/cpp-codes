#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin>>num;
	int n,prev = INT_MAX,count =0;
	while(num--){
		cin>>n;
		if(n<prev) count++;
		prev = n;
	}
	cout<<count;
}

