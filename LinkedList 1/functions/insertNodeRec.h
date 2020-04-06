
Node *insertNodeRec(Node *head, int i, int data){
    if (head == NULL){
        if (i==0){
            Node *newNode = new Node(data);
            return newNode;
        } else {
            return NULL;
        }
    }
    if (i==0){
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    } else {
        head->next = insertNodeRec(head->next, i-1, data);
        return head;
    }
}