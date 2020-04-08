#include <iostream>
#include "LLnode.h"
#include <queue>
#include "BST.h"
#include "BSTNodesSum.h"
using namespace std;

BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n<=0){
        return NULL;
    }
    int midIndex = (n-1)/2;
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(input[midIndex]);
    BinaryTreeNode<int>*leftTree = constructTree(input, midIndex);
    BinaryTreeNode<int>*rightTree = constructTree(input+midIndex+1, n-midIndex-1);
    root->left = leftTree;
    root->right = rightTree;
    return root;
}

pair <Node<int>*, Node<int>*> constructBSTHelper(BinaryTreeNode<int>*root){
    if (root==NULL){
        return pair <Node<int>*, Node<int>*>(NULL,NULL);
    }
    pair <Node<int>*, Node<int>*> leftLLPair = constructBSTHelper(root->left);
    pair <Node<int>*, Node<int>*> rightLLPair = constructBSTHelper(root->right);
    Node<int>*head;
    Node<int>*tail;
    if (leftLLPair.first == NULL){
        head = new Node<int>(root->data);
        tail = head;
    } else {
        head = leftLLPair.first;
        leftLLPair.second->next = new Node<int>(root->data);
        tail = leftLLPair.second->next;
    }
    if (!(rightLLPair.first == NULL)){
        tail->next = rightLLPair.first;
        tail = rightLLPair.second;
    }
    return pair <Node<int>*, Node<int>*>(head, tail);
}
BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    if (rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftData, rightData;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftData;
        if (leftData != -1){
        BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        cin >> rightData;
        if (rightData != -1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
Node<int>* constructBST(BinaryTreeNode<int>* root) {    //Crete a sorted LL from a BST
    return constructBSTHelper(root).first;
}
void printTreeLevelWise(BinaryTreeNode<int> *root){
    if (root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> printQueue;
    printQueue.push(root);
    while(!printQueue.empty()){
        BinaryTreeNode<int> *front = printQueue.front();
        printQueue.pop();
        cout << front->data << ": ";
        if (front->left){
            cout << " L" << front->left->data;
            printQueue.push(front->left);
        }
        if (front->right){
            cout << " R" << front->right->data;
            printQueue.push(front->right);
        }
        cout << endl;
    }
}
// 1 2 3 4 5 8 -1 9 -1 6 7 -1 -1 -1 10 -1 -1 -1 -1 -1 11 -1 -1
//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//12
int main(){
    BinaryTreeNode<int>*root = takeInputLevelWise();
    printNodesSumToS(root, 12);
    delete root;
    return 0;
}