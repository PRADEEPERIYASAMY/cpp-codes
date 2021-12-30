#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int CHAIR = 256;

string nthprimedigitsnumber(int number){
    int rem;
    string res;
    while(number){
        rem = number%4;
        switch(rem){
            case 1:{
                res.push_back('2');
                break;
            }
            case 2:{
                res.push_back('3');
                break;
            }
            case 3:{
                res.push_back('5');
                break;
            }
            case 0:{
                res.push_back('7');
                break;
            }
        }
        
        if(number%4 == 0) number--;
        number/=4;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() { 
    int number = 21;
    cout << nthprimedigitsnumber(10) << "\n";
    cout << nthprimedigitsnumber(21) << "\n";
    return 0;
} 

