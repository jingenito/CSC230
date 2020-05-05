#include "DLL.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    DLL myList;
    int counter=0;
    int dCounter=0;
    
    myList.insert("30", "Jack Eblin",  counter);
    myList.insert("40", "Liz Smith", counter);
    myList.insert("10", "Mike Dutter", counter);
    myList.insert("20", "Kitty Lekberg", counter);
    myList.insert("50", "Carma Meshew", counter);

    cout << "After insertion, we should have 10 20 30 40 50 in order" << endl;
    myList.display();
    
    cout << "Searching 30 in the list, result should be 2" << endl;
    cout << myList.search("30") << endl;
    
    myList.remove("10", dCounter);
    myList.remove("50", dCounter);
    
    cout <<"After deletion, we should have 20 30 40 in order"<< endl;
    myList.display();
    
    
    cout << "Testing copy constructor" << endl;
    DLL* temp = new DLL(myList);
    
    cout << "Contents of the original list" << endl;
    myList.display();
    
    cout << "Contents of the new list, the memory address of the this list must be different from the original list" << endl;
    
    if (myList.getHeadPtr() != nullptr) {
        temp->display();
    }
    
    return 0;
    
    
}