using namespace std;
#include <bits/stdc++.h>

int signum(int a,int b){
    if(a == b) return 0;
    return a<b?-1:1;
}

int getMedian(int e,int &m,priority_queue<int> &max_h,priority_queue<int,vector<int>,greater<int>> &min_h ){
    int sig = signum(max_h.size(),min_h.size());
    switch(sig){
        case 1:if(e<m){
                    min_h.push(max_h.top());
                    max_h.pop();
                    max_h.push(e);
                }else min_h.push(e);
                m = min_h.top()+max_h.top();
                m/=2;
            break;
        case 0:if(e<m){
                    max_h.push(e);
                    m = max_h.top();
                }else{
                    min_h.push(e);
                    m = min_h.top();
                }
            break;
        case -1:if(e<m)max_h.push(e);
                else{
                    max_h.push(min_h.top());
                    min_h.pop();
                    min_h.push(e);
                }
                m = min_h.top()+max_h.top();
                m/=2;
    }
    return m;
}

void printMedian(int arr[],int n){
    int m = 0;
    priority_queue<int> max_h;
    priority_queue<int,vector<int>,greater<int>> min_h;
    for (int i = 0; i < n; i++) {
        m = getMedian(arr[i],m,max_h,min_h);
        cout<<m<<" ";
    }
}
 
int main(){
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(A)/sizeof(A[0]);
    printMedian(A, size);
    return 0;
}

