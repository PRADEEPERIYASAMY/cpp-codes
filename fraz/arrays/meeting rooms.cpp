#include <bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    if(intervals.empty()) return true;
    sort(intervals.begin(),intervals.end());
    for (int i = 1; i < intervals.size(); i++) if(intervals[i-1][1]>intervals[i][0]) return false;
    return true;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/meeting-rooms/
    return 0;
}
