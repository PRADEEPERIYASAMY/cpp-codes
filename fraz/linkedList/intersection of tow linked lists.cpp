#include <iostream>
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return nullptr;
    ListNode *pA = headA,*pB = headB;
    while(pA != pB){
        pA = pA? pA->next:headB;
        pB = pB?pB->next:headA;
    }
    return pA;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/intersection-of-two-linked-lists/
	return 0;
}

