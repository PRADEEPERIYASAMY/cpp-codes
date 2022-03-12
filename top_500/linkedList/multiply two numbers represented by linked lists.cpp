#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node *newNode(int data){
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// multiply as number
// long long multiplyTwoLists(Node *first,Node *second){
//     long long N = 1000000007;
//     long long num1 = 0,num2 = 0;
//     while(first || second){
//         if(first){
//             num1 = (num1*10)%N+first->data;
//             first = first->next;
//         }
//         if(second){
//             num2 = (num2*10)%N+second->data;
//             second = second->next;
//         }
//     }
//     return ((num1%N)*(num2%N))%N;
// }

// multiply as linked list 
struct Node* make_empty_list(int size){
    struct Node* head = NULL;
    while (size--)
        push(&head, 0);
    return head;
}


int reverse(struct Node** head_ref){
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    int len = 0;
    while (current != NULL) {
        len++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return len;
}

Node *multiplyTwoLists(Node *first,Node *second){
    int m = reverse(&first),n = reverse(&second);
    Node *result = make_empty_list(m+n+1);
    Node *second_ptr = second,*first_ptr,*result_ptr1 = result,*result_ptr2;
    while(second_ptr){
        int carry = 0;
        result_ptr2 = result_ptr1;
        first_ptr = first;
        while(first_ptr){
            int mul = first_ptr->data * second_ptr->data + carry;
            result_ptr2->data += mul%10;
            carry = mul/10+ result_ptr2->data/10;
            result_ptr2->data = result_ptr2->data%10;
            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }
        if(carry>0) result_ptr2->data +=carry;
        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }
    reverse(&result);
    reverse(&first);
    reverse(&second);
    while(result->data == 0){
        Node *temp = result;
        result = result->next;
        delete(temp);
    }
    return result;
}

void printList(struct Node *node){
    while(node != NULL){
        cout<<node->data;
        if(node->next)
            cout<<"->";
        node = node->next;
    }
    cout<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/multiply-two-numbers-represented-linked-lists/
	struct Node* first = NULL;
    struct Node* second = NULL;
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First List is: ");
    printList(first);
    push(&second, 4);
    push(&second, 8);
    printf("Second List is: ");
    printList(second);
    cout<<"Result is: ";
    //cout<<multiplyTwoLists(first, second);
    struct Node* result = multiplyTwoLists(first, second);
    cout << "Resultant list is: ";
    printList(result);
    return 0;
}
