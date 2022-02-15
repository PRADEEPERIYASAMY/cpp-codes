#include <iostream>
using namespace std;

// linear
// int kthFactor(int n,int k){
//     for (int i = 1; i <= n/2; i++) if(n%i == 0 && --k == 0)return i;
//     return k == 1?n:-1;
// }

// sqrt(n)
int kthFactor(int n, int k) {
    int d = 1;
    for (; d*d <= n; d++) if(n%d == 0 && --k == 0) return d;
    for (d = d-1; d >= 1; d--) {
        if(d*d == n) continue;
        if(n%d == 0 && --k == 0) return n/d;
    }
    return -1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/the-kth-factor-of-n/discuss/708099/C%2B%2BJava-Straightforward-%2B-Sqrt(n)
	return 0;
}


