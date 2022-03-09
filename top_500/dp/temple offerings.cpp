#include <bits/stdc++.h>
using namespace std;

struct temple{
    int l,r;
};

int offeringNumber(int n,int temleHeights[]){
    vector<temple> chainSize(n);
    for (int i = 0; i < n; i++) chainSize[i].l = chainSize[i].r = -1;
    chainSize[0].l = 1;
    chainSize[n-1].r= 1;
    for (int i = 1; i < n; i++) {
        if(temleHeights[i-1]<temleHeights[i]) chainSize[i].l = chainSize[i-1].l+1;
        else chainSize[i].l = 1;
    }
    for (int i = n-2; i >= 0; i--) {
        if(temleHeights[i+1]<temleHeights[i]) chainSize[i].r = chainSize[i+1].r+1;
        else chainSize[i].r = 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum+=max(chainSize[i].l,chainSize[i].r);
    return sum;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/temple-offerings/
	int arr1[3] = { 1, 2, 2 };
    cout << offeringNumber(3, arr1) << "\n";
    int arr2[6] = { 1, 4, 3, 6, 2, 1 };
    cout << offeringNumber(6, arr2) << "\n";
    return 0;
}
