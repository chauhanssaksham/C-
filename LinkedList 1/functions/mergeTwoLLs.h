Node * mergeTwoLLs(Node *head1, Node *head2){
    Node  *finalHead;
    Node  *finalTail;
    if (head1->data<head2->data){
        finalHead = head1;
        finalTail = head1;
        head1=head1->next;
    } else {
        finalHead = head2;
        finalTail = head2;
        head2=head2->next;
    }
    while (head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            finalTail->next = head1;
            finalTail=head1;
            head1=head1->next;
        } else {
            finalTail->next = head2;
            finalTail=head2;
            head2=head2->next;
        }
    }
    if (head1 == NULL){
        finalTail->next=head2;
    } else {
        finalTail->next=head1;
    }
    return finalHead;
}