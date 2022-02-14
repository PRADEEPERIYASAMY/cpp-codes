#include <iostream>
using namespace std;

string minWindow(string s, string t) {
    vector<int> count(128,0);
    for (auto &c : t) count[c]++;
    int begin = 0,end = 0,head = 0,d = INT_MAX,counter = t.size();
    while(end<s.size()){
        if(count[s[end++]]-->0) counter--;
        while(counter == 0){
            if(end - begin<d){
                head = begin;
                d = end - begin;
            }
            if(count[s[begin++]]++ == 0) counter++;
        }
    }
    return d == INT_MAX?"":s.substr(head,d);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-window-substring/
	return 0;
}

