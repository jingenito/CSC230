#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
  clock_t start, end;
  double duration;

  start = clock();

  /* Your code is here */

  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;

  cout<<"elapsed time: "<< duration <<'\n';
}

