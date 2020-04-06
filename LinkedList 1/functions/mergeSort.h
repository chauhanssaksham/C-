#include "midpoint_linkedlist.cpp"
#include "mergeTwoLLs.cpp"

Node *mergeSort(Node *head){
    if (head->next == NULL || head == NULL){
        return head;
    }
    Node *MidPoint = midpoint_linkedlist(head);
    Node *head2 = MidPoint->next;
    MidPoint->next= NULL;
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return mergeTwoLLs(head, head2);
}