void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        if (front != NULL){
            cout << front->data << " ";
            if (front->left != NULL){
                pendingNodes.push(front->left);
            }
            if (front->right != NULL){
                pendingNodes.push(front->right);
            }
        }
        else{
            if(!pendingNodes.empty()){
            cout << endl;
            pendingNodes.push(NULL);
            }
        }
    }
}