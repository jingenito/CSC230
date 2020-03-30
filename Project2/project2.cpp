#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Person{
    string SSN;
    string Name;
    bool empty = true;
};

unsigned inserted = 0;
unsigned deleted = 0;
unsigned retrieved = 0;

void AppendData(unsigned&, Person*&, Person*&);
void DeleteData(unsigned&, Person*&, Person*&);
void RemoveAt(unsigned, Person*&, unsigned);
void RetrieveData(unsigned, Person*, Person*);

int main(int argc, char** argv)
{
    if(argc < 2){ return 0; }

    //intialize variables
    clock_t start, end;
    double duration;

    char chr;
    string ssn, fname, lname;

    start = clock();

    unsigned dataSize = 1000;
    Person* dataV = new Person[dataSize];

    fstream input(*(argv + 1));
    while(!input.eof()){
        //read the input line
        input >> chr >> ssn >> fname >> lname;

        Person* p = new Person;
        p->empty = false;
        p->SSN = ssn;
        p->Name = fname + " " + lname;

        switch(chr){
            case 'i':
                AppendData(dataSize, dataV, p);
                break;
            case 'r':
                RetrieveData(dataSize, dataV, p);
                break;
            case 'd':
                DeleteData(dataSize, dataV, p);
                break;
        }
    }
    input.close(); //close the file stream

    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;

    unsigned itemsC = inserted - deleted;
    cout << "The Number of Valid Insertation: " << inserted << endl;
    cout << "The Number of Valid Deletion: " << deleted << endl;
    cout << "The Number of Valid Retrieval: " << retrieved << endl;
    cout << "Item numbers in the array: " << itemsC << endl;
    cout << "Array Size is: " << dataSize << endl;
    cout << "Time elapsed: " << duration << endl;
    
    return 0;
}

void AppendData(unsigned& dataC, Person*& dataV, Person*& data)
{
    for(unsigned i = 0; i < dataC; ++i){
        Person p = dataV[i];
        if(p.empty){
            dataV[i] = *data;
            inserted++;
            return;
        }else if(p.SSN == data->SSN){
            return;
        }
    }

    unsigned oldC = dataC;
    dataC *= 2;
    Person* temp = dataV; //create a copy of the dataV to delete

    dataV = new Person[dataC]; //create a new array thats double the size
    for(unsigned i = 0; i < oldC; ++i){
        dataV[i] = temp[i];
    }

    dataV[oldC] = *data; //insert the data into the position of the old size
    inserted++;
    delete[] temp;
}

void DeleteData(unsigned& dataC, Person*& dataV, Person*& data)
{
    unsigned last = 0;
    bool deletedEntry = false;

    for(unsigned i = 0; i < dataC; ++i){
        Person p = dataV[i];
        
        if(!p.empty && p.SSN == data->SSN && p.Name == data->Name){
            RemoveAt(dataC, dataV, i);
            deleted++;
            deleted = true;
        }else if(p.empty){
            last = i;
            break;
        }
    }
    
    if(deletedEntry){
        //last needs to be casted as a double to not truncate the output
        double prop = (double)last / dataC;
        if(prop < 0.25){
            dataC /= 2;
            Person* temp = dataV; //create a copy of the dataV to delete

            dataV = new Person[dataC]; //create a new array thats half the size
            for(unsigned i = 0; i < dataC; ++i){
                dataV[i] = temp[i];
            }

            delete[] temp;
        }
    }
}

void RemoveAt(unsigned dataC, Person*& dataV, unsigned index){
    for(unsigned i = index; i < dataC - 1; ++i){
        dataV[i] = dataV[i + 1];
    }
}

void RetrieveData(unsigned dataC, Person* dataV, Person* data)
{
    for(unsigned i = 0; i < dataC; ++i){
        Person p = dataV[i];
        if(!p.empty && p.SSN == data->SSN && p.Name == data->Name){
            retrieved++;
            return;
        }
    }
}