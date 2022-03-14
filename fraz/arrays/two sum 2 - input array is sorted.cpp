#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 1,j =numbers.size();
    while(i<j){
        int sum = numbers[i-1]+numbers[j-1];
        if(sum == target) return {i,j};
        else if(sum<target) i++;
        else j--;
    }
    return {};
}

int main() {
	// leetcode
	// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    return 0;
}
