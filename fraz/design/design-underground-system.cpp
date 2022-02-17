#include <iostream>
using namespace std;

class UndergroundSystem {
    unordered_map<string,pair<int,int>> checkout;
    unordered_map<int,pair<string,int>> checkin; 
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto[startStation,startTime] = checkin[id];
        string route = startStation+"_"+stationName;
        int totalTime = t - startTime;
        checkout[route].first += totalTime;
        checkout[route].second +=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"_"+endStation;
        auto &t = checkout[route];
        return (double)t.first/t.second;
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/design-underground-system/discuss/554879/JavaC%2B%2B-HashMap-and-Pair-Clean-code-O(1)
	return 0;
}

