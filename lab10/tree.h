#include "treeNode.h"
#include <iomanip>

template <class V>
class tree {
    TreeNode<V> * root;
    int size;

    //inserts the value x starting into the subtree
    void insertAtNode(TreeNode<V>* t, V x){
        if(t->getDatum() > x){
            //insert left
            if(t->getLeft() == nullptr){
                t->setLeft(new TreeNode<V>(x));
                size++;
            }else{
                insertAtNode(t->getLeft(), x);
            }
        }else{
            //insert right
            if(t->getRight() == nullptr){
                t->setRight(new TreeNode<V>(x));
                size++;
            }else{
                insertAtNode(t->getRight(), x);
            }
        }
    }
    
    public:
    // default constructor
    // by default, the tree is empty
    tree(){
        root = nullptr;
        size = 0;
    }

    // search value x in tree rooted at node t    
    bool treeSearch(V x, TreeNode<V>* t){
        if(t == nullptr) return false;
        if(t->getDatum() == x) return true;
        return treeSearch(x, t->getLeft()) || treeSearch(x, t->getRight());
    }
    
    bool treeSearch(V x){
        return treeSearch(x, root);
    }
    

    // binary search value x in tree rooted at node t
    bool treeBSearch(V x, TreeNode<V>* t){
        if(t == nullptr){ return false; }
        if(t->getDatum() == x){ 
            return true; 
        }else if(t->getDatum() > x){
            //search left subtree
            if(t->getLeft()){
                return treeBSearch(x, t->getLeft());
            }
        }else{
            //search right subtree
            if(t->getRight()){
                return treeBSearch(x, t->getRight());
            }
        }
        return false;
    }
    
    bool treeBSearch(V x){
        return treeBSearch(x, root);
    }
    
    // check node t is leaf
    bool isLeaf(TreeNode<V>* t){
      //implement this method
      return t->getLeft() == NULL && t->getRight() == NULL;
    }
    
    // find the height of the tree rooted at node t
    int height(TreeNode<V>* t){
        //implement this method
        int left = 0;
        if(t->getLeft())
            left = height(t->getLeft());
        int right = 0;
        if(t->GetRight())
            right = height(t->getRight());
        return left > right ? left : right;
    }
    
    int height(){
        return height(root);
    }
    
    // find the number of nodes of tree rooted at t
    int nNodes(TreeNode<V>* t){
        //implement this method
        int count = 1; //initialize to 1 to count this node
        //count left subtree
        if(t->getLeft()){
            count += nNodes(t->getLeft());
        }
        //count right subtree
        if(t->getRight()){
            count += nNodes(t->getRight());
        }
        return count;
    }
    
    int nNodes(){
        return nNodes(root);
    }

    // insert value x to the current tree object
    void insert(V x){
        //implement this method
        if(root == nullptr){ 
            root = new TreeNode<V>(x); //set the root to x if its null
            size++;
        }else{
            //size will be updated inside the function
            insertAtNode(root, x);
        }
    }
    
    void traverseInorder(TreeNode<V> *x)
    {
        if (x == nullptr)
            return;
        traverseInorder(x->getLeft());
        cout << x->getDatum() << " ";
        traverseInorder(x->getRight());
    }
    void traverseInorder()
    {
        traverseInorder(root);
        cout<<endl;
    }

    void traversePreorder(TreeNode<V> *x){
        if (x == nullptr)
            return;
        cout << x->getDatum() << " ";
        traversePreorder(x->getLeft());
        traversePreorder(x->getRight());
    }
    void traversePreorder(){
        traversePreorder(root);
        cout<<endl;
    }

    void traversePostorder(TreeNode<V> *x){
        if (x == nullptr)
            return;
        
        traversePostorder(x->getLeft());
        traversePostorder(x->getRight());
        cout << x->getDatum() << " ";
    }
    void traversePostorder(){
        traversePostorder(root);
        cout<<endl;
    } 
    
};
