using namespace std;
#include <bits/stdc++.h>

int getDecimalValue(ListNode* head) {
    int res = 0;
    while(head!=nullptr) res = res*2+head->val,head = head->next;
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
    return 0;
}

