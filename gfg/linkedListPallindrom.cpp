// { Driver Code Starts
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




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* head){
        Node *curr = head->next;
        Node* prev = head;
        while(curr){
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        prev -> next = NULL;
        return prev;
    }
    Node* mid(Node *head){
        Node *fast = head, *slow = head, *prev = head;
        while(1){
            if(!fast)
                return prev;
            if(!fast->next)
                return slow;
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
    }
    bool isPalindrome(Node *head)
    {
        Node* sptr = mid(head);
        Node* fptr = head;
        sptr -> next = reverse(sptr);
        sptr =  sptr -> next;
        while(sptr)
            if(sptr -> data != fptr -> data)
                return false;
            else{
                sptr = sptr->next;
                fptr = fptr->next;
            }
        return true;
        //Your code here
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    
    return 0;
}

  // } Driver Code Ends