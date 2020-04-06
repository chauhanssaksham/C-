Node *reverseLL(Node *head){
    if (head->next == NULL){
        return head;
    }
    Node *recursion = reverseLL(head->next);
    Node *temp = recursion;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return recursion;
}