using namespace std;
#include <bits/stdc++.h>

int peakIndexInMountainArray(vector<int>& A) {
    int l = 0,r = A.size()-1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(A[mid]<A[mid+1]) l = mid+1;
        else r = mid;
    }
    return l;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/peak-index-in-a-mountain-array/
    return 0;
}

