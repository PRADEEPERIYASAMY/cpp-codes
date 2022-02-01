#include <iostream>
using namespace std;

#define mod 1000000007

int knightDialer(int N) { 
    vector<vector<int>> neighbours({ {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4} });
    vector<long> count(10,1);
    for (int i = 0; i < N-1; i++) {
        vector<long> tmp(10,0);
        for (int j = 0; j < 10; j++) {
            for (auto &k : neighbours[j] ) {
                tmp[j] = (tmp[j]+count[k])%mod;
            }
        }
        count = tmp;
    }
    return accumulate(count.begin(),count.end(),(long)0)%mod; // initial value should be mande long else it will consider it as int, reslults in unexpected output for big numbers
}

int main() {
	// leetcode
	// https://leetcode.com/problems/knight-dialer/
	return 0;
}

