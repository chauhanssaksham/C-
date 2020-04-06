Node *deleteNodeRec(Node *head, int i){
    if (head == NULL){
        return NULL;
    }
    if (i==0){
        Node *LL = head->next;
        delete head;
        return LL;
    } else {
        Node *x = deleteNodeRec(head->next, i-1);
        head->next = x;
        return head;
    }
}