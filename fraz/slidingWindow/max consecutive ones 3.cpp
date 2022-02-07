#include <iostream>
using namespace std;

int longestOnes(vector<int>& A, int k) {
    int res = 0,zero_cnt = 0,begin = 0,end = 0;
    while(end<A.size()){
        if(A[end++] == 0) ++zero_cnt;
        if(zero_cnt>k && A[begin++] == 0) zero_cnt--;
        res = max(res,end - begin);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-consecutive-ones-iii/
	return 0;
}

