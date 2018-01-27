#ifndef classes_h
#define classes_h
#include <cstring>
#include <iostream>
using namespace std;
class car{					//creating class car
protected:
	char *name;
	char *color;
	int mileage;
	int TopSpeed;
	int NoOfGears;
	bool Book;
public:
	car(){}
	car(char *n,char *c,int m,int t,int N);
	~car(){}
	char* getname();
	char* getcolor();
	int getmileage();
	int getTopSpeed();
	int getNoOfGears();
	bool getBook();
	void book();
	void unbook();
	car add();
	virtual void display();
	bool operator ==(car obj);				//operator overloading
};

class truck:public car{       //creating class truck with inheriting class car
private:
	int W_LoadingCapacity;		//loading capacity in kg
	int V_LoadingCapacity;		//loading capacity in L
public:
	truck(){}
	truck(char *n,char *c,int m,int t,int N,int Wl,int Vl);
	~truck(){}
	int getW_LoadingCapacity();
	int getV_LoadingCapacity();
	truck add();
	void display();
	bool operator ==(truck obj);							//operator overloading
};

class bus:public car{        //creating class bus with inheriting class car
private:
	int NoOfSeats;

public:
	bus(){}
	bus(char n[20],char c[20],int m,int t,int N,int s);
	~bus(){}
	int getNoOfSeats();
	bus add();
	void display();
	bool operator ==(bus obj);								//operator overloading
};

template <class T> class Node{		//template class for nodes of linked list
private:
	T value;
	Node<T>* next;


public:
	Node(){}
	Node (T temp){					//constructor
		value=temp;
		next=NULL;
	}
	~Node(){} 					//destructor
	T& getvalue(){
		return value;
	}
	T* getvaluep(){				//return address
		return &value;
	}
	Node<T>* getnext(){
		return next;
	}
	void addvalue(T t){
		value=t;
	}
	void addnext(Node<T>* n){					//func to assign n to next
		next=n;
	}
	Node *createnew(){
		Node <T>* temp=new Node<T>((temp->value).add());
		return temp;
	}
	
	
};


#endif