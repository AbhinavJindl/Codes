#include "classes.h"

bus::bus(char n[20],char c[20],int m,int t,int N,int s){
		name=new char[20];
		strcpy(name,n);
		color = new char[20];
		strcpy(color,c);
		mileage=m;
		TopSpeed=t;
		NoOfGears=N;
		NoOfSeats=s;
		Book=false;
	}

int bus::getNoOfSeats(){   //definition of function for no of seats
	return NoOfSeats;
}

bus bus::add(){
	char* n=new char[20];
	char* c=new char[20];
	int m,t,ng,ns;

	cout<<"enter bus name:";
	cin >>n;
	cout<<"enter bus color:";
	cin >>c;
	cout<<"enter bus mileage:";
	cin >>m;
	cout<<"enter bus top speed:";
	cin >>t;
	cout<<"enter bus no of gears:";
	cin >>ng;
	cout<<"enter bus no of seats:";
	cin >>ns;
	bus bus1(n,c,m,t,ng,ns);
	return bus1;
}

bool bus::operator ==(bus obj){										//operator overloading
			if (strcmp(this->getname(),obj.getname())==0) return true;
			else return false;
		}

void bus::display(){
	cout<<"name is "<<name<<"\ncolor is "<<color<<"\nmileage is "<< mileage<<"\ntop speed is "<<TopSpeed<<"\nno of gears are "<<NoOfGears<<"\nNo of passengers that it can carry are "<<NoOfSeats<<"\nBooked status is "<<Book<<endl;
}