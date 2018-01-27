#include  <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "trie.hpp"
using namespace std;

int main(){
    trie Trie;
    ifstream in;
    in.open("name_number.txt");
    string name;
    long long int number;
    while(in>>name>>number){
        for(int i=0;i<name.size();i++){
            if(name[i]<='Z'&&name[i]>='A')
            name[i]=name[i]-('Z'-'z');
        }
        //cout<<name<<endl;
        Trie.insert(name,number);
    }
    while(1){
        string input;
        cout << "Please enter full or partial contact:";
        cin >> input;
        if(input=="0"){
            break;
        }
        for(int i=0;i<input.size();i++){
            if(input[i]<='Z'&&input[i]>='A')
            input[i]=input[i]-('Z'-'z');
        }
        Trie.search(input);
        
    }
}
