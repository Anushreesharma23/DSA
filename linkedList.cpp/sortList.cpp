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