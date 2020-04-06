Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    if (i==0){
        newNode->next = head;
        return newNode;
    }
    for(int x=0; x<i-1 && temp!= NULL; x++){
        temp = temp->next;
    }
    if (temp != NULL){
    newNode->next = temp->next;
    temp->next= newNode;
    }
    return head;
}