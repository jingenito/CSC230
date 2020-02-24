#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node{
    char chr;
    bool solution;
} gridNode;

void checkLeftRight(vector<vector<Node>> &, char*);
void drawLeftRight(vector<vector<Node>> &, int, int, int);
bool checkHorizontal(vector<vector<Node>> &, char*, int, int, bool);
void printMatrix(vector<vector<Node>> &);

int main(int argc, char **argv)
{
    //get all command arguments
    char* args[10];
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
            n.solution = false;
            matrix[i][j] = n;
        }
    }

    for(int i = 0; i < argc - 1; ++i){
        checkLeftRight(matrix, *(args + i));
    }

    printMatrix(matrix);

    return 0;
}

void checkLeftRight(vector<vector<Node>> &matrix, char* word){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if (!matrix[i][j].solution){
                if (checkHorizontal(matrix, word, i, j, true) ){
                    drawLeftRight(matrix, i, j, j + strlen(word) - 1);
                }else if ( checkHorizontal(matrix, word, i, j, false) ){
                    drawLeftRight(matrix, i, j - strlen(word) + 1, j);
                }
            }
        }
    }
}

void drawLeftRight(vector<vector<Node>> &matrix, int row, int startCol, int endCol){
    for(int i = startCol; i <= endCol; ++i){
        matrix[row][i].solution = true;
    }
}

bool checkHorizontal(vector<vector<Node>> &matrix, char* word, int x, int y, bool ltr){
    if(ltr){
        int endInd = y + strlen(word) - 1;
        if (endInd >= matrix[0].size()){ return false; }
        
        for(int i = y; i <= endInd; ++i){
            int ind = i - y;
            if(matrix[x][i].chr != *(word + ind)){ return false; }
        }
    }else{
        int endInd = y - strlen(word) + 1;
        if (endInd < 0){ return false; }

        for(int i = y; i >= endInd; --i){
            int ind = y - i;
            if(matrix[x][i].chr != *(word + ind)){ return false; }
        }
    }

    return true;
}

void printMatrix(vector<vector<Node>> &matrix){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if(matrix[i][j].solution){
                cout << matrix[i][j].chr << " ";
            }else{
                cout << "* ";
            }
        }
        cout << endl;
    }
}
