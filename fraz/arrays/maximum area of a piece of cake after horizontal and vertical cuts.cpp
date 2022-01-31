#include <iostream>
using namespace std;

int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
    sort(hCuts.begin(),hCuts.end());
    sort(vCuts.begin(),vCuts.end());
    int max_h = max(hCuts[0],h - hCuts.back());
    int max_v = max(vCuts[0],w- vCuts.back());
    for (int i = 0; i < hCuts.size()-1; i++) max_h = max(max_h,hCuts[i+1]- hCuts[i]);
    for (int i = 0; i < vCuts.size()-1; i++) max_v = max(max_v,vCuts[i+1]- vCuts[i]);
    return (int)((long)max_h * max_v % 1000000007);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/661644/C%2B%2BJava-Maximum-Gap-Between-Cuts
	return 0;
}

