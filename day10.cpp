#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    public:
    node* first_node(node* &head){
        if(head==NULL || head->next==NULL){
            return NULL;
        }

        node* slow = head;
        node* fast = head;

        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }

        if(slow!=fast){
            return NULL;
        }

        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = new node(50);
        head->next = new node(20);
        head->next->next = new node(15);
        head->next->next->next = new node(4);
        head->next->next->next->next = new node(10);
 
        /* Create a loop*/
        head->next->next->next->next->next = head->next->next;
        Solution ob;
        node* loop = ob.first_node(head);
        cout<<loop<<endl;
    }
    return 0;
}