#include <bits/stdc++.h>
using namespace std;

void findMaximumNum(string str,int k,string &m,int ctr){
    if(k == 0) return;
    int n = str.size();
    char maxm = str[ctr];
    for (int i = ctr+1; i < n; i++) maxm = max(maxm,str[i]);
    if(maxm != str[ctr]) k--;
    for (int i = n-1; i >= ctr; i--) {
        if(str[i] == maxm){
            swap(str[ctr],str[i]);
            if(str.compare(m)>0) m = str;
            findMaximumNum(str,k,m,ctr+1);
            swap(str[ctr],str[i]);
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
	string str = "129814999";
    int k = 4;
    string m = str;
    findMaximumNum(str, k, m, 0);
    cout << m << endl;
    return 0;
}

