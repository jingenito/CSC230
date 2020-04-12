/** Joe Ingenito  */

/** CSC230-02 */

/** Lab 7 */

#include <iostream>
#include "MyQueue.h"
#include "MyStack.h"

using namespace std;

int main()
{
    MyQueue <string> namesQ; /* Declare a MyQueue */
    namesQ.push ("Liz"); /* add values to the end of the MyQueue */
    namesQ.push ("John");
    namesQ.push ("Mike"); 

    cout << "Serve the people in queue : " << endl;
    cout << namesQ.front() << endl;
    namesQ.pop();
    cout << namesQ.front() << endl;
    namesQ.pop();
    cout << namesQ.front() << endl;
    namesQ.pop();

    MyStack <string> namesS; /* Declare a MyStack */
    namesS.push ("Liz"); /* add values to the MyStack */
    namesS.push ("John");
    namesS.push ("Mike"); 

    cout << "Serve the people in stack: " << endl;
    cout << namesS.top() << endl;
    namesS.pop();
    cout << namesS.top() << endl;
    namesS.pop();
    cout << namesS.top() << endl;
    namesS.pop();

    return 0;
}