bool isCircularList(Node*head){
    //empty list
    if(head==NULL){
        return true;
    }
    //making a new node
    Node*temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}