Node *deleteNode(Node *head, int i){
    if (i==0){
        Node *temp = head->next;
        delete head;
        return temp;
    }
    Node *temp = head;
    for(int x=0; x<i-1 && temp->next!=NULL; x++){
        temp = temp->next;
    }
    if (temp->next == NULL){
        return head;
    }
    Node *nextNode = temp->next;
    temp->next = nextNode->next;
    delete nextNode;
    return head;
}