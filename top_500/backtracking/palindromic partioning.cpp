using namespace std;
#include <bits/stdc++.h>

bool checkPalindrome(string str){
    int i = 0,j = str.size()-1;
    while(i<j){
        if(str[i] != str[j]) return false;
        i++;j--;
        return true;
    }
}

void printSolution(vector<vector<string>> partitions){
    for (int i = 0; i < partitions.size(); i++) {
        for (auto &x : partitions[i]) cout<<x<<" ";
        cout<<endl;
    }
    return;
}

void addString(vector<vector<string>> &v,string &s,vector<string> &temp,int index){
    int n = s.size();
    string str;
    vector<string> current = temp;
    if(index == 0) temp.clear();
    for (int i = index; i < n; i++) {
        str = str+s[i];
        if(checkPalindrome(str)){
            temp.push_back(str);
            if(i+1<n) addString(v,s,temp,i+1);
            else v.push_back(temp);
            temp = current;
        }
    }
    return;
}

void partition(string s,vector<vector<string>> &v){
    vector<string> temp;
    addString(v,s,temp,0);
    printSolution(v);
    return;
}

int main(){
    string s = "geeks";
    vector<vector<string> > partitions;
    partition(s, partitions);
    return 0;
}

