#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void revese(string &str,int s,int e){
    while(s<=e){
        swap(str[s],str[e]);
        s++,e--;
    }
}

void reverseWords(string &str,int n){{
    int s = 0;
    for (int i = 0; i <n ; i++) {
        if(str[i] == ' '){
            revese(str,s,i-1);
            s=i+1;
        }
    }
    revese(str,s,n-1);
    revese(str,0,n-1);
}
    
}

int main() 
{ 
    string s = "Welcome to Gfg";
    int n=s.length();
    cout<<"After reversing words in the string:"<<endl;
    reverseWords(s,n);
    for (int i = 0; i < n; i++) cout << s[i];
    return 0; 
}

