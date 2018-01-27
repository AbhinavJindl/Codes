class student{
private:
	char* name;
	char* branch;
	float grade;
public:
	student(char* n,char* b,float g){
		name=n;
		branch=b;
		grade=g;
	}
	char* getname(){
		return name;
	}
	char* getbranch(){
		return branch;
	}
	float getgrade(){
		return grade;
	}
};