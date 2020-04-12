#include <iostream>
#include <stack>
#include <string>
   
using namespace std;
 
int main ()
{
  stack <string> names; /* Declare a stack */
  names.push ("Liz"); /* add values to the top of the stack */
  names.push ("John");
  names.push ("Mike"); 

  cout << "Serve the people in stack: " << endl;
  cout << names.top() << endl;
  names.pop();
  cout << names.top() << endl;
  names.pop();
  cout << names.top() << endl;
  names.pop();
  return 0;

}
