void deleteLL(Node *head){
    if (head == NULL){return;}
    deleteLL(head->next);
    delete head;
}
Node* skipMdeleteN(Node  *head, int M, int N) {
    // Write your code here
  Node *current = head;
  Node *temp, *nextInList;
  bool over = false;
    while(current!=NULL){
        for (int i=0; i<M-1; i++){
            if(current->next == NULL){over = true; break;}
            current = current->next;
        }
        if (over){break;}
        temp = current;
        for (int i=0; i<N; i++){
            if (temp->next==NULL){break;}
            temp=temp->next; 
        }
        nextInList = temp->next;
        temp->next = NULL;
        deleteLL(current->next);
        current->next = nextInList;
        current = current->next;
    }
    return head;
}