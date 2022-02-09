#include <iostream>
using namespace std;

int subarraysWithAtMostKDistinct(vector<int> &A,int k){
    int i =0,res = 0;
    unordered_map<int,int> count;
    for (int j = 0; j < A.size(); j++) {
        if(!count[A[j]]++) --k;
        while(k<0) if(!--count[A[i++]]) ++k;
        res+=j - i+1;
    }
    return res;
}

int subarraysWithKDistinct(vector<int>& A, int K) {
    return subarraysWithAtMostKDistinct(A,K) - subarraysWithAtMostKDistinct(A,K-1);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/subarrays-with-k-different-integers/
	return 0;
}

