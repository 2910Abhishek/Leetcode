//https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021

/*Sort Linked List in 0,1,2*/

/*USING CONCEPT PF DUMMY NODE*/

/*
Following is the class structure of the Node class:
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void insertAtTail(Node* &tail , Node* curr)
{
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head){
   
   // USING CONCEPT OF DUMMY NODES
   Node* zerohead = new Node(-1);
   Node* zerotail = zerohead;
   Node* onehead = new Node(-1);
   Node* onetail = onehead;
   Node* twohead = new Node(-1);
   Node* twotail = twohead;

   Node* curr = head;
   

   // CREATED SEPEARTE LIST FOR 0s ,1s , 2s
   while(curr != NULL)
   {
       int value = curr -> data;

       if(value == 0)
       {
           insertAtTail(zerotail, curr);
       }
       else if(value == 1)
       {
           insertAtTail(onetail, curr);
       }
       else if(value == 2)
       {
           insertAtTail(twotail, curr);
       }

       curr = curr -> next;
   }
    
    // merger 3 sublist 
    if(onehead -> next != NULL)
    {
        zerotail -> next = onehead -> next;
    } else {
        // 1s list is empty
        zerotail = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next = NULL;

    head = zerohead->next;

    // delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}


int main() {
    cout << "Enter Total Number of Elements In The Linked List = " ;
    int n;
    cin >> n;  // Number of elements in the linked list

    Node* head = NULL;
    Node* tail = NULL;

    // Input the linked list elements
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Call the sorting function
    head = sortList(head);

    // Print the sorted linked list
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    // Clean up memory (delete the linked list)
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
