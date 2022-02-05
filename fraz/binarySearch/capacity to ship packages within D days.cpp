#include <iostream>
using namespace std;

int shipWithinDays(vector<int>& weights, int D) {
    int left = *max_element(weights.begin(),weights.end());
    int right = accumulate(weights.begin(),weights.end(),0);
    int n = weights.size();
    while(left<right){
        int mid = left+(right - left)/2,needDay = 1,curLoad = 0;
        int i = 0;
        while(i<n && needDay<=D){
            if(curLoad+weights[i]>mid){
                needDay++;
                curLoad = 0;
            }
            curLoad +=weights[i++];
        }
        if(needDay>D) left = mid+1;
        else right = mid;
    }
    return left;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
	return 0;
}

