/*
PROBLEM
Reverse a Linked List in groups of given size. 

difficulty: Medium

STATEMENT:
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) 
in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should 
be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 

Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.

Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 

Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.

gfg link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

*/

//code
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }  
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        struct node *currptr = head;
        struct node *prevptr = NULL;
        struct node *nextptr;
        
        int count = 0;
        while(currptr != NULL && count<k){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        
        if(nextptr != NULL){
            head->next = reverse (nextptr, k);
        }
        return prevptr;
    }
};

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}
