#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

string caseSpecificSort(string str){
    int n = str.length();
    string string1 = str;
    int j = 0, k = 0;
    sort(string1.begin(),string1.end());
    j = 0;
    while (string1[j] <= 'Z')j++;
            
    for (int i = 0; i < n; i++){
        if(str[i] <= 'Z'){
            str[i] = string1[k];
            k++;
        }
        else{
            str[i] = string1[j];
            j++;
        }
    }
    return str;
}

int main() { 
    cout<<caseSpecificSort("defRTSersUXI");
    return 0;
} 

