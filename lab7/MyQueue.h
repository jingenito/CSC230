#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue {
    // these two stck are instance variables
    // by default, the access is private
    stack<T> first;
    stack<T> second;
    
    public:

    // return the value of the oldest member
    T front(){
      // please implement this method
      if(second.empty()){
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
      }
      return second.top();
    }

    // add value val to MyQueue
    void push(T val){
      // please implement this method  
      first.push(val);      
    }


    // remove the oldest member from MyQueue
    void pop(){
      // please implement this method
      if(second.empty()){
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
      }
      second.pop();
    }
};

#endif /*MYQUEUE_H*/