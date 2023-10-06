//iterative method
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node * prev = NULL;
    Node * current = head;
    Node * forward = NULL;

    while(current != NULL){
        forward = curr->next;
        curr->next = prev;
        prev= curr;
        curr= forward;
    }
    return prev;
}
//recursive method

void reverse(Node * &head, Node* curr, Node* prev){
    //base case
    if(curr== NULL){
        head = prev;
        return;
    }
    //processing
    Node * forward = curr->next;
    reverse(head, forward, curr);
    curr-> next = prev;
}
Node * reverseLinkedList(Node* head){
    Node * curr= head;
    Node * prev= NULL;
    reverse(head, curr, prev);
    return head;
}

//recursive method 2
//it will return the head of the reverse list
// Node* reverse1(Node* head){
//     //base case
//     if(head==NULL || head->next ==NULL){
//         return head;
//     }
//     Node * chotaHead = reverse1(head->next);
//     head->next->next = head;
//     head-> next = NULL;
//     return chotaHead;
// }

// Node * reverseLinkedList(Node* head){
//     return reverse1(head);
// }