//unsorted ll
#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
   if(head==NULL||head->next==NULL){
       return head;
   }
   unordered_set<int>check;
   Node*curr=head;
   Node*prev=NULL;
   
   while(curr!=NULL){
       if(check.count(curr->data)){
           prev->next=curr->next;
           delete curr;
           curr=prev->next;
       }
       else{
           check.insert(curr->data);
           prev=curr;
           curr=curr->next;
       }
   }
   return head;
}

//sorted ll
/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    if(head==NULL){
        return NULL;
    }
    Node* curr= head;
    while(curr!=NULL){
        if((curr->next!=NULL)&& curr->data==curr->next->data){
            Node*next_next=curr->next->next;
            Node*nodeToDelete=curr->next; 
            delete(nodeToDelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

