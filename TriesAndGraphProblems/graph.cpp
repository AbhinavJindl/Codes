#include "graph.hpp"

int main(){
	graph Graph;
	ifstream file;
	file.open("courses.txt");
	string str;

	int duration;
	while(file>>str){
		file>>duration;
		Graph.insertvertex(str,duration);
	}
	file.close();
	file.open("dependencies.txt");
	string str1,str2;
	while(file>>str1){
		file>>str2;
		Graph.insertedge(str1,str2);
	}
	file.close();
	//Graph.print();
	Graph.maxcourse();
}