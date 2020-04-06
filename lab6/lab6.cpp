/* Joe Ingenito */

/* CSC230-02 */

/* Lab 6 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
    string SSN;
    string Name;
    Node* nextNodePtr;
    Node* prevNodePtr;
};

void AppendNode(Node* &, Node* &);
void SearchNode(Node*, string);
void InsertNode(Node* &, Node* &);
void PrintList(Node*&);

int main(int argc, char** argv){
    //initialize variables
    char chr;
    string ssn, fname, lname;
    Node* headNode = NULL; 

    fstream input(*(argv + 1));
    while(!input.eof()){
        Node* n = new Node; //create the node

        //read the input line
        input >> chr >> ssn >> fname >> lname;
        n->SSN = ssn;
        n->Name = fname + " " + lname;
        
        InsertNode(headNode, n);
    }

    input.close(); //close the file stream

    string inputSSN;
    cout << "Input a SSN:" << endl;
    cin >> inputSSN;

    SearchNode(headNode, inputSSN);
    PrintList(headNode);

    return 0;
}

void AppendNode(Node* &headNode, Node* &addNode){
    if(headNode == NULL){
        headNode = addNode;
    }else{
        Node* n = headNode;
        while(n->nextNodePtr != NULL){
            n = n->nextNodePtr;
        }
        n->nextNodePtr = addNode;
    }
}

void SearchNode(Node* headNode, string SSN){
    if(headNode != NULL){
        int pos = 0; 
        Node* n = headNode;
        while(n != NULL){
            if(!SSN.compare(n->SSN)){ 
                cout << "Found at: " << pos << endl;
                return;
            }
            pos++;
            n = n->nextNodePtr;
        }
        cout << -1 << endl;
    }
}

void InsertNode(Node* &headNode, Node* &addNode){
    if(headNode == NULL){
        headNode = addNode;
    }else{
        Node* n = headNode;

        while(n->nextNodePtr != NULL){
            if(n->SSN < addNode->SSN){
                n = n->nextNodePtr;
            }else if(n == headNode){
                //addNode becomes headNode
                Node* temp = headNode;
                
                headNode = addNode;
                headNode->nextNodePtr = temp;
                temp->prevNodePtr = headNode;

                return;
            }else{
                //insert addNode before n
                Node* temp = n->prevNodePtr;

                addNode->nextNodePtr = n;
                n->prevNodePtr = addNode;
                temp->nextNodePtr = addNode;
                addNode->prevNodePtr = temp;
                
                return;
            }
        }

        //append addNode to the end of the list
        n->nextNodePtr = addNode;
        addNode->prevNodePtr = n;
    }
}

void PrintList(Node* &headNode){
    cout << "List of contents:" << endl;

    Node* n = headNode;
    while(n != NULL){
        cout << n->SSN << endl;
        n = n->nextNodePtr;
    }
}