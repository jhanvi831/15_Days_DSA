/*
PROBLEM: Count Pairs whose sum is equal to X 
DIFFICULTY: Easy 
STATEMENT: Given two linked list of size N1 and N2 respectively of distinct elements, your task is to complete 
the function countPairs(), which returns the count of all pairs from both lists whose sum is equal to the given 
value X.
Note: The 2 numbers of a pair should be parts of different lists.

Example 1:

Input:
L1 = 1->2->3->4->5->6
L2 = 11->12->13
X = 15
Output: 3
Explanation: There are 3 pairs that
add up to 15 : (4,11) , (3,12) and (2,13)

Example 2:

Input:
L1 = 7->5->1->3
L2 = 3->5->2->8
X = 10
Output: 2
Explanation: There are 2 pairs that add up
to 10 : (7,3) and (5,5)

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N+M)

gfg link: https://practice.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List#

*/

//code
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}

class Solution{
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_set<int>s;
        int pair = 0;
        Node *temp = head1;
        while(temp != NULL){
            s.insert(temp->data);
            temp=temp->next;
        }
        
        Node* temp2 = head2;
        while(temp2 != NULL){
            if(s.find(x - temp2->data)!=s.end()){
                pair++;
            }
            temp2=temp2->next;
        }
        return pair;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
} 