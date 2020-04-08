#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout <<"Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i=0; i<numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void postOrder(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output in specified format.
     */
	for(int i=0; i<root->children.size(); i++){
      postOrder(root->children[i]);
    }
  cout << root->data << " ";
}

void printTreeLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> printingQueue;
    printingQueue.push(root);
    while(!printingQueue.empty()){
        TreeNode<int>* front = printingQueue.front();
        printingQueue.pop();
        cout << front->data << ": ";
        for (int i=0; i<front->children.size(); i++){
            cout << front->children[i]->data << ", ";
            printingQueue.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int>* takeInputDFS(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout <<"Enter the number of children of " << rootData << endl;
    cin >> n;
    for (int i=0; i<n; i++){
        TreeNode<int>* child = takeInputDFS();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << ":";
    for (int i=0; i<root->children.size(); i++){
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
}