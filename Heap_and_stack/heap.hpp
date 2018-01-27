  //TNode as node of the tree
//LNode as nodes of the linked list 
#ifndef heap_h
#define heap_h
#include <iostream>
using namespace std;
 
template <typename E>
class tnode{
private:
  E value;
  tnode<E>* left;
  tnode<E>* right;
  tnode<E>* parent;
public:
  tnode(const E& e){
    value=e;
    left=NULL;
    right =NULL;
    parent=NULL;
  }
 template <typename T,typename C> friend class Heap;
};


template <typename E, typename C>     // element and comparator
 class Heap {                 // priority-queue interface
 private:
  tnode<E> *root;
  tnode<E> *last;
  int hsize;
  C less;
 public:
   Heap(); //Constructor
   int size() const;         // number of elements
   bool isEmpty() const;       // is the queue empty?
   void insert(const E& e);        // insert element
   const E& min() const;   // minimum element
  void removeMin();     // remove minimum
  void mergeHeaps(Heap H); //MODIFIED 
  void buildHeap(E A[], int size);  
  void upheapify(tnode<E> * node);
  void downheapify(tnode<E>* node);
  void arrheapify(E A[],int i,int size);
  void traversal(tnode<E>* list[]);
  //One function to do the traversal 
  };

template <typename E,typename C>
  Heap<E,C>::Heap(){
    hsize=0;
    root=NULL;
    last=NULL;
  }
template <typename E,typename C>
  int Heap<E,C>::size() const{
    return hsize;
  }

template<typename E,typename C>
  bool Heap<E,C> ::isEmpty() const{
    if (hsize==0) return true;
    else return false;
  }

template <typename E,typename C>
  void Heap<E,C>:: upheapify(tnode<E>* node){
    while (node!=root  && less(node->value,node->parent->value)){
      E temp;
      temp=node->value;
      node->value=node->parent->value;
      node->parent->value=temp;
      node=node->parent;
    }
  }

template <typename E,typename C>
  void Heap<E,C>:: downheapify(tnode<E>* node){
    while (node->left!=NULL && node->right!=NULL  && (less(node->left->value,node->value) || less(node->right->value,node->value))){
      if (less(node->left->value,node->right->value)){
          node=node->left;
          E temp;
          temp=node->value;
          node->value=node->parent->value;
          node->parent->value=temp;
      }
      else{
        node=node->right;
        E temp;
        temp=node->value;
        node->value=node->parent->value;
        node->parent->value=temp;
      }
      
    }
    if (node->left!=NULL && less(node->left->value,node->value)){
        node=node->left;
        E temp;
        temp=node->value;
        node->value=node->parent->value;
        node->parent->value=temp;
    }
  }

template <typename E,typename C>
  void Heap<E,C>:: insert(const E& e){
    tnode<E> *newnode=new tnode<E>(e);
    if (root==NULL){                //if heap is empty
      root=newnode;

    }
    else if(last==root){
      root->left=newnode;
      newnode->parent=root;
    }

    else if ((last->parent)->right==NULL){      //for left child
      (last->parent)->right=newnode;
      newnode->parent=last->parent;
    }
    else if((last->parent)->right==last){     //for complete and right child
      tnode<E>* tempnode=last;
      while (tempnode !=root && (tempnode->parent)->right==tempnode  ){
        tempnode=tempnode->parent;
      }
      if (tempnode==root){                  //if heap is complete
      }
      else {
        tempnode=(tempnode->parent)->right;   //if last is right child 
      }
      while (tempnode->left!=NULL){
          tempnode=tempnode->left;
        }
        tempnode->left=newnode;
        newnode->parent=tempnode;
    }
    last=newnode;
    this->upheapify(last);

    hsize++;
  }

template <typename E,typename C>
  const E& Heap<E,C>:: min() const{
    if(hsize!=0){
      return (root->value);  
    }
    else{
      cout<<"error as no element\n";
    }
  }

template <typename E,typename C>
  void Heap<E,C>::removeMin(){
    if (root==NULL){                //if heap is empty
      cout<<"no element in heap\n";
      return;
    }
    E temp;
    tnode<E>* temp1=last;
    temp=root->value;
    root->value=last->value;
    last->value=temp;
    if (last==root){
      root=NULL;
      last=NULL;
      delete temp1;
      hsize--;
      return;
    }
    else if ((last->parent)->right==last){      //for right child
      last=(last->parent)->left;
      temp1->parent->right=NULL;
    }
    else if((last->parent)->left==last){     //for complete and left child
      tnode<E>* tempnode=last;
      while (tempnode !=root && (tempnode->parent)->left==tempnode  ){
        tempnode=tempnode->parent;
      }
      if (tempnode==root){                  //if heap is complete
      }
      else {
        tempnode=(tempnode->parent)->left;   //if last is left child 
      }
      while (tempnode->right!=NULL){
          tempnode=tempnode->right;
        }
        last=tempnode;
        temp1->parent->left=NULL;
    }
    delete temp1;
    this->downheapify(root);
    hsize--;

  }

template <typename E,typename C>
  void Heap<E,C>::arrheapify(E A[],int i,int size){
    while(2*i+1<size && 2*i+2 <size && (less(A[2*i+1],A[i]) ||less(A[2*i+2],A[i]))){
      if (less(A[2*i+1],A[2*i+2])){
        E temp;
        temp=A[i];
        A[i]=A[2*i+1];
        A[2*i+1]=temp;
        i=2*i+1;
      }
      else if (less(A[2*i+2],A[2*i+1])){
        E temp;
        temp=A[i];
        A[i]=A[2*i+2];
        A[2*i+2]=temp;
        i=2*i+2;
      }
    }
    if (2*i+1<size && less(A[2*i+1],A[i])){
      E temp;
      temp=A[i];
      A[i]=A[2*i+1];
      A[2*i+1]=temp;
    }
  }

template <typename E,typename C>
  void Heap<E,C>::buildHeap(E A[], int size){
    int i;
    for (i=size/2-1;i>=0;i--){
      this->arrheapify(A,i,size);
    }
    tnode<E>** list=new tnode<E>*[size];
    i=0;
    while(i<size){
      list[i]=new tnode<E>(A[i]);
      i++;
    }
    int k;
    i=0;k=0;
    root=list[i];
    last=list[size-1];
    i++;
    while(i<size){
      list[k]->left=list[i];
      list[i]->parent=list[k];
      i++;
      if(i<size){
        list[k]->right=list[i];
        list[i]->parent=list[k];
        i++;
      }
      k++;

    }
    hsize=size;
  }

template <typename E,typename C>
  void Heap<E,C>::traversal(tnode<E>* list[]){
    int i=1,k=0;
    int s=this->size();
    if (s==0){
      return;
    }
    list[0]=root;
    while(i<s){
      list[i]=list[k]->left;
      i++;

      if(i<s){
        list[i]=list[k]->right;
        i++;
      }
      k++;
    }

  }
template <typename E,typename C>
  void Heap<E,C>::mergeHeaps(Heap H){
    int s1,s2;
    s1=H.size();
    if(s1==0){
      return;
    }
    tnode<E>* temp1[s1];
    H.traversal(temp1);
    s2=this->size();
    tnode<E>* temp2[s2];
    this->traversal(temp2);
    E temp[s1+s2];
    int i=0;
    while(i<s1+s2){
      if (i<s2){
        temp[i]=temp2[i]->value;
      }
      else{
        temp[i]=temp1[i-s2]->value;
      }
      i++;
    }
    this->buildHeap(temp,s1+s2);

  }
#endif