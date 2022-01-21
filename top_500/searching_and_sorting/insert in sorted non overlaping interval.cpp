using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

void mergeInterval2(pair<int,int> arr[],int n,pair<int,int> newPair){
    stack<pair<int,int>> st;
    st.push(arr[0]);
    auto top = st.top();
    if(newPair.first<top.second){
        st.pop();
        top.first = min(top.first,newPair.first);
        top.second = max(top.second,newPair.second);
        st.push(top);
    }else{
        st.push(newPair);
    }
    for (int i = 1; i < n; i++) {
        top = st.top();
        if(arr[i].first<top.second){
            st.pop();
            top.first = min(arr[i].first,top.first);
            top.second = max(arr[i].second,top.second);
            st.push(top);
        }else{
            st.push(arr[i]);
        }
    }
    int s = st.size();
    for (int i = 0; i < s; i++) {
        st.push(st.top());
        st.pop();
    }
    while(!st.empty()){
        cout<<st.top().first<<space<<st.top().second<<" ---  ";
        st.pop();
    }
}

int main(){
    pair<int, int> arr2[] = {
        { 1, 2 }, { 3, 5 }, { 6, 7 },
                 { 8, 10 }, { 12, 16 }
    };
    pair<int, int> newPair{ 4, 9 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    mergeInterval2(arr2, n2, newPair);
    return 0;
}

