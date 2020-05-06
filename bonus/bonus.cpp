#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2){ return 0; } //needs an input file to read data from
    
    HashTable<string>* theTable = new HashTable<string>(10007);   

    //intialize variables
    int inserted = 0;
    int deleted = 0;
    int retrieved = 0;
    clock_t start, end;
    double duration;
    
    char chr;
    string ssn, fname, lname;
    start = clock(); //start the clock
    fstream input(argv[1]);
    while(!input.eof()){
      //read the input line
      input >> chr >> ssn >> fname >> lname;
      switch(chr){
        case 'i' :
          if(theTable->insert(ssn, fname + " " + lname)){
            inserted++;
          }else{
            inserted--;
          }
          break;
        case 'r' :
          if(theTable->find(ssn)){
            retrieved++;
          }else{
            retrieved--;
          }
          break;
        case 'd' :
          if(theTable->erase(ssn)){
            deleted++;
          }else{
            deleted--;
          }
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
