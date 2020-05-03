#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
class TreeNode{
    T datum;
    TreeNode<T>* left, * right;
    
    public:
    // constructor with datum value, left and right are nullptr
    TreeNode(T x){
        datum=x;
        left = nullptr;
        right = nullptr;
    }
    // constructor with datum value, left and right values
    TreeNode(T x, TreeNode<T>* lft, TreeNode<T>* rgt){
        datum = x;
        left = lft;
        right = rgt;
    }
    
    //destructor releases left and right nodes, if not nullptr
    ~TreeNode(){
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
    
    // get datum value
    T getDatum(){
        return datum;
    }
    
    // get left pointer
    TreeNode<T>* getLeft(){
        return left;
    }
    
    // get right pointer
    TreeNode<T>* getRight(){
        return right;
    }
    
    // set the left pointer
    void setLeft(TreeNode<T>* p){
        left = p;
    }
    
    // set the right pointer
    void setRight(TreeNode<T>* p){
        right = p;
    }
        
};
