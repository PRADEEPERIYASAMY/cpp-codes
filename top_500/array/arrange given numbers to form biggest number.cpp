using namespace std;
#include <bits/stdc++.h>

int mycompare(string x,string y){
    string xy = x+y;
    string yx = y+x;
    return xy.compare(yx) >0 ? 1:0;
}

void printLargest(vector<string> arr){
    sort(arr.begin(),arr.end(),mycompare);
    for (auto &i : arr) cout<<i;
}

int main(){
    vector<string> arr;
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    printLargest(arr);
    return 0;
}

