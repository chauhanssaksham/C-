#include <vector>
class direction{
    public:
    BinaryTreeNode<int> *node;
    char next;
    direction(BinaryTreeNode<int> *node, char next){
        this->node = node;
        this->next = next;
    }
};

void findDirections(BinaryTreeNode<int> *root, int node, vector<direction*> &directions){
    if (root==NULL){
        return;
    }
    if (root->data == node){
        direction *next = new direction(root, 'X');
        directions.push_back(next);
        return;
    }
    //Call directions on left;
    findDirections(root->left, node, directions);
    if (directions.size() > 0){
        direction *next = new direction(root, 'L');
        directions.push_back(next);
        return;
    }
    //Call directions on right
    findDirections(root->right, node, directions);
    if (directions.size() > 0){
        direction *next = new direction(root, 'R');
        directions.push_back(next);
        return;
    }
    return; //Return without anything if nowhere present
}

void printAllAtDist(BinaryTreeNode<int>*root, int dist){
    if (root == NULL || dist < 0){
        return;
    }
    if (dist == 0){
        cout << root->data << endl;
    }
    printAllAtDist(root->left, dist-1);
    printAllAtDist(root->right, dist-1);
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    vector<direction*> directionsToK;
    findDirections(root, node, directionsToK);
    BinaryTreeNode<int>* mainNode = directionsToK[0]->node;
    //Print all the nodes at distance K from the main node first
    printAllAtDist(mainNode->left, k-1);
    printAllAtDist(mainNode->right, k-1);
    for (int i=1; i < directionsToK.size(); i++){
        direction *currentDirection = directionsToK[i];
        //If we took a left for main Node:
        if (i==k){
            printAllAtDist(currentDirection->node, 0);
            break;
        }
        if (currentDirection->next == 'L'){
            printAllAtDist(currentDirection->node->right, k-i-1);
        }
        //If we took a right for main Node:
        else if (currentDirection->next == 'R'){
            printAllAtDist(currentDirection->node->left, k-i-1);
        }
    }
}
