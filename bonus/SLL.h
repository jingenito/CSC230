#include <iostream>
#include "Node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
    public:
    // default constructor
    SLL(){
      //implement this method
      headPtr = nullptr;
      size = 0;
    }

    // destructor    
    ~SLL(){
      // implement this method
      Node<U>* n = headPtr;
      while (n != nullptr)
      {
        Node<U>* temp = n;
        n = n->next;
        delete temp;
      }
      delete n;
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
      //implement this method
      if(headPtr == nullptr){
        //list is empty set the headptr
        Node<U> *n = new Node<U>();
        n->SSN = item1;
        n->name = item2;
        headPtr = n;
        size++;
        return;
      }
      //find the last node in the list
      Node<U> *n = headPtr;
      while(n->next != nullptr){
        n = n->next;
      }
      //create a new node
      Node<U> *p = new Node<U>;
      p->SSN = item1;
      p->name = item2;
      //append the new node to the end of the list
      n->next = p;
      size++;
    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
      Node<U> *n = headPtr;
      while(n != nullptr){
        if(item1 == n->SSN){
          return n;
        }
        n = n->next;
      }
      return nullptr;
    }
    
    // remove the node with key value: item1
    bool remove(U item1){
      //implement this method
      Node<U> *n = headPtr;
      Node<U> *pred = nullptr;
      while(n->next != nullptr && n->SSN != item1){
        pred = n;
        n = n->next;
      }

      if(n->next == nullptr && n->SSN != item1){
        return false; //no match found
      }

      if(n == headPtr && n->next != nullptr){
        //remove the first node
        headPtr = n->next;
        delete n;
        size--;
        return true;
      }else if(n->next != nullptr){
        //remove from the middle
        pred->next = n->next;
        delete n;
        size--;
        return true;
      }else{
        //remove the last node
        pred->next = nullptr;
        delete n;
        size--;
        return true;
      }

      return false; //this should never happen
    }
    
    int getSize(){
        
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};


