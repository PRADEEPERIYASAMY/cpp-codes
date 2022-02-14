#include <iostream>
using namespace std;

class RandomizedCollection {
    vector<pair<int,int>> nums;
    unordered_map<int,vector<int>> mp;
public:
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        bool result = (mp.count(val) == 0);
        mp[val].push_back(nums.size());
        nums.push_back({val,mp[val].size()-1});
        return result;
    }
    
    bool remove(int val) {
        bool result = (mp.count(val)!=0);
        if(result){
            auto[f,s] = nums.back();
            mp[f][s] = mp[val].back();
            nums[mp[val].back()] = {f,s};
            mp[val].pop_back();
            if(mp[val].empty()) mp.erase(val);
            nums.pop_back();
        }
        return result;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()].first ;
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
	return 0;
}

