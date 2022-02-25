#include <bits/stdc++.h>
using namespace std;

string nextGreaterWithSameDigits(string bnum){
    int l = bnum.size();
    int i;
    for (i = l-2; i >=1; i--) {
        if(bnum[i] == '0' && bnum[i+1] == '1'){
            swap(bnum[i],bnum[i+1]);
            break;
        }
    }
    if(i == 0) return "NO greater number";
    int j = i+2,k = l-1;
    while(j<k){
        if(bnum[j] == '1' && bnum[k] == '0'){
            swap(bnum[j],bnum[k]);
            j++;
            k--;
        }else if(bnum[i] == '0') break;
        else j++;
    }
    return bnum;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/binary-representation-next-greater-number-number-1s-0s/
    string bnum = "10010";
    cout<<"Binary representation of next greater number = "<<nextGreaterWithSameDigits(bnum);
    return 0;
}

