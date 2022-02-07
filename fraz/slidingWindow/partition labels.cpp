#include <iostream>
using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> last(26,0);
    for (int i = 0; i < S.size(); i++) last[S[i] -'a'] = i;
    vector<int> res;
    int j = 0,k = 0;
    for (int i = 0; i < S.size(); i++) {
        j = max(j,last[S[i] - 'a']);
        if(i == j){
            res.push_back(i - k +1);
            k = i+1;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/partition-labels/discuss/348059/C%2B%2B-O(n)-solution-with-explanation
	return 0;
}

