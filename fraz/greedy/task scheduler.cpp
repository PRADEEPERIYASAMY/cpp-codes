#include <iostream>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> coutn(26,0);
    int mx = 0,max_count = 0;
    for (auto &i : tasks) {
        coutn[i-'A']++;
        if(mx == coutn[i-'A']) max_count++;
        else if(mx < coutn[i-'A']){
            mx = coutn[i-'A'];
            max_count = 1;
        }
    }
    return max((int)tasks.size(),(mx-1)*(n+1)+max_count);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/task-scheduler/
	return 0;
}

