#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

int isRotated(string str1,string str2){
    if(str1.length() != str2.length()) return false;
    if(str1.length()<2) return str1.compare(str2) == 0;
    string clockRot = "",anitClockRot = "";
    int n = str2.length();
    anitClockRot+=(str2.substr(n-2,2)+str2.substr(0,n-2));
    clockRot+=(str2.substr(2,n-2)+str2.substr(0,2));
    return (str1.compare(clockRot) == 0) || (str1.compare(anitClockRot) == 0);
}

int main() { 
    string str1 = "geeks";
    string str2 = "eksge";
    isRotated(str1, str2) ? cout << "Yes": cout << "No";
    return 0;
} 

