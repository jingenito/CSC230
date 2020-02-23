#include <cstring>

void reverse(char* p){
    for (int i = 0; i < strlen(p) / 2; ++i) {
        int ind = strlen(p) - i - 1;
        char temp = *(p + i);
        *(p + i) = *(p + ind);
        *(p + ind) = temp;
    }
};