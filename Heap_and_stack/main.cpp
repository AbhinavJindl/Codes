#include <iostream>
#include <fstream>
using namespace std;
#include "student.h"
#include "cStack.hpp"

int main(){

	char* name=new char[20];
	
	char* branch= new char [5];
	float grade;

	fstream infile;
	int count=0;								//counting no of students
	infile.open("records.txt",ios::in);
	while(infile>>name){
		infile>> branch>>grade;
		count++;
	}
	infile.close();


	student* studentarr[count];						//initialising array of student pointer type 
	count=0;
	infile.open("records.txt",ios::in);
	while(infile>>name){							//storing student details in array created
		infile>> branch>>grade;
		studentarr[count]=new student(name,branch,grade);
		count++;
	}
	infile.close();
}
