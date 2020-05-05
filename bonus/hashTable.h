#include <iostream>
#include "SLL.h"
using  namespace  std;

template <class V>
class HashTable {
    int tableSize; // table size
    
    SLL<V>* table;
    
    public:
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which use size as the table size
    HashTable(int size){
      // implement this method
      tableSize = size;
      table = new SLL<V>[tableSize];
    }
    
    // search item in the table
    // if found, return true; otherwise, return false
    bool find(V item){
      // implement this method
      cout << "NOT IMPLEMENTED" << endl;
      return false;
    }
    
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2){
      //implement this method
      cout << "NOT IMPLEMENTED" << endl;
      return false;
    }
    
    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false 
    bool erase(V item){
      // implement this method
      cout << "NOT IMPLEMENTED" << endl;
      return false;
    }

    // return the total number of nodes in the hash table    
    int getSize(){
      // implement this method
      cout << "NOT IMPLEMENTED" << endl;
      return 0;
    }

};
