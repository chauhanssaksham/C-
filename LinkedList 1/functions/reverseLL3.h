Node *reverseLL3(Node *head){
    if (head->next == NULL){
        return head;
    }
    Node *recursion = reverseLL3(head->next);
    Node *temp = head->next;
    head->next = NULL;
    temp->next = head;
    return recursion;
}