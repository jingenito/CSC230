#include <iostream>
using  namespace  std;

template <class T>
struct  Node{
  T SSN;
  T name;
  Node<T>*  next;
};

