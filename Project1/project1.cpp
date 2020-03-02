#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node{
    char chr;
    bool solution;
};

void findWord(vector<vector<Node>> &, char*);
void drawWord(vector<vector<Node>> &, char*, int, int, int, int);
bool checkWord(vector<vector<Node>> &, char*, int, int, int, int);
void printMatrix(vector<vector<Node>>);

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
        findWord(matrix, *(argv + i));
    }

    printMatrix(matrix);

    return 0;
}

void findWord(vector<vector<Node>> &matrix, char* word){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            //check all possible directions
            if(checkWord(matrix, word, i, 0, j, 1)){
                drawWord(matrix, word, i, 0, j, 1);
            }
            if(checkWord(matrix, word, i, 0, j, -1)){
                drawWord(matrix, word, i, 0, j, -1);
            }
            if(checkWord(matrix, word, i, 1, j, 0)){
                drawWord(matrix, word, i, 1, j, 0);
            }
            if(checkWord(matrix, word, i, -1, j, 0)){
                drawWord(matrix, word, i, -1, j, 0);
            }
            if(checkWord(matrix, word, i, 1, j, 1)){
                drawWord(matrix, word, i, 1, j, 1);
            }
            if(checkWord(matrix, word, i, 1, j, -1)){
                drawWord(matrix, word, i, 1, j, -1);
            }
            if(checkWord(matrix, word, i, -1, j, -1)){
                drawWord(matrix, word, i, -1, j, -1);
            }
            if(checkWord(matrix, word, i, -1, j, 1)){
                drawWord(matrix, word, i, -1, j, 1);
            }
        }
    }
}

void drawWord(vector<vector<Node>> &matrix, char* word, int x, int delX, int y, int delY){
    int _count = 0;
    while(_count < strlen(word)){
        matrix[x][y].solution = true;

        _count++;
        x += delX;
        y += delY;
    }
}

bool checkWord(vector<vector<Node>> &matrix, char* word, int x, int delX, int y, int delY){
    int _count = 0;
    while(_count < strlen(word)){
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()){ return false; }
        if(matrix[x][y].chr != *(word + _count)){ return false; }

        _count++;
        x += delX;
        y += delY;
    }
    
    return true;
}

//only print characters in the solution - add * to excluded chars
void printMatrix(vector<vector<Node>> matrix){
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
