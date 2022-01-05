#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int calc(int arr[],int n){
	int res = 0;
	stack<int> st;
	st.push(arr[0]);
	for(int i = 1;i<n;i++){
		if(st.top()>arr[i]) res++;
		else{
			while(!st.empty()) st.pop();
			st.push(arr[i]);
		}
	}
	while(!st.empty()) st.pop();
	st.push(arr[n-1]);
	for(int i = n-2;i>=0;i--){
		if(st.top()>arr[i]) res++;
		else{
			while(!st.empty()) st.pop();
			st.push(arr[i]);
		}
	}
	return res;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++) cin>>arr[i];
	cout<<calc(arr,n);
	return 0;
}

