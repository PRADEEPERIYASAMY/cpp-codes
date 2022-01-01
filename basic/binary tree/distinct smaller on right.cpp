#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node  { 
  int key; 
  struct Node *left; 
  struct Node *right;
  Node(int k){
      key=k;
      left=right=nullptr;
  }
};

int SmallerOnRight(int arr[],int n){
    int res = 0;
    set<int> s;
    for (int i = n-1; i >= 0; i--) {
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        int p = distance(s.begin(),it);
        res = max(res,p);
    }
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 2, 1};
    cout<<SmallerOnRight(arr,5);
    return 0;
}

