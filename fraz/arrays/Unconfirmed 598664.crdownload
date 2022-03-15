#include <bits/stdc++.h>
using namespace std;

int findCelebrity(int n) {
    int candidate = 0;
    for (int i = 0; i < n; i++) {
        if(i != candidate && knows(candidate,i)) candidate = i;
    }
    for (int i = 0; i < n; i++) {
        if(i != candidate && (knows(candidate,i)) || !(knows(i,candidate))) return -1;
    }
    return candidate;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/find-the-celebrity/
    return 0;
}
