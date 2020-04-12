#include <iostream>
#include "MyStack.h" 
#include <string>
   
using namespace std;
 
int main ()
{
  MyStack <string> names; /* Declare a MyStack */
  names.push ("Liz"); /* add values to the MyStack */
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
