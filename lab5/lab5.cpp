/* Joe Ingenito */

/* CSC230-02 */

/* Lab 5 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
    string SSN;
    string Name;
    Node* nextNodePtr;
};

void AppendNode(Node* &, Node* &);
void SearchNode(Node*, string);

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
        
        AppendNode(headNode, n);
    }

    input.close(); //close the file stream

    string inputSSN;
    cout << "Enter a SSN:" << endl;
    cin >> inputSSN;

    SearchNode(headNode, inputSSN);

    return 0;
}

void AppendNode(Node* &headNode, Node* &addNode){
    if(!headNode){
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
    if(headNode){
        int pos = 1; //initialize position counter to 1
        Node* n = headNode;
        while(n){
            if(!SSN.compare(n->SSN)){ 
                cout << "Found at location " << pos << " belongs to " << n->Name << endl;
                return;
            }
            pos++;
            n = n->nextNodePtr;
        }
    }
}