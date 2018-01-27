#ifndef deque_h
#define deque_h
#include "cStack.hpp"
#include <iostream>
using namespace std;

template <typename E>  
class Deque {				// deque as doubly linked list
private:
    cStack <E> stack;
    cStack <E> tempstack;
  public:
    Deque();				// constructor
    int size() const;				// number of items in the deque
    bool empty() const;				// is the deque empty?
    const E& front()  ; // the first element
    const E& back() ;	// the last element
    void insertFront(const E& e);		// insert new first element
    void insertBack(const E& e);		// insert new last element
    void removeFront();	// remove first element
    void removeBack();	// remove last element
    void transfer(bool i);          //tranfer from one to other
  };



template <typename E>
  Deque<E>:: Deque(){
  }

template <typename E>
  int Deque<E>:: size() const{
    return (stack.redsize()+stack.bluesize());
  }



template <typename E>
  void Deque<E>:: transfer(bool i){
    if (i==0){
        while(stack.redsize()!=(this->size())/2+1){       //0 for tranfer from red to blue
            tempstack.redpush(stack.redtop());
            stack.redpop();
        }                                           
        while(stack.redempty()!=true){
            stack.bluepush(stack.redtop());
            stack.redpop();
        }
        while(tempstack.redempty()!=true){
            stack.redpush(tempstack.redtop());
            tempstack.redpop();
        }
    }
    if (i==1){
        while(stack.bluesize()!=(this->size())/2+1){       //1 for tranfer from blue to red
            tempstack.bluepush(stack.bluetop());
            stack.bluepop();
        }                                           
        while(stack.blueempty()!=true){
            stack.redpush(stack.bluetop());
            stack.bluepop();
        }
        while(tempstack.blueempty()!=true){
            stack.bluepush(tempstack.bluetop());
            tempstack.bluepop();
        }
    }
  }



template <typename E>
  bool Deque<E>:: empty() const {
    if (stack.redempty() && stack.blueempty()){
        return true;
    }
    else {
        return false;
    }
  }


template <typename E>
  const E& Deque<E>:: front() {
    if (this->size()==0){
        cout<<"no element\n";
    }
    else if(stack.redempty()){
        this->transfer(true);
        return stack.redtop();
    }
    else{
        return stack.redtop();
    }
  }


template <typename E>
  const E& Deque<E>:: back() {
    if (this->size()==0){
        cout<<"no element\n";
    }
    else if(stack.blueempty()){
        this->transfer(false);
        return stack.bluetop();
    }
    else {
        return stack.bluetop();}
  }

template <typename E>
  void Deque<E>:: insertFront(const E& e){
    stack.redpush(e);
  }


template <typename E>
  void Deque<E>:: insertBack(const E& e){
    stack.bluepush(e);
  }


template <typename E>
  void Deque<E>:: removeFront(){
    if (this->size()==0){
        cout<<"no element\n";
    }
    else if(stack.redempty()){
        this->transfer(true);
        stack.redpop();
    }
    else{
    stack.redpop();}
  }


template <typename E>
  void Deque<E>:: removeBack(){
    if (this->size()==0){
        cout<<"no element\n";
    }
    else if(stack.blueempty()){
        this->transfer(false);
        stack.bluepop();
    }
    else {
    stack.bluepop();}
  }

#endif