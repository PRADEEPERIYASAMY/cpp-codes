#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int const size = 8*(sizeof(ull));

bool bit_anagram_check(ull a,ull b){
    int i = 0;vector<int> binaryA(size,0);
    while(a>0){
        binaryA[i] = a%2;
        a/=2;
        i++;
    }
    int j = 0;vector<int> binaryB(size,0);
    while(b>0){
        binaryB[j] = b%2;
        b/=2;
        j++;
    }
    sort(binaryA.begin(),binaryA.end());
    sort(binaryB.begin(),binaryB.end());
    for (int i = 0; i < size; i++) if(binaryA[i] != binaryB[i]) return false;
    return true;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/check-binary-representations-two-numbers-anagram/
	ull a = 8, b = 4;
    cout << bit_anagram_check(a, b) << endl;
    return 0;
}

