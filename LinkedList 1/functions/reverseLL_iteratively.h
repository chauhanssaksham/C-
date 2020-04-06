Node *reverseLL_iterative(Node *head){
    Node *before = NULL;
    Node *after = head->next;
    while(head->next != NULL){
        head->next = before;
        before = head;
        head = after;
        after = after->next;
    }
    head->next = before;
    return head;
}