#include <iostream>
using namespace std;

int gcd(int num1,int num2){
    while(num2!=0){
        int tmp = num2;
        num2 = num1%num2;
        num1 = tmp;
    }
    return num1;
}

int maxPoints(vector<vector<int>>& points) {
    map<pair<int,int>,int> slopes;
    int n = points.size(),res = 0;
    for (int i = 0; i <n; i++) {
        slopes.clear();
        int duplicates = 1;
        for (int j = i+1; j < n; j++) {
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                duplicates++;
                continue;
            }
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            int dvs = gcd(dx,dy);
            slopes[{dx/dvs,dy/dvs}]++;
        }
        res = max(res,duplicates);
        for (auto &i : slopes) res = max(res,i.second+duplicates);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-points-on-a-line/
	return 0;
}

