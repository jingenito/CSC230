#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person{
    string SSN;
    string Name;
    bool empty = true;
};

unsigned inserted = 0;
unsigned deleted = 0;
unsigned retrieved = 0;

void AppendData(unsigned&, Person*&, Person&);
void DeleteData(unsigned&, Person*&, Person&);
void RemoveAt(unsigned, Person*&, unsigned);
void RetrieveData(unsigned, Person*, Person);

int main(int argc, char** argv)
{
    unsigned dataSize = 1000;
    Person* dataV = new Person[dataSize];
    
    unsigned count = 1000;
    for(unsigned i = 0; i <= dataSize; ++i){
        Person p;
        p.empty = false;
        p.Name = "test";
        p.SSN = "0";

        AppendData(count, dataV, p);
    }

    cout << count << endl;
}

void AppendData(unsigned& dataC, Person*& dataV, Person& data)
{
    for(unsigned i = 0; i < dataC; ++i){
        Person p = dataV[i];
        if(p.empty){
            dataV[i] = data;
            inserted++;
            return;
        }else if(p.SSN == data.SSN){
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

    dataV[oldC] = data; //insert the data into the position of the old size
    inserted++;
    delete[] temp;
}

void DeleteData(unsigned& dataC, Person*& dataV, Person& data)
{
    unsigned last = 0;

    for(unsigned i = 0; i < dataC; ++i){
        Person p = dataV[i];
        if(!p.empty && p.SSN == data.SSN && p.Name == data.Name){
            RemoveAt(dataC, dataV, i);
            deleted++;
        }else if(p.empty){
            last = i;
            break;
        }
    }

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

void RemoveAt(unsigned dataC, Person*& dataV, unsigned index){
    cout << "Not Implemented Exception - RemoveAt" << endl;
}

void RetrieveData(unsigned dataC, Person* dataV, Person data)
{
    for(unsigned i = 0; i < dataC; ++i){
        Person p = dataV[i];
        if(!p.empty && p.SSN == data.SSN && p.Name == data.Name){
            retrieved++;
            return;
        }
    }
}