#include <bits/stdc++.h>
using namespace std;

class myStack{
  struct Node{
      int num;
      Node *next,*prev;
      Node(int num):num(num){}
  };
  Node *head = nullptr;
  Node *mid = nullptr;
  int size = 0;
  public:
  void push(int data){
      Node *temp = new Node(data);
      if(size == 0){
          head = temp;
          mid =temp;
          size++;
          return;
      }
      head->next = temp;
      temp->prev = head;
      head = head->next;
      if(size%2 == 1) mid = mid->next;
      size++;
  }
  void pop(){
      if(size != 0){
          if(size == 1){
              head = nullptr,mid = nullptr;
          }else{
              head = head->prev;
              head->next = nullptr;
              if(size%2 == 0) mid = mid->prev;
          }
          size--;
      }
  }
  int findMiddle(){
      if(size == 0) return -1;
      return mid->num;
  }
  void deleteMiddle(){
      if(size != 0){
          if(size == 1) head = nullptr,mid = nullptr;
          else if(size == 2){
              head = head->prev;
              mid = mid->prev;
              head->next = nullptr;
          }else{
              mid->next->prev = mid->prev;
              mid->prev->next = mid->next;
              if(size %2 == 0) mid = mid->prev;
              else mid = mid->next;
          }
          size--;
      }
  }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
	myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    cout<<st.findMiddle()<<endl;
    st.pop();
    st.deleteMiddle();
    cout<<st.findMiddle()<<endl;
    return 0;
}
