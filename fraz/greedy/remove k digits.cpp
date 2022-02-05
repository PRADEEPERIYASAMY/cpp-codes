#include <iostream>
using namespace std;

string removeKdigits(string num, int k) {
    string res;
    int n = num.size(),keep = n-k;
    for (auto &c : num) {
        while(k && !res.empty() && res.back()>c) res.pop_back(),k--;
        res.push_back(c);
    }
    res.resize(keep);
    while(!res.empty() && res[0] == '0') res.erase(res.begin());
    return res.empty()?"0":res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-k-digits/
	return 0;
}

