//https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021

/*Sort Linked List in 0,1,2*/
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


void insertAttail(int data , Node* &head)
{
  if (head == NULL) {
    Node *temp = new Node(data);
    head = temp;
    return ;
  }

  Node * temp = head;
  while(temp != NULL)
  {
      temp = temp -> next;
  }

  Node* Node_to_insert = new Node(data , head);
    temp -> next = Node_to_insert;
    return ;

}

Node* sortList(Node *head){
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp -> data == 0)
        {
            zero_count++;
        }
        else if(temp -> data == 1)
        {
            one_count++;
        } else if (temp->data == 2) {
            two_count++;
        }

        temp = temp -> next;
    }
        temp = head;
        while(temp != NULL)
        {
            if(zero_count != 0)
            {
                temp -> data = 0;
                zero_count--;
            }
            else if(one_count != 0)
            {
                temp -> data = 1;
                one_count--;
            }
            else if(two_count != 0)
            {
                temp -> data = 2;
                two_count--;
            }

            temp = temp -> next;
        }

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
