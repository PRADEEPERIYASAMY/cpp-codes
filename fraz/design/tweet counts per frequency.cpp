#include <iostream>
using namespace std;

class TweetCounts {
    unordered_map<string,vector<int>> m;
    unordered_map<string,int> f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> res;
        for (int i = 0; i <= (endTime - startTime)/f[freq]; i++) res.push_back(0);
        for (auto &time : m[tweetName]) {
            if(time>=startTime && time<=endTime){
                int index = (time - startTime)/f[freq];
                res[index]++;
            }
        }
        return res;
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/tweet-counts-per-frequency/discuss/504456/C%2B%2B-accepted-solution-with-map
	return 0;
}

