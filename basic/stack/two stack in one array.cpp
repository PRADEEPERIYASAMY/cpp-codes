#include <bits/stdc++.h> 
using namespace std; 

struct TwoStacks{
    int *arr;
    int cap;
    int top1,top2;
    TwoStacks(int n){
        cap = n;
        arr = new int[cap];
        top1 = n/2+1;
        top2 = n/2;
    }
    void push1(int x){
        if(top1 >0){
            top1--;
            arr[top1] = x;
        }else{
            cout << "Stack Overflow"<< " By element :" << x << endl; 
            return;
        }
    }
    void push2(int x){
        if(top2 < cap-1){
            top2++;
            arr[top2] = x;
        }else{
            cout << "Stack Overflow"<< " By element :" << x << endl; 
            return;
        }
    }
    int pop1(){
        if(top1 <= cap/2){
            int x = arr[top1];
            top1++;
            return x;
        }else{
            cout<<"Stack underflow";
            return INT_MIN;
        }
    }
    int pop2(){
        if(top2 >= (cap/2 +1)){
            int x = arr[top2];
            top2--;
            return x;
        }else{
            cout<<"Stack underflow";
            return INT_MIN;
        }
    }
};

