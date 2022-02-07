#include <iostream>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int mins = customers.size();
    int directly_satisified = 0;
    for (int i = 0; i < mins; i++) {
        if(!grumpy[i]){
            directly_satisified+=customers[i];
            customers[i] = 0;
        }
    }
    int secretely_satisified = 0,sum = 0;
    for (int j = 0,i = 0; j < mins; j++) {
        sum += customers[j];
        if(j - i == X) sum -= customers[i++];
        secretely_satisified = max(secretely_satisified,sum);
    }
    return directly_satisified+secretely_satisified;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/grumpy-bookstore-owner/discuss/299198/C%2B%2B-Linear-Time-(Easy-to-Understand)
	return 0;
}

