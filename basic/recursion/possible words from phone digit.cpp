#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
// for iterative use i,j method
// still error is there
// recursive

unordered_map<int,vector<char>> mp;

void generate(int arr[],int n,int ind,string s){
    if(ind == n){
        cout<<s<<endl;
        return;
    }
    auto x = mp[arr[ind]];
    for (int i = 0; i < x.size(); i++){
        generate(arr,n,ind+1,s+x[i]);
    }
}

vector<string> possibleWords(int arr[],int n){
    mp[2]={'a','b','c'};
    mp[3]={'d','e','f'};
    mp[4]={'g','h','i'};
    mp[5]={'j','k','l'};
    mp[6]={'m','n','o'};
    mp[7]={'p','q','r','s'};
    mp[8]={'t','u','v'};
    mp[9]={'w','x','y','z'};
    
    generate(arr,n,0,"");
}

int main() {
    int arr[] = {2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
	possibleWords(arr,n);
    return 0;
}

