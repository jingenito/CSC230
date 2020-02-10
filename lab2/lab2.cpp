#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

bool check (vector< vector<char> > &matrix, char *word, int x, int y){
    if(x >= matrix.size()){ return false; }

    for(int i = y; i < matrix[x].size(); ++i){
        if(matrix[x][i] != *(word + (i - y))) {return false; }
    }

    return true;
}

int main(int argc, char *argv[])
{
    int x, y;

    cin >> x;
    cin >> y;

    char *argWord = argv[1];
    int argX = strtol(argv[2], nullptr, 0);
    int argY = strtol(argv[3], nullptr, 0);

    vector< vector<char> > arr;
    arr.resize(x);

    for(int i = 0; i < x; ++i){
        arr[i].resize(y);

        for(int j = 0; j < y; ++j){
            cin >> arr[i][j];
        }
    }

    if( check(arr, argWord, argX, argY) ){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}