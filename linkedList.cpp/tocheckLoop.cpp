#include <map>
#include <iostream>
using namespace std;
using map
// bool DetectLoop(Node*head){
//     if(head==NULL){
//         return false;
//     }
//     map<Node*,bool>visited;
//     Node* temp= head;

//     while(temp!=NULL){
//         if(visited[temp]==true){
//             return true;
//         }
//         visited[temp]= true;
//         temp= temp->next;
//     }
//     return false;
// }

floyds cycle detection

Node* floydDetectLoop(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node* slow= head;
    Node* fast= head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"present at"<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

//finding out the starting node of the loop
Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node*slow = head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
//removing cycles from the loopedLL
void removeLoop(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node* startOfLoop = getStartingNode(head);
    Node*temp= startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}