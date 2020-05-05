#include "DLL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
    if(argc < 2){ return 0; }

    //intialize variables
    int inserted = 0;
    int deleted = 0;
    int retrieved = 0;

    clock_t start, end;
    double duration;

    char chr;
    string ssn, fname, lname;

    start = clock();

    DLL theList;

    fstream input(*(argv + 1));
    while(!input.eof()){
        //read the input line
        input >> chr >> ssn >> fname >> lname;
        
        switch(chr){
            case 'i':
                theList.insert(ssn, fname + " " + lname, inserted);
                break;
            case 'r':
                if(theList.search(ssn)){
                    retrieved++;
                }else{
                    retrieved--;
                }
                break;
            case 'd':
                theList.remove(ssn, deleted);
                break;
        }
    }
    input.close(); //close the file stream

    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;

    int itemsC = inserted - deleted;
    cout.precision(5);
    cout << "The Number of Valid Insertation: " << inserted << endl;
    cout << "The Number of Valid Deletion: " << deleted << endl;
    cout << "The Number of Valid Retrieval: " << retrieved << endl;
    cout << "Item numbers in the list: " << itemsC << endl;
    cout << "Time elapsed: " << fixed << duration << endl;
    
    return 0;
}