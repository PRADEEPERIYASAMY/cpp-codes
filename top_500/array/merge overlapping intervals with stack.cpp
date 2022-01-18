using namespace std;
#include <bits/stdc++.h>

struct Interval{
    int start,end;
};

bool comparison(Interval a,Interval b){
    return a.start<b.start;
}

void mergeIntervals(Interval arr[],int n){
    if(n<0) return;
    stack<Interval> s;
    sort(arr,arr+n,comparison);
    s.push(arr[0]);
    for (int i = 1; i < n; i++) {
        Interval top = s.top();
        if(top.end < arr[i].start) s.push(arr[i]);
        else if(top.end < arr[i].end){
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    while(!s.empty()){
        Interval t = s.top();
        cout<<"["<<t.start<<","<<t.end<<"]";
        s.pop();
    }
}

int main()
{
    Interval arr[] =  {{1,3}, {2,4}, {5,7}, {6,8}};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}

