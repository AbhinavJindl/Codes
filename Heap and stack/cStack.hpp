#ifndef cStack_h
#define cStack_h
#include <iostream>
using namespace std;
  template <typename E>
  class cStack {			// an interface for a stack
  private:
    int redend;
    int blueend;
    E* stack;
    int size;
  public:
    cStack(int cap = 100){
      stack=new E[cap];             //constructing array for stack of size capacity
      redend=-1;                   //initialising index of red to -1
      blueend=cap;
      size=cap; 
    }		                           // constructor from capacity
    int redsize() const;		// number of items in stack
    bool redempty() const;		// is the stack empty?
    const E& redtop();	      		// the top element
    void redpush(const E& e); 		// push x onto the stack
    void redpop();		      	// remove the top element
    int bluesize() const;               // number of items in stack
    bool blueempty() const;             // is the stack empty?
    const E& bluetop() const;           // the top element
    void bluepush(const E& e);          // push x onto the stack
    void bluepop();                     // remove the top element 
 };




////////////////////////////////////////////
//////for red




template <typename E>
int cStack<E>:: redsize() const{            //size=redend+1
  return (redend+1); 

}

template <typename E>
bool cStack<E>:: redempty() const{          //true if redend = -1
  if (redend==-1){
    return true;
  } 
  else{
    return false;
  }

}

template <typename E>
const E& cStack<E>:: redtop(){
  if (redend==-1){
    cout<<"no element in red stack\n";
  }
  else {
    return stack[redend];
  }
}


template <typename E>
void cStack<E>:: redpush(const E& e){
  if (redend==size-1){
    cout<<"further elements cannot be added as stack is full\n";
    return;
  }
  redend++;
  stack[redend]=e;
}


template <typename E>
void cStack<E>:: redpop(){
  if(redend==-1) return;
  redend--;
}

////////////////////////////////////////////////////
/////for blue



template <typename E>
int cStack<E>:: bluesize() const{            //size=size-blueend
  return (size-blueend); 

}

template <typename E>
bool cStack<E>:: blueempty() const{          //true if blueend = size
  if (blueend==size){
    return true;
  } 
  else{
    return false;
  }

}

template <typename E>
const E& cStack<E>:: bluetop() const{
  if (blueend==size){
    cout<<"no element in blue stack\n";
  }
  else {
    return stack[blueend];
  }
}


template <typename E>
void cStack<E>:: bluepush(const E& e){
  if(blueend==0){
    cout<<"no further elements can be added as capacity is full\n";
    return;
  }
  blueend--;
  stack[blueend]=e;
}


template <typename E>
void cStack<E>:: bluepop(){
  if(blueend==size){return;}
  blueend++;
}

#endif