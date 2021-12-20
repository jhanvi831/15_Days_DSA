/*
Reverse a linked list
(Iterative Method & Recursive)

*/

//code
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val){
    node* n = new node(val);
    
    if(head==NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = n;
    return;
}

void reverse_ll(node* &head){
    node *prev = NULL;
    node *curr = head;
    node *nptr = NULL;
    
    while(curr!=NULL){
        nptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nptr;
    }
    head = prev;
    return;
}

node* reverse_recur(node* &head){
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node *newhead = reverse_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

void display(node *head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    
    node* head = NULL;
    
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    
    display(head);
    
    reverse_ll(head);
    
    display(head);
    
    node *newhead = reverse_recur(head);
    display(newhead);
    
    return 0;
}
