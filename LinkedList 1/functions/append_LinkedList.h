int ListLength(Node*head){
    int i=0;
    while (head!=NULL){
        i++;
        head=head->next;
    }
    return i;
}
Node* append_LinkedList(Node* head,int n){
    if (n==0){
        return head;
    }
    int length = ListLength(head);
    Node *temp = head;
    for (int i=0; i<length-n-1; i++){
        temp = temp->next;
    }
    Node* newhead = temp->next;
    temp->next = NULL;
    temp = newhead;
    while (temp->next != NULL){
        temp=temp->next;
    }
    temp->next = head;
    return newhead;
}