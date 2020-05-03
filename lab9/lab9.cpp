/* Joe Ingenito */

/* CSC230-02 */

/* Lab 9 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Tree Node has data, left pointer, right pointer
struct TreeNode
{
    int datum;
    struct TreeNode* left;
    struct TreeNode* right;
};

// create a new node with given value, left and right pointers are nullptr
struct TreeNode* newTreeNode(int value)
{
    struct TreeNode* node = new struct TreeNode;
    node->datum = value;
    node->left = nullptr;
    node->right = nullptr;
    return(node);
}

// Non-recursive traverse a binary tree
// print out the values by inorder
// it uses stack to store the nodes 
void noRecInorder(TreeNode *root)
{
    stack<TreeNode*> stack;
    
    while(true){
        //push left subtree to stack
        while(root){
            stack.push(root);
            root = root->left;
        }
        
        if(stack.empty()){break;}
        //pop from stack
        root = stack.top();
        stack.pop();

        //print out datum
        cout << root->datum << endl;
        root = root->right;
    }
}

// level order traversal 
// It uses queue to store the values of the next level
void levelOrder(TreeNode *root){
    queue<TreeNode*> queue;

    if(root){queue.push(root);}
    while(!queue.empty()){
        TreeNode* temp;
        temp = queue.front(); //create a temp of the front
        queue.pop(); //dequeue

        //print the datum in temp
        cout << temp->datum << endl;

        //print the level
        if(temp->left){queue.push(temp->left);}
        if(temp->right){queue.push(temp->right);}
    }
}


// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
        100
      /     \
      9      10
     /  \    /
     9   4  7
     */
    struct TreeNode *root = newTreeNode(100);
    root->left        = newTreeNode(9);
    root->right       = newTreeNode(10);
    root->left->left  = newTreeNode(9);
    root->left->right = newTreeNode(4);
    root->right->left = newTreeNode(7);
    
    cout << "Inorder traversal result:" << endl;;
    noRecInorder(root);
    cout << "Level traversal result:" << endl;
    
    levelOrder(root);
    
    return 0;
}
