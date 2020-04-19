/* Joe Ingenito */

/* CSC230-02 */

/* Lab 8 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

long hashcode(char*);

int main(int argc, char** argv)
{
    //end function if no input was entered
    if(argc < 2) {return 0;}

    int dataCount = 10007; //store the count of data
    int collisionCount = 0; //store the collision count
    int lineCount = 0; //store a count of the lines read from the input file
    char* data[dataCount + 1];

    fstream input(*(argv + 1)); //create a filestream
    while(!input.eof()){
        char* s;
        input >> s; //get the next line from the filestream
        long hs = hashcode(s) % dataCount; //calculate h(s) mod 10007
        
        if(data[hs]){
            collisionCount++;
        }else{
            data[hs] = s; //storing in a data array to keep track for collisions
        }
        lineCount++;
    }

    input.close(); //close the file stream

    cout << "Total Input is " << lineCount - 1 << endl;
    cout << "Collision # is " << collisionCount << endl;
}

long hashcode(char* s){
    long val = 0;
    int n = strlen(s);
    for(int i = 0; i < n; ++i){
        val += s[i] * pow(31, n - i - 1);
    }
    return val;
}