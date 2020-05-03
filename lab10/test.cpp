/** Joe Ingenito  */

/** CSC230-02 */

/** Lab 10 */

#include "tree.h"

int main(){
    
    tree<int> myTree;
    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(7);
    myTree.insert(9);
    
    cout << myTree.treeBSearch(9) << endl;
    cout << myTree.treeBSearch(11) << endl;
    cout << "Number of nodes: " << myTree.nNodes() << endl;
    
    cout << "Inorder Traversal: " << endl;
    myTree.traverseInorder();
    cout << "Preorder Traversal: " << endl;
    myTree.traversePreorder();
    cout << "Postorder Traversal: " << endl;
    myTree.traversePostorder();

}