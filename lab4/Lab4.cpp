/** Joe Ingenito  */

/* CSC230-02 */

/* Lab 4  */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
    string SSN;
    string Name;
};

int main(int argc, char** argv){
    //initialize variables
    char chr;
    string ssn, fname, lname;

    Node arr[1000]; //initialize the array to size 1000

    int _counter = 0; //initialize the loop counter
    fstream input(*(argv + 1));
    while(!input.eof()){
        Node n; //create the node

        //read the input line
        input >> chr >> ssn >> fname >> lname;
        n.SSN = ssn;
        n.Name = fname + lname;
        
        //add the node to the array
        arr[_counter] = n;
        _counter++;
    }

    input.close(); //close the file stream

    string inputSSN;
    cout << "Enter a SSN:" << endl;
    cin >> inputSSN;

    for(int i = 0; i < _counter; ++i){
        if(inputSSN.compare(arr[i].SSN) == 0){
            cout << "Found at location " << i << endl;
            break;
        }
    }

    return 0;
}