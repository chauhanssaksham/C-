Node *bubble_sort_LinkedList_itr(Node *head){
    bool swapTaken;
    Node *temp;
    while(1){
        swapTaken = false;
        if (head->data > head->next->data){
            //Swap Head and the next
            Node *swap2 = head->next;
            Node *after2 = swap2->next;
            swap2->next = head;
            head->next = after2;
            head = swap2;
            swapTaken = true;
        }
        Node *before1 = head;
        while (before1->next->next!=NULL){
            if (before1->next->data > before1->next->next->data){
                //Swap
                Node *swap1 = before1->next;
                Node *swap2 = swap1->next;
                Node *after2 = swap2->next;
                swap1->next = after2;
                swap2->next = swap1;
                before1->next = swap2;
                swapTaken = true;
            }
            before1 = before1->next;
        }
        if (!swapTaken){
            break;
        }
    }
    return head;
}
