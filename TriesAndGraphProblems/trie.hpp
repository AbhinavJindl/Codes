#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <string>
using namespace std;
class trie;
class node{
	char key;
	long long int number;
	int size;
	node* next[26];

public:
	node(){
		for (int i=0;i<26;i++){
			next[i]=NULL;
			number=0;
			size=0;
		}
	}
	friend class trie;

};

class trie{
	node* root;
public:
	trie();
	void insert(string s,long long int);
	void search(string s);
	void print(node* temp,string s,int* counter);
};

trie::trie(){
	root=new node();
}

void trie::insert(string s,long long int num){
	int ssize=s.size();
	node* temp=root;
	for(int j=0;j<ssize;j++){
		int index=s[j]-'a';
		if (temp->next[index]==NULL){
			temp->next[index]=new node();
			temp->next[index]->key=s[j];
			temp->next[index]->size=1;
		}
		else{
			temp->next[index]->size++;
		}
		temp=temp->next[index];
	}
	temp->number=num;
	//cout<<temp->key<<temp->number<<endl;

}

void trie::search(string s){
	node*temp=root;
	for (int j=0;j<s.size();j++){
		int index=s[j]-'a';
		if(temp->next[index]==NULL){
			cout<<"contact not found\n";
			return;
		}
		else{
			temp=temp->next[index];
		}
	}
	int number=temp->size;
	int xyz=5;
	cout<<"we found "<<number<<" contacts matching with "<<s<<":\n";
	if(number>=5){
		print(temp,s,&xyz);
	}
	else{
		print(temp,s,&number);
	}


}

void trie::print(node* temp,string s,int* counter){
	//cout<<*counter<<endl;
	if(*counter>0 && temp->number!=0){
		cout<<s<<" "<<temp->number<<endl;
		*counter=*counter-1;
	}
	for (int i=0;i<26;i++){
		if(temp->next[i]!=NULL){
			print(temp->next[i],s+(char)('a'+i),counter);
		}
	}
}

#endif