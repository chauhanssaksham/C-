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