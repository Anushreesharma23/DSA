//singly circular linkedlist
//we use only tail pointer here because that gets the work done
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        if(this->next !=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data"<<value<<endl;
    }
};

void insertNode(Node*&tail, int element, int d){
    //assuming that the element is present in the linkedlist
    //empty
    if(tail==NULL){
        Node * nodeToInsert = new Node(d);
        tail = nodeToInsert;
        nodeToInsert->next = nodeToInsert;
    }
    //non empty list
    //element is present in the list
    else{
        Node * curr=tail;
        while(curr->data != element){
            curr = curr->next;
        }
        //element found-->curr is representing element wala node
        Node * temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

        
    }
}

void print(Node * tail){
    //agar same aaye toh ruk jana isliye we saved the value of tail in temp n then we compare using while loop
    //single node list wont be able to print itself for that we print the first one manually
    Node* temp = tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }

    do{
        cout<< tail->data<<" ";
        tail = tail->next;
    }while(tail!= temp);
    cout<<endl;
}

void deleteNode(Node * &tail, int value ){
    //empty list
    if(tail==NULL){
        cout<<"list is empty,Please insert elements"<<endl;
        return;
    }
    //non empty case
    //assuming value is present in the list
    Node* prev = tail;
    Node* curr= prev->next;
    while(curr->data!=value){
        prev=curr;
        curr = curr->next;
    }
    prev->next=curr->next;

    //one node
    if(curr==prev){
        tail=NULL;
    }
    //>>1
    else if(tail==curr){
        tail=prev;
    }
    curr->next=NULL;
    delete curr;

}

int main(){

    Node * tail = NULL;
    //empty list mai insertion
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,9,10);
    print(tail);
    insertNode(tail,3,4);
    print(tail);

    deleteNode(tail,6);
    print(tail);

    return 0;
}