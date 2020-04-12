#include <iostream>
#include <queue>
using namespace std;

template <class T>
class MyStack {

  // define two instance variables
  // by default, they are private
  queue <T> first; 
  queue <T> second;

 public:

  // return the latest value of MyStack
  T top(){
    // please implement this method
    return second.front();
  }

  // add value val to MyStack
  void push(T val){
    // please implement this method
    second.push(val);

    while(!first.empty()){
      second.push(first.front());
      first.pop();
    }

    queue<T> q = first;
    first = second;
    second = q;
  }

  // remove the oldest value from MyStack
  void pop(){
    // please implement this method
    second.pop();
  }
};
