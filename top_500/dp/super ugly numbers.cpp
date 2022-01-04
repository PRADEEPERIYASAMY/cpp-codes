#include<bits/stdc++.h>
using namespace std;

int superUgly(int n,int primes[],int k){
    vector<int> nextMultiple (primes,primes+k);
    int mulptiple[k]={0};
    set<int> ugly;
    ugly.insert(1);
    while(ugly.size() != n){
        int nex_ugly = *min_element(nextMultiple.begin(),nextMultiple.end());
        ugly.insert(nex_ugly);
        for (int i = 0; i < k; i++) {
            if(nex_ugly == nextMultiple[i]){
                mulptiple[i]++;
                set<int>::iterator it = ugly.begin();
                for (int j = 1; j <= mulptiple[i]; j++) it++;
                nextMultiple[i] = primes[i] * (*it);
                break;
            }
        }
    }
    set<int>::iterator it = ugly.end();
    it--;
    return *it;
}

int main() {
	int primes[] = {2,  5};
    int k = sizeof(primes)/sizeof(primes[0]);
    int n = 5;
    cout << superUgly(n, primes, k);
    return 0;
}

