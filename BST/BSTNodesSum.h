#include <stack>
using namespace std;
int countNodes(BinaryTreeNode<int>*root){
    if (root==NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    stack<BinaryTreeNode<int>*> inOrder;
    BinaryTreeNode<int>* temp = root;
    while(temp!=NULL){
        inOrder.push(temp);
        temp=temp->left;
    }
    stack<BinaryTreeNode<int>*> reverseInOrder;
    temp = root;
    while(temp!=NULL){
        reverseInOrder.push(temp);
        temp=temp->right;
    }
    int n = countNodes(root);
    int large, small;
    for(int i=0; i<n;){
        large = reverseInOrder.top()->data;
        small = inOrder.top()->data;
        if (small == large){
            temp = inOrder.top();
            inOrder.pop();
            if (temp->right!=NULL){
                temp = temp->right;
                while(temp!=NULL){
                    inOrder.push(temp);
                    temp=temp->left;
                }
            }
            continue;
        }
        if (small + large == s){
            i += 2;
            cout << small << " " << large << endl;
            temp = inOrder.top();
            inOrder.pop();
            if (temp->right!=NULL){
                temp = temp->right;
                while(temp!=NULL){
                    inOrder.push(temp);
                    temp=temp->left;
                }
            }
            temp = reverseInOrder.top();
            reverseInOrder.pop();
            if (temp->left != NULL){
                temp = temp->left;
                while(temp!=NULL){
                    reverseInOrder.push(temp);
                    temp=temp->right;
                }
            }
        } else if (small + large > s){
            i++;
            temp = reverseInOrder.top();
            reverseInOrder.pop();
            if (temp->left != NULL){
                temp = temp->left;
                while(temp!=NULL){
                    reverseInOrder.push(temp);
                    temp=temp->right;
                }
            }
        } else {
            i++;
            temp = inOrder.top();
            inOrder.pop();
            if (temp->right!=NULL){
                temp = temp->right;
                while(temp!=NULL){
                    inOrder.push(temp);
                    temp=temp->left;
                }
            }
        }
    }
}
