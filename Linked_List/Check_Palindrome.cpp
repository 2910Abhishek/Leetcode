// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
        
    }
    
    Node* getMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL)
        {
            return head;
        }
        Node* middle = getMid(head);
        middle -> next = reverse(middle -> next) ;
        
        Node* head1 = head;
        Node* head2 = middle -> next;
        while(head2 != NULL)
        {
            if(head1 -> data == head2 -> data)
            {
                head1 = head1 -> next;
                head2 = head2 -> next;
                continue;
            }
            else
            {
                return false;
            }
        }
        middle = getMid(head);
        middle -> next = reverse(middle -> next);
        return true;
    }
};
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
// TIME COMPLELXITY = O(n)
// Space Complexity = O(1)


/*  Approach 2 
    Copy ALl elements of linked list in array and then check palindrome
*/

