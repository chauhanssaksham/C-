#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root){
    if (root == NULL){
        return pair<int,int>(0,0);
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lH = leftAns.first;
    int lD = leftAns.second;
    int rH = rightAns.first;
    int rD = rightAns.second;
    int height = 1 + max(lH, rH);
    int diameter = max(lH+rH, max(lD, rD));
    return pair<int,int>(height, diameter);
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

BinaryTreeNode<int> *takeInput(){ //painful method!!!!
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

// 1 2 3 4 5 8 -1 9 -1 6 7 -1 -1 -1 10 -1 -1 -1 -1 -1 11 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    nodesAtDistanceK(root, 4, 3);
    delete root;
    return 0;
}