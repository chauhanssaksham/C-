TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if (root == NULL){
        return NULL;
    }
    TreeNode<int>* maxNode = root;
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> * x = maxDataNode(root->children[i]);
        if (maxNode->data < x->data){
            maxNode = x; 
        }
    }
    return maxNode;
}