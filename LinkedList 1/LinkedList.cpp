#include <iostream>
using namespace std;
#include "Node.cpp"
#include "functions/bubble_sort_LinkedList_itr.cpp"

Node* takeInput(){
    Node *head = NULL;
    int n;
    cin >> n;
    if (n==-1){
        return head;
    } else {
        Node *newNode = new Node(n);
        head = newNode;
    }
    Node *temp = head;
    cin>>n;
    while (n != -1){
        Node *newNode = new Node(n);
        temp->next = newNode;
        temp = temp->next;
        cin >> n;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main(){
    //Statically
    // Node n1(1);
    // Node *head = &n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;
    // cout << n1.data << n2.data;
    // cout << head->data << head->next->data << endl;

    int x;
    cout << "Enter the list1: ";
    Node *head1 = takeInput();
    // cout << endl << "Enter the number to append: ";
    // cin >> x;
    // head = insertNodeRec(head, x, 100);
    Node* merge = bubble_sort_LinkedList_itr(head1);
    print(merge);
    return 0;
}