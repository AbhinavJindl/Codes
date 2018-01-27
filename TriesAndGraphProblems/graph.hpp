#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace  std;
class graph;
class vertex{
	string name;
	int duration;
	vector <vertex*> next;
	vertex* maxchild;
	bool visited;
	int maxduration;
	bool notstack;
public:
	vertex(string n,int dur){
		name=n;
		duration=dur;
		visited=0;
		maxchild=NULL;
		notstack=0;
	}
	void display();
	friend class graph;
};
void vertex::display(){
	cout<<name<<"-->";
	vector<vertex*>::iterator i;
	for(i=next.begin();i!=next.end();++i){
		cout<<(*i)->name<<" ";
	}
}

class graph{
	map <string,vertex*> vertices;
public:
	void insertvertex(string n,int dur);
	void insertedge(string u1,string v1);
	void print();
	bool checkDAG();
	void maxcourse();
	int maxpath(vertex* node);
	bool cycle(vertex *v, bool &temp);
};

void graph:: insertvertex(string n,int dur){
	vertex* newvertex=new vertex(n,dur);
	vertices.insert(pair<string,vertex*>(n,newvertex));
}

void graph::insertedge(string u1,string v1){
	map<string,vertex*>::iterator itr;
	itr=vertices.find(u1);
	vertex* u=itr->second;
	itr=vertices.find(v1);
	vertex* v=itr->second;
	u->next.push_back(v);
}

void graph::print(){
	map<string,vertex*>::iterator itr;
	for (itr = vertices.begin(); itr != vertices.end(); ++itr){
        (itr->second)->display();
        cout<<endl;
    }
}

bool graph::checkDAG(){
	bool temp = false;
	map <string, vertex*> :: iterator itr;
	for (itr = vertices.begin(); itr != vertices.end(); ++itr)
    {
    	temp = cycle(itr -> second,temp);
    	if(temp)
    		break;
    }
    return !temp;
    //itr = g.begin();

}

bool graph :: cycle(vertex *v, bool &temp){
	if(v -> visited)
		return temp;
	v -> visited = true;
	vector <vertex*> :: iterator itr;
	if(!(v -> next).empty())
	for (itr = v->next.begin(); itr != v->next.end(); ++itr)
    {
    	if((*itr)->visited == 0)
    	{
    		temp = cycle((*itr),temp);
    	}
    	else
    	{
    		if((*itr)->notstack == 0)
    		{
    			return true;
    		}
    	}
    }
    v -> notstack = true;
    return temp;

}

void graph::maxcourse(){
	bool DAG=checkDAG();
	if(DAG==0){
		cout<<"Not a DAG\n";
		return;
	}
	map<string,vertex*>::iterator itr;
	for (itr = vertices.begin(); itr != vertices.end(); ++itr){
        (itr->second)->visited=0;
    }
    itr=vertices.begin();
    vertex* root=itr->second;
    int maximum=maxpath(root);
    cout<<"The longest path is: ";
    while(root!=NULL && root->maxchild->maxchild!=NULL){
    	cout<<root->name<<"-->";
    	root=root->maxchild;
    }
    cout<<root->name<<"-->"<<root->maxchild->name<<endl;
    cout<<"Longest duration is "<<maximum<<" months"<<endl;

}
int graph::maxpath(vertex* node){
	if(node->next.empty()){
		node->maxduration=node->duration;
		node->visited=1;
		return node->duration;
	}
	int maximum=0;
	if(!(node->visited)){
		for(int i=0;i<node->next.size();++i){
			int n=maxpath(node->next[i]);
			if(maximum<n){
				maximum=n;
				node->maxchild=node->next[i];
			}
		}
		node->maxduration=node->duration+maximum;
		node->visited=1;
		return node->maxduration;
	}
	else{
		return node->maxduration;
	}
}