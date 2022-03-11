#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next, *random;
    Node(int data){
        this->data = data;
        this->next = this->random = NULL;
    }
};

class LinkedList{
    public:
    Node *head;
 
    LinkedList(Node *head){
        this->head = head;
    }
 
    void push(int data){
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }
    void print(){
        Node *temp = head;
        while (temp != NULL){
            Node *random = temp->random;
            int randomData = (random != NULL)?random->data: -1;
            cout << "Data = " << temp->data<< ", ";
            cout << "Random Data = " <<randomData << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    // hashmap based implementation
    // LinkedList *clone(){
    //     Node *origCurr = head;
    //     Node *cloneCurr = nullptr;
    //     unordered_map<Node*,Node*> mp;
    //     while(origCurr != nullptr){
    //         cloneCurr = new Node(origCurr->data);
    //         mp[origCurr] = cloneCurr;
    //         origCurr = origCurr->next;
    //     }
    //     origCurr = head;
    //     while(origCurr != nullptr){
    //         cloneCurr = mp[origCurr];
    //         cloneCurr->next = mp[origCurr->next];
    //         cloneCurr->random = mp[origCurr->random];
    //         origCurr = origCurr->next;
    //     }
    //     return new LinkedList(mp[head]);
    // }
    
    // constant space implementation
    LinkedList *clone(){
        Node *curr = head,*temp;
        while(curr){
            temp = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        while(curr){
            if(curr->next){
                curr->next->random = curr->random?curr->random->next:curr->random;
                curr = curr->next?curr->next->next:curr->next;
            }
        }
        Node *original = head,*copy = head->next;
        temp = copy;
        while(original && copy){
            original->next = original->next?original->next->next:original->next;
            copy->next = copy->next?copy->next->next:copy->next;
            original = original->next;
            copy = copy->next;
        }
        return new LinkedList(temp);
    }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
	LinkedList *mylist = new LinkedList(new Node(5));
    mylist->push(4);
    mylist->push(3);
    mylist->push(2);
    mylist->push(1);
    mylist->head->random = mylist->head->next->next;
    mylist->head->next->random = mylist->head->next->next->next;
    mylist->head->next->next->random = mylist->head->next->next->next->next;
    mylist->head->next->next->next->random = mylist->head->next->next->next->next->next;
    mylist->head->next->next->next->next->random = mylist->head->next;
    LinkedList *clone = mylist->clone();
    cout << "Original linked list\n";
    mylist->print();
    cout << "\nCloned linked list\n";
    clone->print();
    return 0;
}
