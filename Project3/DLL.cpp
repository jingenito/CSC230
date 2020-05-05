#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor is already implemented
// do not modify the default constructor
DLL::DLL(){
    headPtr = nullptr;
    itemCount=0;
}

// return the head pointer of the list
// it is already implemented, do not modify it
Node* DLL::getHeadPtr(){
    return headPtr;
}

// copy construct, which copies an existing list n
// the new list is a different object from n
// the new list and object n have the same contents
// Please implement it
DLL::DLL(DLL& n){
    int count = 0; //for insert function
    Node* p = n.getHeadPtr();
    //copy all succeeding values
    while(p != nullptr){
        insert(p->ssn,p->name,count); 
        p = p->succ;
    }
}

// destructor
// release every node of the list
// Please implement it
DLL::~DLL(){
    Node* t = headPtr;
    while(t){
        Node* temp = t;
        t = t->succ;
        delete temp;
    }
    delete t;
}

// if some node has SSN matcthes string ss
// return the index value of the node
// the index value of the first node is 0, the second node is 1, etc.
// if there is node matching ss, return -1
int DLL::search(string ss)const{
    Node* t = headPtr;
    int ind = 0;
    while(t != nullptr){
        if(ss.compare(t->ssn) == 0){
            return ind;
        }else{
            ind++;
        }
        t = t->succ;
    }
    return -1;
}


// insert (ss, name) to the existing list
// the SSN values are each node are organized in INCREASING order
// if there is a node matching ss value, return false; otherwise true
// else create a node with (ss, name), insert the node to the proper position
// parameter count is the counter of number of valid insertion
// when you implement this method, consider the following situations:
// 1. list is empty
// 2. node should be inserted to the beginning of the list
// 3. node should be inserted to the middle of the list
// 4. node should be inserted to the end of the list
bool DLL::insert(string ss, string name, int & count){
    if(headPtr == nullptr){
        //list is empty set the headptr
        Node* n = new Node();
        n->name = name;
        n->ssn = ss;
        headPtr = n;
        //update counters
        count++;
        itemCount++;
        return true;
    }else{
        Node* n = headPtr;
        while(n->succ != nullptr){
            if(ss.compare(n->ssn) == 0){ return false; } //check for existing ssn

            if(ss.compare(n->ssn) > 0){
                n = n->succ;
            }else if(n == headPtr){
                //beginning of the list
                //new node is new headptr
                Node* temp = headPtr;
                //create a new node
                Node* p = new Node();
                p->ssn = ss;
                p->name = name;
                //insert the node
                headPtr = p;
                headPtr->succ = temp;
                temp->pred = headPtr;
                //update counters
                count++;
                itemCount++;
                return true;
            }else{
                //insert into the middle of the list
                //create a new node
                Node* p = new Node();
                p->ssn = ss;
                p->name = name;
                Node* temp = headPtr; //create a temp copy of head
                //insert p into the list
                p->succ = n;
                n->pred = p;
                temp->succ = p;
                p->pred = temp;
                //update counters
                count++;
                itemCount++;
                return true;                
            }
        }

        //append new node to the end of the list
        Node* p = new Node();
        p->ssn = ss;
        p->name = name;

        n->succ = p;
        p->pred = n;

        //update counters
        count++;
        itemCount++;
        return true;
    }

    return false; //this should never happen
}


// remove node containing ss value
// if there is no node containing ss, return false; otherwise true
// consider the following situations:
// 1. list is empty
// 2. node containing ss value is the first node
// 3. node containing ss value is in the middle of the list
// 4. node containing ss value is the last node of the list
bool DLL::remove(string ss, int & count){
    Node* n = headPtr;
    while(n != nullptr){
        if(ss.compare(n->ssn) == 0){
            //found ssn to remove
            if(n->pred == nullptr){
                //remove first node
                Node* t = n->succ;
                headPtr = t;
                headPtr->pred = nullptr;
                delete n;
                //update counts
                count++;
                itemCount--;
                return true;
            }else if(n->succ != nullptr){
                //remove node from middle
                //copy pred and succ
                Node* p = n->pred;
                Node* s = n->succ;
                //remove link to n
                p->succ = s;
                s->pred = p;
                delete n;
                //update counts
                count++;
                itemCount--;
                return true;
            }else{
                //remove last node
                Node* t = n->pred;
                t->succ = nullptr;
                delete n;
                //update counts
                count++;
                itemCount--;
                return true;

            }
        }
        n = n->succ;
    }

    return false; //empty list or no match found
}

// return the number of the nodes
// it is already implemented, do not modify it
int DLL::size(){
    
    return itemCount;
}

// iterate through each node
// print out SSN and memory address of each node
// do not modify this method
void DLL::display(){
    Node* temp;
    temp = headPtr;
    while (temp!= nullptr) {
        cout << temp->ssn << "\t" << temp << endl;
        temp = temp->succ;
    }
}
