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
  private:
    Node* getMid(Node*head){
        Node*slow=head;
        Node*fast= head->next;
        while(fast!=NULL&& fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    Node* reverse(Node*head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL){
            return true;
        }
        Node*middle=getMid(head);
        Node*temp=middle->next;
        middle->next=reverse(temp);
        
        //compare the halves
        Node* head1= head;
        Node* head2= middle->next;
        while(head2!=NULL){
            if(head1->data!=head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        //repeat step two reverse back
        temp = middle->next;
        middle->next= reverse(temp);
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
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


// } Driver Code Ends

//second approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return(head);
        }
        ListNode*reverse=NULL;
        ListNode*link=head;
        
        while(link!=NULL){
            ListNode*temp= new ListNode(link->val);
            temp->next=reverse;
            reverse=temp;
            link=link->next;
        }
        while(head&&reverse){
            if(head->val!=reverse->val){
                return false;
            }
            head=head->next;
            reverse=reverse->next;
        }
        return true;
    }
};