/*

PROBLEM: Add 1 to a number represented as linked list 
DIFFICULTY: Easy
STATEMENT: A number N is represented in Linked List such that each digit corresponds to a node in linked list. 
You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457

Example 2:

Input:
LinkedList: 1->2->3
Output: 124 

GFG LINK: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

*/

//code
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
    public:
    Node* reverse(Node* head){
        if(head == NULL || head->next==NULL){
            return head;
        }
        Node *newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    
    Node* addOneUtil(Node* head){
    Node* res = head; 
    Node *temp = NULL; 
  
    int carry = 1, sum; 
  
    while (head != NULL)
    { 
        
        sum = carry + head->data; 
        carry = (sum >= 10)? 1 : 0; 
        sum = sum % 10; 
        head->data = sum; 
        temp = head; 
        head = head->next; 
    } 
    if (carry > 0) 
        temp->next = new Node(carry); 
  
    return res; 
    } 
  
    Node* addOne(Node *head) 
    { 
        head = reverse(head);
        head = addOneUtil(head); 
        return reverse(head); 
    } 
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 