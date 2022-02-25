#include <bits/stdc++.h>
using namespace std;

bool match(string first,string second){
    if(first[0] == '\0' && second[0] == '\0') return true;
    if(first[0] == '*' && first[1] != '\0' && second[0] == '\0') return false;
    if(first[0] == '?' || first[0] == second[0]) return match(first.substr(1),second.substr(1));
    if(first[0] == '*') return match(first.substr(1),second) || match(first,second.substr(1));
    return false;
}

void test(string first,string second){
    match(first,second)?cout<<"y":cout<<"n";
    cout<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/wildcard-character-matching/
	test("g*ks", "geeks");
    test("ge?ks*", "geeksforgeeks");
    test("g*k", "gee");
    return 0;
}

