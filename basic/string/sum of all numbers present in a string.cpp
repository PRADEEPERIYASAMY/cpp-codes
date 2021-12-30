#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int findSum(string &str){
    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        int temp = 0;
        while(isdigit(str[i])){
            temp = temp*10+(str[i]-'0');
            i++;
        }
        res+=temp;
        temp = 0;
    }
    return res;
}

int main() { 
    string str = "12abc20yz68";
    cout << findSum(str);
    return 0;
} 

