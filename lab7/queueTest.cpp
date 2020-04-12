#include <iostream>
#include "MyQueue.h"
#include <string>
   
using namespace std;
 
int main ()
{
  MyQueue <string> names; /* Declare a MyQueue */
  names.push ("Liz"); /* add values to the end of the MyQueue */
  names.push ("John");
  names.push ("Mike"); 

  cout << "Serve the people in queue : " << endl;
  cout << names.front() << endl;
  names.pop();
  cout << names.front() << endl;
  names.pop();
  cout << names.front() << endl;
  names.pop();
  return 0;

}
