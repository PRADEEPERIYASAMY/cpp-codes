#include <bits/stdc++.h>
using namespace std;

void fillDepth(int parent[],int i,int depth[]){
    if(depth[i]) return;
    if(parent[i] == -1){
        depth[i] = 1;
        return;
    }
    if(depth[parent[i]] == 0) fillDepth(parent,parent[i],depth);
    depth[i] = depth[parent[i]]+1;
}

 int findHeight(int parent[],int n){
     int depth[n] = {0};
     for (int i = 0; i < n; i++) fillDepth(parent,i,depth);
     return *max_element(depth,depth+n);
 }

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/
    int parent[] = { -1, 0, 0, 1, 1, 3, 5 };
    int n = sizeof(parent) / sizeof(parent[0]);
    cout << "Height is " << findHeight(parent, n);
    return 0;
}

