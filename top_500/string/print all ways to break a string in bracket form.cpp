#include <bits/stdc++.h>
using namespace std;

void findCombinations(string str,int index,string out){
    if(index == str.size()) cout<<out<<"\n";
    for (int i = index; i < str.size(); i++) findCombinations(str,i+1,out+"("+str.substr(index,i+1 - index)+")");
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-ways-break-string-bracket-form/
	string str = "abcd";
    findCombinations(str, 0, "");
	return 0;
}

