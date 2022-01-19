using namespace std;
#include <bits/stdc++.h>

void printLeast(string str){
    int min_val = 1,pos_i = 0;
    vector<int> v;
    if(str[0] = 'I'){
        v.push_back(1);
        v.push_back(2);
        min_val = 3;
        pos_i = 1;
    }else{
        v.push_back(2);
        v.push_back(1);
        min_val = 3;
        pos_i = 0;
    }
    for (int i = 1; i < str.size(); i++) {
        if(str[i] == 'I'){
            v.push_back(min_val);
            min_val++;
            pos_i =i+1;
        }else{
            v.push_back(v[i]);
            for (int j = pos_i; j <= i; j++) v[j]++;
            min_val++;
        }
    }
    for (auto &i : v) cout<<i<<" ";
    cout<<endl;
}

int main(){
    printLeast("IDID");
    printLeast("I");
    printLeast("DD");
    printLeast("II");
    printLeast("DIDI");
    printLeast("IIDDD");
    printLeast("DDIDDIID");
    return 0;
}

