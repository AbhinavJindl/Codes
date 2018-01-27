#include "LinkedList.cpp"


int main(){



char *name=new char[20];
char *color=new char[20];  				//variables for reading from file
int mileage,topspeed,noofgears,wloadingcap,lloadingcap,noofseats;






//reading from file car
fstream infile;
infile.open("car.txt",ios::in);
infile >>name>>color>> mileage >>topspeed>>noofgears;


	car car1(name,color,mileage,topspeed,noofgears);   //creating object of car with constructor
	Node <car>* node=new Node<car>(car1);				//creating car node with calling car1 object
	//cout<<(node->getvalue()).getname()<<"\n";
	LinkedList <Node<car> > clist(node);              //initialising linked list object and head is node
while (infile >> name){
	infile >>color>> mileage >>topspeed>>noofgears;
	//cout<< name<<" " <<  color<<" "<<mileage<<" " <<topspeed<<" "<<noofgears<<" "<<"\n";
	car car2(name,color,mileage,topspeed,noofgears);   //creating object of car with constructor
	Node <car>* node=new Node<car>(car2);
	clist.add(node);						//adding node to linked list


}
infile.close();





//reading from file truck
infile.open("truck.txt",ios::in);
infile >> name >> color>> mileage >>topspeed>>noofgears>>wloadingcap>>lloadingcap;

truck truck1(name,color,mileage,topspeed,noofgears,wloadingcap,lloadingcap);
Node <truck>* tnode=new Node<truck>(truck1);
LinkedList <Node<truck> > tlist(tnode);   				//creating truck linked list with tnode as head


while (infile >> name >> color>> mileage >>topspeed>>noofgears>>wloadingcap>>lloadingcap){
	//cout<< name<<" " << color<<" " <<mileage<<" " <<topspeed<<" "<<noofgears<<" "<<wloadingcap<<" "<<lloadingcap<<" "<<"\n";
	truck truck2(name,color,mileage,topspeed,noofgears,wloadingcap,lloadingcap);
	Node <truck>* tnode=new Node<truck>(truck2);
	tlist.add(tnode);												//adding node
}
infile.close();







//reading from file bus
infile.open("bus.txt",ios::in);
infile >> name >>color>> mileage >>topspeed>>noofgears>>noofseats;


bus bus1 (name,color,mileage,topspeed,noofgears,noofseats);
Node <bus>* bnode =new Node<bus>(bus1);
LinkedList <Node<bus> > blist (bnode);						//creating bus linked list with bnode as head
while (infile >> name >>color>> mileage >>topspeed>>noofgears>>noofseats){
	//cout<< name <<" "<< color<<" "<<mileage <<" "<<topspeed<<" "<<noofgears<<" "<<noofseats<<" "<<"\n";	
	bus bus1 (name,color,mileage,topspeed,noofgears,noofseats);
	Node <bus>* bnode =new Node<bus>(bus1);
	blist.add(bnode);							//adding bus node
}
infile.close();




//functionalities
int temp;
char * inst=new char[20];
cout<<"ADD ---> add vehicle\nDEL ---> remove vehicle\nWATERMELON --->check number of trucks for watermelons\nPASSENGERS --->  buses and cars for passengers\nBOOK ---> book vehicle\nUNBOOK --->unbook vehicle\nDETAILS ---> to get details\nAnything else to exit\n";

while (1){
	cout<<"\n\nENTER INSTRUCTION :";
	cin>>inst;
	//add instruction block
	if (strcmp(inst,"ADD")==0||strcmp(inst,"Add")==0||strcmp(inst,"add")==0){
		cout<<"Enter type of vehicle:";
		cin>>inst;
		if (strcmp(inst,"car")==0||strcmp(inst,"Car")==0||strcmp(inst,"CAR")==0){
			Node<car>* newnode =newnode->createnew();
			clist.add(newnode);
		}
		else if (strcmp(inst,"truck")==0||strcmp(inst,"Truck")==0||strcmp(inst,"TRUCK")==0){
			Node<truck>	*tnewnode=tnewnode->createnew();								//creating new truck node to be added
			tlist.add(tnewnode);
		}
		else if (strcmp(inst,"bus")==0||strcmp(inst,"Bus")==0||strcmp(inst,"BUS")==0){
			Node<bus> *bnewnode=bnewnode->createnew();								//creating new bus node to be added
			blist.add(bnewnode);
		}
		else{
			cout<<"This vehicle type does not exist,check again!!\n";
		}
	}
	//delete instruction block
	else if (strcmp(inst,"del")==0||strcmp(inst,"delete")==0||strcmp(inst,"Del")==0||strcmp(inst,"DEL")==0||strcmp(inst,"Delete")==0||strcmp(inst,"DELETE")==0){
		cout<<"Enter type of vehicle:";
		cin>>inst;
		if(strcmp(inst,"car")==0||strcmp(inst,"Car")==0||strcmp(inst,"CAR")==0){
			cout<<("enter name of car to be deleted:");
			cin>>name;
			clist.remove(name);
		}
		else if (strcmp(inst,"truck")==0||strcmp(inst,"Truck")==0||strcmp(inst,"TRUCK")==0){
			cout<<("enter name of truck to be deleted:");
			cin>>name;
			tlist.remove(name);
		}
		else if(strcmp(inst,"bus")==0||strcmp(inst,"Bus")==0||strcmp(inst,"BUS")==0){
			cout<<("enter name of bus to be deleted:");
			cin>>name;
			blist.remove(name);
		}
		else{
			cout<<"This vehicle type does not exist,check again!!\n";
		}
	}

	//watermelon function block
	else if (strcmp(inst,"watermelon")==0||strcmp(inst,"WATERMELON")==0||strcmp(inst,"Watermelon")==0){
		cout<<"enter the number of watermelons:";
		int vol;
		cin>>vol;
		vol=vol*30;
		tlist.sort(1);
		//tlist.print();								//sorting truck linked list
		int no=tlist.trucksReq(vol);
		if (no!=-1){
			cout<<"number of trucks required are "<<no<<endl;
		}
	}
	
//passenger function block
	else if(strcmp(inst,"passengers")==0||strcmp(inst,"Passengers")==0||strcmp(inst,"PASSENGERS")==0){
		int passengers;
		cout<<"enter no of passengers:";
		cin>>passengers;
		int *a=new int[2];
		blist.sort();					//sorting bus linked list
		//blist.print();
		a=blist.vehicleReq(passengers);
		if (a[0]!=-1){
			cout<<"no of buses required are "<<a[0]<<endl;
		}
		else if(a[0]==-1){
			int ncars=clist.carsReq(passengers-a[1]);
			if (ncars!=-1){
				cout<<"no of cars required are "<<ncars<<endl;
				cout<<"therefore total no cars and buses required are "<<ncars+blist.size()<<endl;
			}
		}
	}
	
//book block
	else if(strcmp(inst,"book")==0||strcmp(inst,"Book")==0||strcmp(inst,"BOOK")==0){
		cout<<"Enter type of vehicle:";
		cin>>inst;
		if(strcmp(inst,"car")==0||strcmp(inst,"Car")==0||strcmp(inst,"CAR")==0){
			char* n=new char[20];
			cout<<"Enter car name to be booked:";
			cin>>n;
			clist.bookVehicle(n);
		}
		else if(strcmp(inst,"truck")==0||strcmp(inst,"Truck")==0||strcmp(inst,"TRUCK")==0){
			char* n=new char[20];
			cout<<"Enter truck name to be booked:";
			cin>>n;
			tlist.bookVehicle(n);
		}
		else if(strcmp(inst,"bus")==0||strcmp(inst,"Bus")==0||strcmp(inst,"BUS")==0){
			char* n=new char[20];
			cout<<"Enter bus name to be booked:";
			cin>>n;
			blist.bookVehicle(n);
		}
		else{
			cout<<"This vehicle type does not exist,check again!!\n";
		}
	}
	
//unbook block	
	else if(strcmp(inst,"unbook")==0||strcmp(inst,"Unbook")==0||strcmp(inst,"UNBOOK")==0){
		cout<<"Enter type of vehicle:";
		cin>>inst;
		if(strcmp(inst,"car")==0||strcmp(inst,"Car")==0||strcmp(inst,"CAR")==0){
			char* n=new char[20];
			cout<<"Enter car name to be unbooked:";
			cin>>n;
			clist.unbookVehicle(n);
		}
		else if(strcmp(inst,"truck")==0||strcmp(inst,"Truck")==0||strcmp(inst,"TRUCK")==0){
			char* n=new char[20];
			cout<<"Enter truck name to be unbooked:";
			cin>>n;
			tlist.unbookVehicle(n);
		}
		else if(strcmp(inst,"bus")==0||strcmp(inst,"Bus")==0||strcmp(inst,"BUS")==0){
			char* n=new char[20];
			cout<<"Enter bus name to be unbooked:";
			cin>>n;
			blist.unbookVehicle(n);
		}
		else{
			cout<<"This vehicle type does not exist,check again!!\n";
		}
	}
	
//details block
	else if (strcmp(inst,"details")==0||strcmp(inst,"Details")==0||strcmp(inst,"DETAILLS")==0){
		cout<<"Enter type of vehicle:";
		cin>>inst;
		if(strcmp(inst,"car")==0||strcmp(inst,"Car")==0||strcmp(inst,"CAR")==0){
			char* n=new char[20];
			cout<<"Enter car name about which you want to know:";
			cin>>n;
			clist.showdetails(n);
		}
		else if(strcmp(inst,"truck")==0||strcmp(inst,"Truck")==0||strcmp(inst,"TRUCK")==0){
			char* n=new char[20];
			cout<<"Enter truck name about which you want to know:";
			cin>>n;
			tlist.showdetails(n);
		}
		else if(strcmp(inst,"bus")==0||strcmp(inst,"Bus")==0||strcmp(inst,"BUS")==0){
			char* n=new char[20];
			cout<<"Enter bus name about which you want to know:";
			cin>>n;
			blist.showdetails(n);
		}
		else{
			cout<<"This vehicle type does not exist,check again!!\n";
		}
	}

	else{
		cout<<"no further function will be performed as none of given instructions was entered\n";
		break;
	}

}



//clist.print();				//printing
//tlist.print();												
//blist.print();						
}