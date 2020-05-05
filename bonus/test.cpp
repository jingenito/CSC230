#include <iostream>
#include <string>
#include "hashTable.h"

using namespace std;

int main(){
  // Node<string>* temp = new Node<string>;
  SLL<string>* tempSLL = new SLL<string>;
  // HashTable<string>* tempT = new HashTable<string>(10007);
  tempSLL->insert("1", "blah");
  tempSLL->insert("2", "blah2");
  tempSLL->insert("3", "blah3");
  tempSLL->insert("4", "blah4");
  tempSLL->insert("5", "blah 5");
  tempSLL->display();

  cout << "Searching for node 3:" << endl;
  Node<string> *n = tempSLL->search("3");
  if(n == nullptr){
    cout << "nothing found" << endl;
  }else{
    cout << "SSN: " << n->SSN << " Name: " << n->name << endl;
  }

  cout << "Removing node 4" << endl;
  tempSLL->remove("4");

  cout << "The size of the list is " << tempSLL->getSize() << endl;

  tempSLL->display();
  return 0;
}
