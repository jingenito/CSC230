#include <iostream>
#include <cstring>

using namespace std;

void DeleteAtIndex(char* str, int index){
    for(int i = index; i < strlen(str); ++i){
        *(str + i) = *(str + i + 1);
    }
}

void ReadInput(char* input){
    for(int i = 0; i < 5; ++i){
        cin >> input[i];
    }
}

void PrintOutput(char* output){
    for(int i = 0; i < strlen(output); ++i){
        cout << output[i] << " ";
    }
}

int main()
{
    char str[50];
    int ind;

    ReadInput(str);
    cin >> ind;

    DeleteAtIndex(str, ind);
    PrintOutput(str);
}