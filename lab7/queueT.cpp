#include <iostream>
#include <queue>
#include <string>
   
using namespace std;
 
int main ()
{
  queue <string> names; /* Declare a queue */
  names.push ("Liz"); /* add values to the end of the queue */
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
