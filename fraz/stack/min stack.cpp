using namespace std;
#include <bits/stdc++.h>

// class MinStack{
//     stack<int> s1,s2;
//     public:
//     MinStack(){
        
//     }
//     void push(int x){
//         s1.push(x);
//         if(s2.empty() || x<= getMin()) s2.push(x);
//     }
//     void pop(){
//         if(s1.top() == s2.top()) s2.pop();
//         s1.pop();
//     }
//     int top(){
//         return s1.top();
//     }
//     int getMin(){
//         return s2.top();
//     }
// };

// class MinStack {
//     int minval;
//     stack<int> st;
//     public:
//     MinStack():minval(INT_MAX){
        
//     }
//     void push(int x){
//         if(x<= minval){
//             st.push(minval);
//             minval = x; 
//         }
//         st.push(x);
//     }
//     void pop(){
//         int t = st.top();st.pop();
//         if(t == minval){
//             minval = st.top();
//             st.pop();
//         }
//     }
//     int top(){
//         return st.top();
//     }
//     int getMin(){
//         return minval;
//     }
// };

class MinStack{
    stack<long long> st;
    long long minval;
    public:
    MinStack():minval(INT_MAX){
        
    }
    void push(long long val){
        if(st.empty()){
            st.push(val);
            minval = val;
        }else if(val>=minval) st.push(val);
        else{
            st.push(2*val-minval);
            minval = val;
        }
    }
    
    void pop(){
        long long t = st.top();st.pop();
        if(t<minval){
            minval = 2*minval - t;
        }
    }
    long long top(){
        long long t = st.top();
        if(t<minval) return minval;
        return t;
    }
    int getMin(){
        return minval;
    }
};

int main(){
    //leet code solutions
    //https://leetcode.com/problems/min-stack/discuss/1539330/C%2B%2B-99.74-faster-or-Simple-Better-and-Optimal-solutions-using-stacks
    //https://leetcode.com/problems/min-stack/discuss/1217452/C%2B%2B-solution-using-O(1)-extra-space-simple-math-trick
    return 0;
}

