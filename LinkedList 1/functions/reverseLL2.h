Pair reverseLL2(Node *head){
    if (head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverseLL2(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    smallAns.tail=head;
    return smallAns;
}