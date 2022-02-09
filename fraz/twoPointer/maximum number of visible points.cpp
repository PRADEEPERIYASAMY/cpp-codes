#include <iostream>
using namespace std;
#define PI 3.14159265
#define MARGIN 1e-9

double getAngle(int x,int y){
    return atan2(y,x)*180/ PI;
}

int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    int i,j,n = points.size(),common = 0;
    vector<double> vals;
    for (int i = 0; i < n; i++) {
        int x = points[i][0] - location[0];
        int y = points[i][1] - location[1];
        if(x == 0 && y == 0) common++;
        else{
            double A = getAngle(x,y);
            if(A<0) A+=360;
            vals.emplace_back(A);
        }
    }
    sort(vals.begin(),vals.end());
    vector<double> a = vals;
    a.insert(a.end(),vals.begin(),vals.end());
    for (int i = vals.size(); i < a.size(); i++) a[i]+=360;
    int res = 0;
    for (int i = 0,j = 0; i < a.size(); i++) {
        while(j<a.size() && (a[j]-a[i]<=angle+MARGIN)) j++;
        res = max(res,j - i);
    }
    return res+common;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-number-of-visible-points/discuss/877735/C%2B%2B-Clean-with-Explanation
	return 0;
}

