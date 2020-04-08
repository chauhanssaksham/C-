void printTree(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data<< ":";
    if (root->left){
        cout << "L" << root->left->data << " ";
    }
    if (root->right){
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}