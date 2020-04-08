#include "BinaryTreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

class BST{
    BinaryTreeNode<int> *root;

    bool hasData(int data, BinaryTreeNode<int>*root){
         if(root==NULL){
            return false;
        }
        if (root->data == data){
            return true;
        } else if (data < root->data){
            return hasData(data, root->left);
        } else {
            return hasData(data, root->right);
        }
    }
    BinaryTreeNode<int> *insert(BinaryTreeNode<int>* root, int data){
        if (root == NULL){
            BinaryTreeNode<int>* Node = new BinaryTreeNode<int>(data);
            return Node;
        }
        if (data < root->data){
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
    BinaryTreeNode<int>*findMinNode(BinaryTreeNode<int>*root){
        if (root==NULL){
            return NULL;
        }
        while (root->left != NULL){
            root=root->left;
        }
        return root;
    }
    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>*root, int data){
        if(root==NULL){
            return NULL;
        }
        if (data<root->data){
            root->left = deleteData(root->left, data);
            return root;
        } else if ( data > root->data){
            root->right = deleteData(root->right, data);
            return root;
        } else {
            //Node to be deleted!
            if (root->left == NULL && root->right==NULL){
                //Leaf Node
                delete root;
                return NULL;
            } else if (root->left == NULL && root->right != NULL){
                //Only right subtree is present
                BinaryTreeNode<int>* rightTree = root->right;
                root->right= NULL;
                delete root;
                return rightTree;
            }
            else if (root->right == NULL && root->left  != NULL){
                //Only left subtree is present
                BinaryTreeNode<int>* leftTree = root->left;
                root->left= NULL;
                delete root;
                return leftTree;
            } else { 
                // both children are present
                BinaryTreeNode<int> *minNode = findMinNode(root->right);
                root->data = minNode->data;
                root->right = deleteData(root->right, root->data);
                return root;
            }
        }
    }
    
    public:
    BST(){
        root=NULL;
    }

    ~BST(){
        delete root;
    }

    bool hasData(int data){
        return hasData(data, root);
    }

    void insert(int data){
        root = insert(root, data);
    }

    void deleteData(int data){
        deleteData(root, data);
    }

    void printTreeLevelWise(){
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
};