#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1,1);
    for (int i = 2; i <= rowIndex; i++) {
        for (int j = i-1; j >=1; j--) res[j]+=res[j-1];
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/pascals-triangle-ii/
    return 0;
}
