#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"memory is free for  node with data "<<value<<endl;
    }
};
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    Node*temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    //insert at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    //insert at last
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //if the position is not first and last
    Node* nodeToInsert = new Node(d);
    nodeToInsert-> next = temp-> next;
    temp-> next = nodeToInsert;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(int position, Node* &head){
    if (position ==1)
    {
        Node * temp = head;
        head = head->next;
        temp-> next = NULL;
        delete temp;
    }
    else{
        Node * curr = head;
        Node * prev = NULL;
        int cnt = 1;
        while(cnt< position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        prev -> next = curr ->next;
        curr -> next = NULL;
        delete curr;
    }
}

    bool DetectLoop(Node*head){
    if(head==NULL){
        return false;
    }
    map<Node*,bool>visited;
    Node* temp= head;

    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"loop starts from the element "<<temp->data<<endl;
            return true;
        }
        visited[temp]= true;
        temp= temp->next;
    }
    return false;
}
    
int main(){
    //node creation
    Node* node1 = new Node(10);
    //cout<<node1 -> data <<endl;
    //cout<<node1 -> next <<endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    // print(head);
    // insertAtHead(head, 12);
    // print(head);
    // insertAtHead(head, 15);
    // print(head);
    
    insertAtTail(tail, 12);
    // print(head);
    insertAtTail(tail, 15);
    // print(head);

    insertAtPosition(tail, head, 4, 22);
    // print(head);
    tail->next= head->next;
    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;
    
    // deleteNode(1,head);
    //print(head);
    if(DetectLoop(head)){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"No cycle is present"<<endl;
    }

    return 0;
}