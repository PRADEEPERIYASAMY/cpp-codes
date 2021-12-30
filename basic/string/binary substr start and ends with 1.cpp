#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int countSubStr(string &str){
    int m = 0;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '1') m++;
    }
    return m*(m-1)/2;
}

int main() { 
  string str = "00100101";
  cout << countSubStr(str);
  return 0;
} 

