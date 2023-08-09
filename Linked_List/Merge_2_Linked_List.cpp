#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the linked list node structure.

************************************************************/
template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
    
Node<int>* solve(Node<int> *first, Node<int> *second) {
    
    // if only one element d present in 1st list
    if(first -> next == NULL)
    {
        first -> next = second;
        return first;
    }

    
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL)
    {
        if((curr2 -> data >= curr1 -> data)
        && (curr2 -> data <= next1 -> data))
        {
            // add node in between the first node
           curr1 -> next = curr2;
           next2 = curr2 -> next;
           curr2 -> next = next1;
           
           // update pointer 
           curr1 = curr2;
           curr2 = next2;
        }
        else{
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1 -> next;
            
            if(next1 == NULL)
            {
                curr1 -> next = curr2;
                return first;
            }

        }
    }

    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
    {
        return second;
    }
    
    if(second == NULL)
    {
        return first;
    }

    if(first -> data <= second -> data)
    {
        return solve(first , second);
    }
    else
    {
        return solve(second , first);
    }
}



int main() {
    int n, m; // Number of elements in the first and second linked lists
    cin >> n >> m;

    Node<int>* firstHead = NULL;
    Node<int>* firstTail = NULL;

    // Input the elements of the first linked list
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node<int>* newNode = new Node<int>(data);
        if (firstHead == NULL) {
            firstHead = newNode;
            firstTail = newNode;
        } else {
            firstTail->next = newNode;
            firstTail = newNode;
        }
    }

    Node<int>* secondHead = NULL;
    Node<int>* secondTail = NULL;

    // Input the elements of the second linked list
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        Node<int>* newNode = new Node<int>(data);
        if (secondHead == NULL) {
            secondHead = newNode;
            secondTail = newNode;
        } else {
            secondTail->next = newNode;
            secondTail = newNode;
        }
    }

    // Call the sortTwoLists function to merge and sort the linked lists
    Node<int>* sortedList = sortTwoLists(firstHead, secondHead);

    // Print the sorted merged linked list
    Node<int>* current = sortedList;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    // Clean up memory (delete the linked lists)
    delete firstHead;
    delete secondHead;
    // Remember to delete the sortedList as well

    return 0;
}
