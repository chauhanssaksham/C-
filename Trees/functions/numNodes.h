#include "../TreeNode.h"

int numNode(NodeTree<int>* root){
    int ans = 1;
    for (int i=0; i<root->children.size(); i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}