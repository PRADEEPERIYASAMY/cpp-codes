#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void solution(int arr[],int n){
   int small[n],large[n];
   stack<int> st;
   for(int i = n-1;i>=0;i--){
      while(!st.empty() && arr[i]<= arr[st.top()]) st.pop();
      if(!st.empty()) small[i] = st.top();
      else small[i] = -1;
      st.push(i);
   }
   while(!st.empty()) st.pop();
   for(int i = n-1;i>=0;i--){
      while(!st.empty() && arr[i]>= arr[st.top()]) st.pop();
      if(!st.empty()) large[i] = st.top();
      else large[i] = -1;
      st.push(i);
   }
   for(int i=0;i<n;i++){
      if(large[i] != -1 && small[large[i]] != -1) cout<<arr[small[large[i]]]<<" ";
      else cout<<-1<<" ";
   }
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i =0;i<n;i++) cin>>arr[i];
   solution(arr,n);
   return 0;
}

