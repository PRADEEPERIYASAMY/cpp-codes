#include <iostream>
using namespace std;

int countDigitOne(int n) {
    int ones = 0;
    for (long long m = 1; m <= n; m*=10) {
        int a = n/m,b = n%m;
        ones+=(a+8)/10 * m+(a%10 == 1) *(b+1);
    }
    return ones;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/number-of-digit-one/discuss/64381/4%2B-lines-O(log-n)-C%2B%2BJavaPython
	return 0;
}

