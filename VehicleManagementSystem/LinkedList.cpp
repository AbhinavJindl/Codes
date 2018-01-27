#include <iostream>
using namespace std;
#include <fstream>
#include <cstring>
#include "classes.h"


template <class T> class LinkedList{		//template class for linked list
	private:
		T* head;

	public:	
		LinkedList(T* temp){
			head=temp;
		}								//function declarations
		void print();
		void add( T* n);
		void remove(char* a);
		int size();
		void sort(bool i);					//function overloading
		void sort();
		int trucksReq(int vol);
		int *vehicleReq(int passengers);
		int carsReq(int Rpass);
		void bookVehicle(char* n);
		void unbookVehicle(char* n);
		void showdetails(char* n);


};













//definition of print function
template <class T>
void LinkedList <T>::print(){
	T* temp;
	int a=0;
	temp=head;
	while(temp!=NULL){
		cout<<(temp->getvalue()).getname()<<"-->";
		temp=temp->getnext();
		a++;
	}
	cout<<"\n";
}


//definition of func add in class linked list
template <class T>
void LinkedList <T>::add(T* n){
	T* temp;
	temp=head;
	while(temp->getnext()!=NULL){
		if (temp->getvalue()==n->getvalue()){					 //checking if same name vehicle exists and returning error if true
			cout<<"error same name vehicle already exists \n";
			return;
		}
		temp=temp->getnext();
	}
	temp->addnext(n);	
}



//definition  of remove func
template <class T>
void LinkedList <T>::remove(char* n){
	T* temp;
	temp=head;
	if (strcmp(temp->getvalue().getname(),(n))==0){     //checking if same name vehicle exists and returning error if true
		cout<<"vehicle found and removed \n";
		head=head->getnext();
	return;
	}

	while(temp->getnext()!=NULL){
		if (strcmp((temp->getnext())->getvalue().getname(),(n))==0){     //checking if same name vehicle exists and returning error if true
			cout<<"vehicle found and removed \n";
			temp->addnext((temp->getnext())->getnext());
			return;
		}
		temp=temp->getnext();
	}
	cout<<"vehicle not found\n";
	

}


//definition of size func
template <class T>
int LinkedList <T>:: size(){
	T* temp=head;
	int size=0;
	while(temp!=NULL){
		size++;
		temp=temp->getnext();
	}
	return size;
}


//definition of sort func acc to vol if  argument is 1 or weight if arg is 0
template <class T>
void LinkedList <T>:: sort(bool j){
	T temp;
	T* curr;
	int size=this->size();
	if (j==1){
		for (int i=0;i<size;i++){

			curr=head;
			while (curr->getnext()!=NULL){
				if (curr->getvalue().getV_LoadingCapacity()<curr->getnext()->getvalue().getV_LoadingCapacity()){
				
					temp.addvalue(curr->getvalue());
					curr->addvalue(curr->getnext()->getvalue());
					curr->getnext()->addvalue(temp.getvalue());
		
				}
				curr=curr->getnext();
			
		
			}
	}
	}
	else{
		for (int i=0;i<size;i++){

		curr=head;
		while (curr->getnext()!=NULL){
			if (curr->getvalue().getW_LoadingCapacity()<curr->getnext()->getvalue().getW_LoadingCapacity()){
				
				temp.addvalue(curr->getvalue());
				curr->addvalue(curr->getnext()->getvalue());
				curr->getnext()->addvalue(temp.getvalue());
		
			}
			curr=curr->getnext();
			
		
		}
	}

	}

}



//definition of sort acc to seats
template <class T>
void LinkedList <T>::sort(){
	T temp;
	T* curr;
	int size=this->size();
	for (int i=0;i<size;i++){

		curr=head;
		while (curr->getnext()!=NULL){
			if (curr->getvalue().getNoOfSeats()<curr->getnext()->getvalue().getNoOfSeats()){
				temp.addvalue(curr->getvalue());
				curr->addvalue(curr->getnext()->getvalue());
				curr->getnext()->addvalue(temp.getvalue());
		
			}
			curr=curr->getnext();
		
		}
	}

}


//return no of trucks required
template <class T>
int LinkedList <T>:: trucksReq(int vol){
	T* temp=head;
	int count=0,sum=0;
	while(temp!=NULL){
		if (sum<vol){
			sum=sum+temp->getvalue().getV_LoadingCapacity();
			count++;
			cout<<"truck no."<<count<<":- "<<temp->getvalue().getname()<<endl;
		}
		if (sum>=vol){				//if trucks are sufficient
			return count;
		}

		temp=temp->getnext();
	}
	cout<<"trucks are not enough for this much melons.....so sorry!!!"<<endl;
	return -1;

}


//definiton of no of passenger func
template <class T>
int* LinkedList <T>:: vehicleReq(int vol){
	T* temp=head;
	int count=0,sum=0;
	int *a=new int[2];
	while(temp!=NULL){
		if (sum<vol && temp->getvalue().getNoOfSeats()>=5){
			sum=sum+temp->getvalue().getNoOfSeats();				//adding passengers from bus
			count++;
			cout<<"bus no."<<count<<":- "<<temp->getvalue().getname()<<endl;
		}
		if (sum>=vol){						//if buses are sufficient
			a[0]=count;
			a[1]=sum;
			return a;
		}

		temp=temp->getnext();
	}
	a[0]=-1;									//if buses are not sufficient
	a[1]=sum;
	cout<<"this alone is not enough for this much passengers!!!"<<endl;
	cout<<"buses can accomodate "<<a[1]<<" passengers only\n";
	return a;

}



//definition of cars required list
template <class T>
int LinkedList <T>::carsReq(int Rpass){
	T* temp=head;
	int count=0,sum=0;
	int a;
	while(temp!=NULL){
		if (sum<Rpass){					//adding passengers from car
			sum=sum+5;
			count++;
			cout<<"car no."<<count<<":- "<<temp->getvalue().getname()<<endl;
		}
		if (sum>=Rpass){				//if cars are sufficient
			a=count;
			return a;
		}

		temp=temp->getnext();
	}
	a=-1;
	cout<<"cars and buses are not enough for this much passengers!!!"<<endl;
	return a;

}




//definition of book func
template <class T>
void LinkedList <T>:: bookVehicle(char* n){
	T* curr=head;
	while(curr!=NULL){
		if (strcmp(curr->getvalue().getname(),n)==0){
			if (curr->getvalue().getBook()==1){
				cout<<"So sorry!!!, "<<n<<" is already booked"<<endl;
				cout<<"Vehicle details are :\n";
				curr->getvalue().display();
				return;
			}
			else{
				curr->getvaluep()->book();       		//booking status changed using pointer
				cout<<curr->getvalue().getname()<<" is booked\n";
				cout<<"Vehicle details are :\n";
				curr->getvalue().display();				//printing details
				return;
			}
		}
		curr=curr->getnext();
	}
	cout<<"Vehicle with this name not found\n";
}



//definition of unbook func
template <class T>
void LinkedList <T>:: unbookVehicle(char* n){
	T* curr=head;
	while(curr!=NULL){
		if (strcmp(curr->getvalue().getname(),n)==0){
			if (curr->getvalue().getBook()==0){
				cout<<n<<" is already unbooked"<<endl;
				cout<<"Vehicle details are :\n";
				curr->getvalue().display();
				return;
			}
			else{
				curr->getvaluep()->unbook();						//booking status changed using pointer
				cout<<curr->getvalue().getname()<<" is unbooked\n";
				cout<<"Vehicle details are :\n";
				curr->getvalue().display();							//printing details
				return;
			}
		}
		curr=curr->getnext();
	}
	cout<<"Vehicle with this name not found\n";
}



//definition of show details func
template <class T>
void LinkedList <T>:: showdetails(char* n){
	T* curr=head;
	car* car1;
	while(curr!=NULL){
		if (strcmp(curr->getvalue().getname(),n)==0){
				cout<<"Vehicle details are :\n";
				car1=&(curr->getvalue());
				car1->display();
				return;
		}
		curr=curr->getnext();
	}
	cout<<"Vehicle with this name not found\n";
}



