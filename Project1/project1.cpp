#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node{
    char chr;
    bool solution;
} gridNode;

//verticle functions
void checkUpDown(vector<vector<Node>> &, char*);
bool checkVerticle(vector<vector<Node>> &, char*, int, int, bool);
void drawVerticle(vector<vector<Node>> &, int, int, int);
//horizontal functions
void checkLeftRight(vector<vector<Node>> &, char*);
void drawLeftRight(vector<vector<Node>> &, int, int, int);
bool checkHorizontal(vector<vector<Node>> &, char*, int, int, bool);
//output function
void printMatrix(vector<vector<Node>> &);

int main(int argc, char **argv)
{
    //read size from the input file
    int x, y;
    cin >> x;
    cin >> y;

    //initialize the char matrix
    vector< vector<Node> > matrix;
    matrix.resize(x);
    //read the matrix from the input file
    for(int i = 0; i < x; ++i){
        matrix[i].resize(y);

        for(int j = 0; j < y; ++j){
            //create the node and insert to the matrix
            Node n;
            cin >> n.chr;
            n.solution = false;
            matrix[i][j] = n;
        }
    }

    //loop over the input arguments excluding the name of the program
    for(int i = 1; i < argc; ++i){
        //check every direction
        checkLeftRight(matrix, *(argv + i));
        checkUpDown(matrix, *(argv + i));
    }

    printMatrix(matrix);

    return 0;
}

void checkUpDown(vector<vector<Node>> &matrix, char* word){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if(!matrix[i][j].solution){
                if (checkVerticle(matrix, word, i, j, true) ){
                    drawVerticle(matrix, i, i + strlen(word) - 1, j);
                }else if ( checkVerticle(matrix, word, i, j, false) ){
                    drawVerticle(matrix, i - strlen(word) + 1, i, j);
                }
            }
        }
    }
}

bool checkVerticle(vector<vector<Node>> &matrix, char* word, int x, int y, bool topDown){
    if(topDown){
        //adjust the end index
        int endInd = x + strlen(word) - 1;
        if (endInd >= matrix.size()){ return false; }

        for(int i = x; i <= endInd; ++i){
            int ind = i - x;
            if(matrix[i][y].chr != *(word + ind)){ return false; }
        }
    }else{
        //adjust the end index
        int endInd = x - strlen(word) + 1;
        if (endInd < 0){ return false; }

        for(int i = x; i >= endInd; --i){
            int ind = x - i;
            if(matrix[i][y].chr != *(word + ind)){ return false; }
        }
    }

    return true;
}

void drawVerticle(vector<vector<Node>> &matrix, int startRow, int endRow, int col){
    for(int i = startRow; i <= endRow; ++i){
        matrix[i][col].solution = true;
    }
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
        //adjust the end index
        int endInd = y + strlen(word) - 1;
        if (endInd >= matrix[0].size()){ return false; }
        
        for(int i = y; i <= endInd; ++i){
            int ind = i - y;
            if(matrix[x][i].chr != *(word + ind)){ return false; }
        }
    }else{
        //adjust the end index
        int endInd = y - strlen(word) + 1;
        if (endInd < 0){ return false; }

        for(int i = y; i >= endInd; --i){
            int ind = y - i;
            if(matrix[x][i].chr != *(word + ind)){ return false; }
        }
    }

    return true;
}

//only print characters in the solution - add * to excluded chars
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
