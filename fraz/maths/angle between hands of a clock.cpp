#include <iostream>
using namespace std;

double angleClock(int hour, int minutes) {
    double hourAngle = (hour%12)*30+minutes*0.5;
    double minumteAngle = minutes*6;
    double diff = abs(hourAngle - minumteAngle);
    return min(diff,360 - diff);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/angle-between-hands-of-a-clock/discuss/735414/C%2B%2B-or-Easy-with-explanation
	return 0;
}

