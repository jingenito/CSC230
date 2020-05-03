#include "treeNode.h"
#include <iomanip>

template <class V>
class tree {
    TreeNode<V> * root;
    int size;
    
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
        treeSearch(x, root);
    }
    

    // binary search value x in tree rooted at node t
    bool treeBSearch(V x, TreeNode<V>* t){

      // implement this method
      return false;
    }
    
    bool treeBSearch(V x){
        return treeBSearch(x, root);
    }
    
    // check node t is leaf
    bool isLeaf(TreeNode<V>* t){

      //implement this method
      return false;
    }
    
    // find the height of the tree rooted at node t
    int height(TreeNode<V>* t){
      //implement this method
      return 0;
    }
    
    int height(){
        return height(root);
    }
    
    // find the number of nodes of tree rooted at t
    int nNodes(TreeNode<V>* t){
      //implement this method
      return 0;
    }
    
    int nNodes(){
        return nNodes(root);
    }

    // insert value x to the current tree object
    void insert(V x){
        if(root){ 
            root = x; //set the root to x if its null
        }else if(root->getDatum() > x){
            //insert left subtree
            TreeNode<V>*t = root->getLeft();
            while(!t){
                t = t->getLeft();
            }
        }else{

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
