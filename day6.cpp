/*

Implementing linked list functions.
    -> Insert at beginning
    -> Insert at end
    -> Insert at a specific position
    -> searching value in the linked list
    -> deletion of any value

*/

#include<bits/stdc++.h>
using namespace std;


//class node to initialise our node with value and next field
class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};


//insert at starting position
void insertAtHead (node *&head, int val){
    //creating a new node
    node *n = new node(val);
    
    //pointing new node's next field to current head node
    n->next = head;
    //making n the new head node
    head = n;
}

//inserting at a specific position
void insertAtPosition(node* &head, int val, int pos){
    node *n = new node(val);
    
    node *temp = head;
    
    //traverse till node before pos
    for(int i=0; i<pos-1; i++){
        temp=temp->next;
    }
    
    //establish link from right first
    n->next = temp->next;
    
    //establish link from left now
    temp->next = n;
}

//insertion at the end of the linked list
void insertAtTail(node* &head, int val){
    
    //creating a new node
    node *n = new node(val); 
    
    //checking if linked list is empty
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    
    //temp pointer for traversal
    node *temp = head;
    
    //traversing the limked list till the last node
    while(temp->next != NULL){
        temp=temp->next;
    }
    
    //linking the last node with node to be inserted
    temp->next = n;
}

void search(node* &head, int key){
    node *temp = head;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Element found"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Element not found"<<endl;
}


void deleteAtHead(node* &head){
    
    node *todelete = head;
    head=head->next;
    
    delete(todelete);
}

void deletion(node* &head, int val){
    
    //if linked list is empty
    if(head == NULL){
        cout<<"Nothing to delete"<<endl;
        return;
    }
    
    //if only one element is present in linked list
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    
    //if the value at beginning is first call delete at Head
    if(temp->data == val){
        deleteAtHead(head);
        return;
    }
    
    while(temp->next->data != val){
        temp=temp->next;

        //if element to be deleted is not found in the linked list
        if(temp->next == NULL){
            cout<<"Element to be deleted not found"<<endl;
            return;
        }
    }
    
    node* todelete = temp->next;
    temp->next = temp->next->next;
}

//funcr=tion to display linked list
void display(node * head){
    
    //traversal pointer
    node *temp = head;
    
    //traverse all the nodes
    while(temp!=NULL){
        //print the data
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    
    //creating head pointer
    node *head = NULL;
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    
    insertAtHead(head, 4);
    
    insertAtPosition(head, 5, 2);
    
    display(head);
    
    search(head, 7);
    
    return 0;
}
