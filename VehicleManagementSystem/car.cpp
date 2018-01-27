#include "classes.h"
#include <stdio.h>
using namespace std;

//definition of functions in class car

car::car(char *n,char *c,int m,int t,int N){
		name = new char[20];
		strcpy(name,n);
		color = new char[20];
		strcpy(color,c);
		mileage=m;
		TopSpeed=t;
		NoOfGears=N;
		Book =false;
	}


char* car::getname(){
	return name;
}
char* car::getcolor(){
	return color;
}
int car::getmileage(){
	return mileage;
}
int car::getTopSpeed(){
	return TopSpeed;
}
int car::getNoOfGears(){
	return NoOfGears;
}
bool car::getBook(){
	return Book;
}
void car::book(){
	Book=true;
}
void car::unbook(){
	Book=false;
}
car car::add(){
	char* n=new char[20];
	char* c=new char[20];
	int m,t,ng;

	cout<<"enter car name:";
	cin >>n;
	cout<<"enter car color:";
	cin >>c;
	cout<<"enter car mileage:";
	cin >>m;
	cout<<"enter car top speed:";
	cin >>t;
	cout<<"enter car no of gears:";
	cin >>ng;
	
	car car1(n,c,m,t,ng);
	return car1;
}

void car::display(){
	cout<<"name is "<<name<<"\ncolor is "<<color<<"\nmileage is "<< mileage<<"\ntop speed is "<<TopSpeed<<"\nno of gears are "<<NoOfGears<<"\nBooked status is "<<Book<<endl;
}

bool car::operator ==(car obj){									//operator overloading
			if (strcmp(this->getname(),obj.getname())==0) return true;
			else return false;
		}
