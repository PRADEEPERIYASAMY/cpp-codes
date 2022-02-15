#include <iostream>
using namespace std;

class Solution {
    unordered_map<string,string> short2Long,long2Short;
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    
    Solution(){
        short2Long.clear();
        long2Short.clear();
        srand(time(NULL));
    }
    
    string encode(string longUrl) {
        if(long2Short.count(longUrl)){
            return "http://tinyurl.com/"+long2Short[longUrl];
        }
        string randStr;
        for (int i = 0; i < 6; i++) {
            randStr.push_back(dict[rand()%62]);
        }
        int idx = 0;
        while(long2Short.count(randStr)){
            randStr[idx] = dict[rand()%62];
            idx = (idx+1)%62;
        }
        short2Long[randStr] = longUrl;
        long2Short[longUrl] = randStr;
        return "http://tinyurl.com/" + randStr;
    }

    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/")+1);
        return short2Long.count(randStr)?short2Long[randStr]:shortUrl;
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/encode-and-decode-tinyurl/
	return 0;
}

