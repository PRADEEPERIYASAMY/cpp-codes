using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int minMoves(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    int min = *min_element(nums.begin(),nums.end());
    int n = nums.size();
    return sum - min*n;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/minimum-moves-to-equal-array-elements/ && https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question
    return 0;
}

