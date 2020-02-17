#include <iostream>
using namespace std;

extern void reverse(char* p);

int main()
{
  char input[50];

  cin >> input;

  reverse(&input[0]);

  cout << input << endl;
}
