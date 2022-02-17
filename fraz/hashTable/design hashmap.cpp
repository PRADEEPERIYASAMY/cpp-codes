#include <iostream>
using namespace std;

class MyHashMap {
    vector<list<pair<int,int>>> mData;
    size_t s = 1000;
public:
    MyHashMap() {
        mData.resize(s);
    }
    
    void put(int key, int value) {
        auto &list = mData[key%s];
        for (auto &node : list) {
            if(node.first == key){
                node.second = value;
                return;
            }
        }
        list.emplace_back(key,value);
    }
    
    int get(int key) {
        const auto& list = mData[key%s];
        if(list.empty()) return -1;
        for (auto &node : list) {
            if(node.first == key) return node.second;
        }
        return -1;
    }
    
    void remove(int key) {
        auto &list = mData[key%s];
        for(auto it = list.begin();it != list.end();it++){
            if(it->first == key){
                list.erase(it);
                return;
            }
        }
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/design-hashmap/
	return 0;
}

