#include <iostream>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
public:
    LRUCache(int capacity):cap(capacity) {
        m.reserve(cap);
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        int value = m[key]->second;
        l.erase(m[key]);
        l.push_front({key,value});
        m[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(m.count(key)) l.erase(m[key]);
        l.push_front({key,value});
        m[key] = l.begin();
        if(m.size()>cap){
            int delete_key = l.rbegin()->first;
            l.pop_back();
            m.erase(delete_key);
        }
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/lru-cache/
	return 0;
}

