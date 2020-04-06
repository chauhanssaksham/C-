int ListLength(Node*head){
    int i=0;
    while (head!=NULL){
        i++;
        head=head->next;
    }
    return i;
}
Node*reverse(Node*head){
    if (head->next == NULL || head == NULL){
        return head;
    }
    Node *recursion = reverse(head->next);
    Node *temp = head->next;
    head->next = NULL;
    temp->next = head;
    return recursion;
}

Node *kReverse(Node*head, int k){
    int length = ListLength(head);
    if (length<=k){
        //Base Case
        return reverse(head);
    }
    Node *temp=head;
    for(int i=0; i<k-1; i++){
        temp = temp->next;
    }
    Node *nextKReverse = temp->next;
    temp->next = NULL;
    Node *recursion = kReverse(nextKReverse, k);
    temp = reverse(head);
    head->next = recursion;
    return temp;
}