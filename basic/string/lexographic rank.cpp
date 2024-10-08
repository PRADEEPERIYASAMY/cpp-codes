#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

// summation of factorial*no of chair less than this pressent one(assuming all chairs are distinct)
int fact(int n) { 
    return (n <= 1) ? 1 : n * fact(n - 1); 
} 

int lexRank(string &str){
    int res = 1; 
    int n=str.length();
    int mul= fact(n);
    int count[CHAIR] = {0};
    for (int i = 0; i <n; i++) count[str[i]]++;
    for (int i = 1; i < CHAIR; i++) count[i]+=count[i-1];
    for (int i = 0; i < n-1; i++) {
        mul/=(n-i);
        res+=count[str[i]-1]*mul;
        for (int j = str[i]; j < CHAIR; j++) count[j]--;
    }
    return res;
}

int main() { 
    string str = "STRING"; 
    cout << lexRank(str);  
    return 0; 
} 

