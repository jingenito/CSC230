#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Node{
    char chr;
    bool included;
} gridNode;

// bool check (vector< vector<char> > &matrix, char *word, int x, int y){
//     if(x >= matrix.size()){ return false; }

//     for(int i = y; i < matrix[x].size(); ++i){
//         if(matrix[x][i] != *(word + (i - y))) {return false; }
//     }

//     return true;
// }

int main(int argc, char **argv)
{
    //get all command arguments
    char **args;
    for(int i = 1; i < argc; ++i){
        *(args + (i-1)) = *(argv + i);
    }

    //read size from the input file
    int x, y;
    cin >> x;
    cin >> y;

    //fill the two dimensional array from the input file
    vector< vector<Node> > matrix;
    matrix.resize(x);

    for(int i = 0; i < x; ++i){
        matrix[i].resize(y);

        for(int j = 0; j < y; ++j){
            Node n;
            cin >> n.chr;
            n.included = false;
            matrix[i][j] = n;
        }
    }

    //check all rows LTR


    //check all rows TRL

    return 0;
}

bool checkAscending(vector<vector<Node>> &matrix, char *word, int x, int y){
    if(x >= matrix.size()){ return false; }

    for(int i = y; i < matrix[x].size(); ++i){
        if(matrix[x][i].chr != *(word + (i - y))) {return false; }
    }

    return true;
}