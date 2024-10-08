#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

Node* newNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// using divide and conquire
// Node *SortedMerge(Node *a,Node *b){
//     Node *result = nullptr;
//     if(a == nullptr) return b;
//     if(b == nullptr) return a;
//     if(a->data <= b->data){
//         result = a;
//         result->next = SortedMerge(a->next,b);
//     }else{
//         result = b;
//         result->next = SortedMerge(a,b->next);
//     }
//     return result;
// }

// Node *mergeKLists(Node *arr[],int last){
//     while(last != 0){
//         int i = 0,j = last;
//         while(i<j){
//             arr[i] = SortedMerge(arr[i],arr[j]);
//             i++,j--;
//             if(i>=j) last = j;
//         }
//     }
//     return arr[0];
// }

// using priority queue 

// struct compare{
//     bool operator()(Node *a,Node b){
//         return a->data>b->data;
//     }
// }

Node *mergeKLists(Node *arr[],int k){
    auto compare = [](Node *a,Node *b){return a->data > b->data;};
    priority_queue<Node*,vector<Node*>,decltype(compare)> pq(compare); 
    for (int i = 0; i < k; i++) pq.push(arr[i]);
    if(pq.empty()) return nullptr;
    Node *dummy = newNode(0);
    Node *last = dummy;
    while(!pq.empty()){
        Node *cur = pq.top();pq.pop();
        last->next = cur;
        last = last->next;
        if(cur->next) pq.push(cur->next);
    }
    return dummy->next;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/
	int k = 3;
    int n = 4; 
    Node* arr[k];
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
    //Node* head = mergeKLists(arr, k - 1);
    Node* head = mergeKLists(arr, k);
    printList(head);
    return 0;
}
