#include "classes.h"


truck::truck(char *n,char *c,int m,int t,int N,int Wl,int Vl){
		name=new char[20];
		strcpy(name,n);
		color = new char[20];
		strcpy(color,c);
		mileage=m;
		TopSpeed=t;
		NoOfGears=N;
		W_LoadingCapacity=Wl;
		V_LoadingCapacity=Vl;
		Book=false;

	}


int truck::getW_LoadingCapacity(){
	return W_LoadingCapacity;      //definition of function for loading capacity in kg
}
int truck::getV_LoadingCapacity(){
	return V_LoadingCapacity;       //definition of function for loading capacity in l
}


truck truck::add(){
	char* n=new char[20];
	char* c=new char[20];
	int m,t,ng,vl,wl;

	cout<<"enter truck name:";
	cin >>n;
	cout<<"enter truck color:";
	cin >>c;
	cout<<"enter truck mileage:";
	cin >>m;
	cout<<"enter truck top speed:";
	cin >>t;
	cout<<"enter truck no of gears:";
	cin >>ng;
	cout<<"enter truck capacity in kgs:";
	cin >>wl;
	cout<<"enter truck capacity in litres:";
	cin >>vl;
	truck truck1(n,c,m,t,ng,wl,vl);
	return truck1;
}

bool truck::operator ==(truck obj){											//operator overloading
			if (strcmp(this->getname(),obj.getname())==0) return true;
			else return false;
		}

void truck::display(){
	cout<<"name is "<<name<<"\ncolor is "<<color<<"\nmileage is "<< mileage<<"\ntop speed is "<<TopSpeed<<"\nno of gears are "<<NoOfGears<<"\nLoading capacity in kilos is "<<W_LoadingCapacity<<"\nLoading capacity in litres is "<<V_LoadingCapacity<<"\nBooked status is "<<Book<<endl;
}