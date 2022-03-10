#include <bits/stdc++.h>
using namespace std;

// naive method use two stacks one for store value and another for minvalues
// space optimized version
class SpecialStack{
    int min = -1;
    static const int d = 99999;
    stack<int> st;
    public:
    void getMin(){
        cout<<"Min is: "<<min<<"\n";
    }
    void push(int val){
        if(st.empty() || val<min) min = val;
        st.push(val*d+min);
        cout<<"pushed: "<<val<<"\n";
    }
    int pop(){
        if(st.empty()){
            cout<<"Stack underflow\n";
            return -1;
        }
        int val = st.top();
        st.pop();
        if(!st.empty()) min = st.top()%d;
        else min = -1;
        cout<<"popped: "<<val/d<<"\n";
        return val/d;
    }
    int peek(){
        return st.top()/d;
    }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
	SpecialStack s;
    vector<int> arr = { 3, 2, 6, 1, 8, 5, 5, 5, 5 };
    for(int i = 0; i < arr.size(); i++){
        s.push(arr[i]);
        s.getMin();
    }
    cout << endl;
    for(int i = 0; i < arr.size(); i++){
        s.pop();
        s.getMin();
    }
    return 0;
}