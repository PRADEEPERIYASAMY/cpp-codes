#include <bits/stdc++.h>
using namespace std;

bool findContainOneTwoThree(int number){
    string str = to_string(number);
    int countOnes ,countTwo, countThree;
    countOnes = countTwo = countThree = 0;
    for (auto &i : str) {
        if(i == '1') countOnes++;
        else if(i == '2') countTwo++;
        else if(i == '3') countThree++;
    }
    return countOnes&&countTwo&&countThree;
}

string printNumbers(int numbers[],int n){
    vector<int> oneTwoThree;
    for (int i = 0; i < n; i++) if(findContainOneTwoThree(numbers[i])) oneTwoThree.push_back(numbers[i]);
    sort(oneTwoThree.begin(),oneTwoThree.end());
    string result = "";
    for (auto &i : oneTwoThree) {
        if(result.size()) result+=", ";
        result+=to_string(i);
    }
    return result.size()>0?result:"-1";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-number-ascending-order-contains-1-2-3-digits/
	int numbers[] = { 123, 1232, 456, 234, 32145 };
    int n = sizeof(numbers)/sizeof(numbers[0]);
    string result = printNumbers(numbers, n);
    cout << result;
	return 0;
}

