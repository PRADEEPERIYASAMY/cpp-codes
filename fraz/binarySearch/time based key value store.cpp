#include <iostream>
using namespace std;

class TimeMap {
unordered_map<string,map<int,string>> mp;
public:
    TimeMap() {}
    void set(string key,string value,int timestamp){
        mp[key][timestamp] = value;
    }
    string get(string key,int timestamp){
        auto it = mp[key].upper_bound(timestamp);
        return it == mp[key].begin()?"":prev(it)->second;
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/create-maximum-number/
	return 0;
}

