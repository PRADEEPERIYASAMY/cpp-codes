using namespace std;
#include <bits/stdc++.h>

class RandomizedSet {
    vector<int> nums;
    unordered_map<int,int> m;
public:
    
    RandomizedSet(){
        srand(time(NULL));
    }
    bool insert(int val){
        if(m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size()-1;
        return true;
    }
    bool remove(int val){
        if(!m.count(val)) return false;
        int last = nums.back();
        if(last != val){
            m[last] = m[val];
            nums[m[val]] = last;
        }
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom(){
        return nums[rand()%nums.size()];
    }
};

int main(){
    //leet code solutions
    //https://leetcode.com/problems/insert-delete-getrandom-o1/
    return 0;
}

