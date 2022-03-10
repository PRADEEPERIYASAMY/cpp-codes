#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256

struct node {
    char a;
    struct node *next, *prev;
};

void appendNode(struct node** head_ref,struct node** tail_ref, char x){
    struct node* temp = new node;
    temp->a = x;
    temp->prev = temp->next = NULL;
 
    if (*head_ref == NULL) {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}

void removeNode(struct node** head_ref,struct node** tail_ref, struct node* temp){
    if (*head_ref == NULL) return;
    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    delete (temp);
}

void findFirstNonRepeating(){
    node *inDll[MAX_CHAR];
    bool repeated[MAX_CHAR];
    node *head = nullptr,*tail = nullptr;
    fill(inDll,inDll+MAX_CHAR,nullptr);
    fill(repeated,repeated+MAX_CHAR,false);
    string stream = "geeksforgeeksandgeeksquizfor";
    for (int i = 0; i < stream.size(); i++) {
        char x = stream[i];
        cout<<"Reading "<<x<<" from stream \n";
        if(!repeated[x]){
            if(inDll[x] == nullptr){
                appendNode(&head,&tail,stream[i]);
                inDll[x] = tail;
            }else{
                removeNode(&head,&tail,inDll[x]);
                inDll[x] = nullptr;
                repeated[x] = true;
            }
        }
        if(head != nullptr)cout<<"First non-repeating character so far is "<<head->a<<endl;
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
	findFirstNonRepeating();
    return 0;
}
