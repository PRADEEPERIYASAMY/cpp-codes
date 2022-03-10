#include <bits/stdc++.h>
using namespace std;

class kStacks{
    int *arr,*top,*next,n,k,free;
    public:
    kStacks(int k,int n):k(k),n(n){
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        fill(top,top+k,-1);
        free = 0;
        for (int i = 0; i <n-1; i++) next[i] = i+1;
        next[n-1] = -1;
    }
    void push(int item,int sn){
        if(isfull()){
            cout<<"\nStack Overflow\n";
            return;
        }
        int i =free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = item;
    }
    int pop(int sn){
        if(isEmpty(sn)){
            cout<<"\nStack underflow\n";
            return INT_MAX;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] =free;
        free = i;
        return arr[i];
    }
    bool isfull(){
        return free == -1;
    }
    bool isEmpty(int sn){
        return top[sn] == -1;
    }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
	int k = 3, n = 10;
    kStacks ks(k, n);
  
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
  
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}
