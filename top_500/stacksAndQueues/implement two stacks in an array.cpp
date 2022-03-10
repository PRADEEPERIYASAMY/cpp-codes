#include <bits/stdc++.h>
using namespace std;

// divide array into two halves
// class twoStack{
//     int *arr;
//     int size;
//     int top1,top2;
//     public:
//     twoStack(int n):size(n){
//         arr = new int[n];
//         top1 = n/2+1;
//         top2 = n/2;
//     }
//     void push1(int x){
//         if(top1>0){
//             top1--;
//             arr[top1] = x;
//         }else{
//             cout<<"Stack overflow by element :"<<x<<"\n";
//             return;
//         }
//     }
//     void push2(int x){
//         if(top2<size-1){
//             top2++;
//             arr[top2] = x;
//             return;
//         }else{
//             cout<<"Stack overflow by element :"<<x<<"\n";
//             return;
//         }
//     }
//     int pop1(){
//         if(top1<=size/2){
//             int x = arr[top1];
//             top1++;
//             return x;
//         }else{
//             cout<<"Stack underflow";
//             return -1;
//         }
//     }
//     int pop2(){
//         if(top2>=size/2 +1){
//             int x = arr[top2];
//             top2--;
//             return x;
//         }else{
//             cout<<"Stack underflow";
//             return 0;
//         }
//     }
// };

// efficient
class twoStack{
  int *arr;
  int size;
  int top1,top2;
  public:
  twoStack(int n):size(n){
      arr = new int[n];
      top1 = -1;
      top2 = n;
  }
  void push1(int x){
      if(top1<top2-1){
          top1++;
          arr[top1] = x;
      }else{
          cout<<"Stack overflow";
          return;
      }
  }
  void push2(int x){
      if(top1<top2-1){
          top2--;
          arr[top2] = x;
      }else{
          cout<<"Stack overflow";
          return;
      }
  }
  int pop1(){
      if(top2>=0){
          int x = arr[top1];
          top1--;
          return x;
      }else{
          cout<<"Stack underflow";
          return -1;
      }
  }
  int pop2(){
      if(top2<size){
          int x = arr[top2];
          top2++;
          return x;
      }else{
          cout<<"Stack underflow";
          return -1;
      }
  }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
	twoStack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "<< " : " << ts.pop1()<< endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "<< ": " << ts.pop2()<< endl;
    return 0;
}
