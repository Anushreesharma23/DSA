//with replacement
/*
Following is the class structure of the Node class:

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
*/

Node* sortList(Node *head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;

    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        if(temp->data==1){
            oneCount++;
        }
        if(temp->data==2){
            twoCount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(zeroCount!=NULL){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=NULL){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=NULL){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}
//without replacements
void insertAtTail(Node*&tail, Node*curr){
    tail->next=curr;
    tail=curr;
}
Node*sortList(Node*head){
    Node*zeroHead =new Node(-1);
    Node*zerotail =zeroHead;
    Node*oneHead =new Node(-1);
    Node*onetail =oneHead;
    Node*twoHead =new Node(-1);
    Node*twotail =twoHead;

    Node*curr=head;

    //createseparate list 0s,1s,and 2s
    while(curr!=NULL){
        int value= curr->data;
        if(value==0){
            insertAtTail(zeroTail,curr);
        }
        else if(value==1){
            insertAtTail(oneTail,curr);
        }
        else if(value==2){
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }

    //merge three sublists
    //list not empty

    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoHead->next=NULL;

    //setup head
    head= zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}