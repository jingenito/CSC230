#include <iostream>
#include "SLL.h"
using  namespace  std;

template <class V>
class HashTable {
    int tableSize; // table size
    int nodeCount; //node count
    
    SLL<V>* table;
    
    public:
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        nodeCount = 0;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which use size as the table size
    HashTable(int size){
      // implement this method
      tableSize = size;
      nodeCount = 0;
      table = new SLL<V>[tableSize];
    }
    
    // search item in the table
    // if found, return true; otherwise, return false
    bool find(V item){
      // implement this method
      int key = stoi(item) % tableSize;
      Node<V> *n = (*(table + key)).search(item);

      if(n == 0){
        return false;
      }
      return true;
    }
    
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2){
      //implement this method
      int key = stoi(item1) % tableSize;
      (*(table + key)).insert(item1, item2);
      nodeCount++;
      return true;
    }
    
    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false 
    bool erase(V item){
      int key = stoi(item) % tableSize;
      if( (*(table + key)).remove(item) ){
        nodeCount--;
        return true;
      }
      return false;
    }

    // return the total number of nodes in the hash table    
    int getSize(){
      // implement this method
      return nodeCount;
    }

};
