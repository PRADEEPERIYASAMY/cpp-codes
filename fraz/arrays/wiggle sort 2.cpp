#include <bits/stdc++.h>
using namespace std;

// naive
// void wiggleSort(vector<int>& nums) {
//     vector<int> tmp = nums;
//     sort(nums.begin(),nums.end());
//     int n = nums.size(),j = n,k = (n+1)/2;
//     for (int i = 0; i < n; i++) tmp[i] = (i&1)?nums[j--]:nums[k--];
//     nums = tmp;
// }

// virtual addressing and three way partitioning 
void wiggleSort(vector<int> &nums){
    int n = nums.size();
    auto midPtr = nums.begin()+n/2;
    nth_element(nums.begin(),midPtr,nums.end());
    int mid = *midPtr;
    #define A(i) nums[(2*i+1)%(n|1)]
    int i=0,j = 0,k = n-1;
    while(j<=k){
        if(A(j)>mid) swap(A(i++),A(j++));
        else if(A(j)<mid) swap(A(j),A(k--));
        else j++;
    }
}

int main() {
	// leetcode
	// https://leetcode.com/problems/wiggle-sort-ii/
	// https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
    return 0;
}
