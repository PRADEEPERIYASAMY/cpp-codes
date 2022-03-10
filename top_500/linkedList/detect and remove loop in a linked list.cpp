#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key){
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void printList(Node* head){
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

// void detectAndRemoveLoop(Node *head){
//     if(head == nullptr || head->next == nullptr) return;
//     Node *slow,*fast;
//     slow = fast = head;
//     slow = slow->next;
//     fast = fast->next->next;
//     while(fast && fast->next){
//         if(slow == fast) break;
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     if(slow == fast){
//         slow = head;
//         if(slow == fast){ // if both meets at head
//             while(fast->next != slow) fast = fast->next;
//         }else{
//             while(slow->next != fast->next) slow = slow->next,fast = fast->next;
//         }
//     }
//     fast->next = nullptr;
// }

// using hashmap
void detectAndRemoveLoop(Node *head){
    unordered_map<Node*,int> mp;
    Node* last = nullptr;
    while(head != nullptr){
        if(mp.find(head) == mp.end()){
            mp[head]++;
            last = head;
            head = head->next;
        }else{
            last->next = nullptr;
            break;
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
	Node* head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head;
    detectAndRemoveLoop(head);
    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}
