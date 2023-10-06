/// previous--data--next
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * prev;

    //constructor
    Node(int data){
        this -> data= data;
        this -> next= NULL;
        this -> prev= NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data"<<value<<endl;
    }
};

void print(Node * head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(Node * head){
    int len = 0;
    Node * temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node * &head, Node * &tail, int d){
    //empty list
    if(head==NULL){
        Node* temp = new Node(d);
        head= temp;
        tail= temp;
    }
    else{
        Node * temp = new Node(d);
        temp-> next = head;
        head-> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail= temp;
        head= temp;
    }
    else{
        Node * temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node * &tail, Node * & head, int position, int d){
    //insert at start
    if(position== 1){
        insertAtHead(head,tail, d);
        return;
    }

    Node * temp = head;
    int cnt = 1;
    while(cnt<position -1){
        temp= temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        insertAtTail(tail,head,d);
        return;
    }

    Node * nodeToInsert = new Node(d);
    nodeToInsert->next = temp-> next;
    temp-> next ->prev = nodeToInsert;
    temp->next= nodeToInsert;
    nodeToInsert->prev= temp;
}

void deleteNode(int position, Node* &head){
    if (position ==1)
    {
        Node * temp = head;
        temp->next->prev=NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    // if(temp->next=NULL){
    //     temp->next= prev->next;
    // }
    else{
        Node * curr = head;
        Node * prev = NULL;
        int cnt = 1;
        while(cnt< position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        curr->prev=NULL;
        prev->next= curr->next;
        curr->next= NULL;
        delete curr;
    }
    
} 

int main(){
    Node * node1= new Node(10);
    Node * head = node1;
    Node * tail = node1;

    print(head);
    cout<<getlength(head)<<endl;

    insertAtHead(head,tail,11);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;


    insertAtHead(head,tail,12);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    
    insertAtHead(head,tail,13);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    insertAtTail(tail,head,14);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    insertAtPosition(tail,head,2,100);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    insertAtPosition(tail,head,1,101);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    insertAtPosition(tail,head,8,102);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    deleteNode(6,head);
    print(head);
    cout<<"head"<<" "<<head->data<<endl;
    cout<<"tail"<<" "<<tail->data<<endl;

    deleteNode(7,head);
    print(head);
    cout<<"head"<<" "<<head->data<<endl;
    cout<<"tail"<<" "<<tail->data<<endl;

    return 0;
}
