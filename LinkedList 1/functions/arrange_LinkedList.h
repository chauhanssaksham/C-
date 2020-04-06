Node *push(Node*head, Node*item){
    if (head == NULL){
        return item;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = item;
    return head;
}
Node* arrange_LinkedList(Node* head)
{
    Node *odd = NULL, *even = NULL, *temp = head, *after = NULL;
	while(temp!=NULL){
        after = temp->next;
        temp->next = NULL;
        if (temp->data % 2 == 0){
            even = push(even, temp);
        } else {
            odd = push(odd, temp);
        }
        temp = after;
    }
    temp = odd;
    if (odd ==NULL){
        return even;
    }
    while (temp->next != NULL){
        temp=temp->next;
    }
    temp->next = even;
    return odd;
}
