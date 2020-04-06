//THIS CODE IS WRONG!!!!

Node *swap_nodes(Node *head, int i, int j){
    if (j < i){
        int temp = j;
        j=i;
        i=temp;
    }
    if (j-i == 1){
        //Swapping consecutive nodes
        if (i==0){
            Node *swap2 = head->next;
            Node *after2 = swap2->next;
            swap2->next = head;
            head->next = after2;
            return swap2;
        } else {
            Node *before2 = head;
            for (int x=0; x<i-1;x++){
                before2=before2->next;
            }
            Node* swap1= before2->next;
            Node*swap2 = swap1->next;
            Node*after2 = swap2->next;
            swap1->next = after2;
            swap2->next = swap1;
            before2->next = swap2;
            return head;
        }
    } else {
        if (i==0){
            //Swapping head with another node
            Node*before2 = head;
            for (int x=0; x<j-1; x++){
                before2=before2->next;
            }
            Node *after1=head->next;
            Node *swap2 = before2->next;
            head->next = swap2->next;
            swap2->next = after1;
            before2->next = head;
            return swap2;
        } else {
            //General Case
            Node *before1 = head;
            for (int x=0; x<i-1; x++){
                before1 = before1->next;
            }
            Node *before2 = before1;
            for (int x=0; x<j-i; x++){
                before2=before1->next;
            }
            Node *swap1 = before1->next;
            Node *swap2 = before2->next;
            Node*after1 = swap1->next;
            Node *after2 = swap2->next;
            swap2->next = after1;
            swap1->next = after2;
            before1->next = swap2;
            before2->next = swap1;
            return head;
        }
    }
}