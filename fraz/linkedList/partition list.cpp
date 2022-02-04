#include <iostream>
using namespace std;

ListNode *partition(ListNode *head, int x) {
    ListNode *p1 = new ListNode(0),*p2 = new ListNode(0),*temp1 = p1,*temp2 = p2;
    while(head){
        if(head->val<x){
            p1->next = head;
            p1 = p1->next;
        }else{
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }
    p2->next = nullptr;
    p1->next = temp2->next;
    return temp1->next;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/partition-list/
	return 0;
}

