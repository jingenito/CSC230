#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x, y;

    cin >> x;
    cin >> y;

    char arr[x][y]
    for(int i = 0; i < x; ++i)
        for(int j = 0; j < y; ++j)
            cin >> arr[i][j];
    
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}