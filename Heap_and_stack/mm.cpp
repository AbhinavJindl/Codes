#include<iostream>
#include<string>
#include "cStack.hpp"
#include "deque.hpp"
#include "heap.hpp"
using namespace std;


/*
class Student{
    public:
    string name;
    int grade;
    Student (){ };
    Student (string s , int g){ 
        name = s; 
        grade = g;
    }
    void print(){
        cout << name << " " << grade << endl; 
    }
    
    friend class isLess;
};

class isLess{

    public: 
        bool operator() (Student A , Student B){
            return A.grade<B.grade;
        }    
};

int main(){
    cStack<string> s;
    cout << "IS Empty Red "<<s.redempty() << " Is empty blue "<< s.blueempty() <<endl;
    //cout << s.redtop() << " red Top << blue top >> " << s.bluetop() << endl;
    s.redpush("5");
    s.redpush("10");
    s.bluepush("100");
    cout << s.redsize() << " <<- red  blue ->> " << s.bluesize() << endl;
    cout << "IS Empty Red "<<s.redempty() << " Is empty blue "<< s.blueempty() <<endl;
    s.bluepop();
    s.bluepop();
    //cout << s.redtop() << " red Top << blue top >> " << s.bluetop() << endl;
    s.redpush("30");
    s.redpush("500");
    s.bluepush("200");
    s.redpush("40");
    s.redpush("40"); 
    cout << "\nDEque \n";
    Deque<int> d;
    cout << "IS EMPTY " << d.empty()<< endl;
    d.insertBack(5);
    d.insertBack(35);
    d.insertBack(15);
    d.insertBack(25);
    d.insertBack(10);
    d.insertFront(200);
    d.insertFront(500);
    d.removeBack();
    d.removeBack();
    cout << d.front() << endl;
    d.removeFront();
    d.removeFront();
    d.removeFront();
    d.insertFront(1000);
    d.insertBack(50);
    d.removeBack();
    d.removeBack();
    d.removeFront();
    cout << d.front() << endl;
    cout << d.back() << endl;
    
    cout << endl << endl << "Heap " << endl << endl;
    Heap<Student, isLess > h;
    Student a("Chomu" , 10 ) , b("abcd" , 1) , c("aacabcd" , 8) , d("abcdczdc" , 3) , e("ad" , 2) ,f("asvscd" , 6); 
    h.insert(a);
    h.insert(b);
    h.insert(c);
    h.insert(d);
    h.insert(e);
    h.insert(f);
    for (int i=0;i<6 ; i++){
        const Student& q = h.min();
        cout << q.name << " " <<q.grade << endl;
        h.removeMin();
    }
    }*/
/*    #include <iostream>
#include <string>
#include "heap.hpp"

using namespace std;

class Student{
public:
	Student(){}
	Student(string n, string b, double g){
		name=n;
		branch=b;
		grade=g;
	}
	string name;
	string branch;
	double grade;

};


class Less{
public:
	bool operator()(Student &a, Student &b){ return a.grade<b.grade; }
};



void test_1(Heap<Student,Less> h){
	cout<<h.min().name<<endl;
	h.removeMin();
	Student *s = new Student("Karan","CSE", 1.0);
	h.insert(*s);
	cout<<h.min().name<<endl;
}


void test_2(Heap<Student,Less> h){
	Student arr[] = {Student("A","B",1), Student("C","D", 3), Student("E","F",2)};
	h.buildHeap(arr,3);
	cout<<h.min().name<<endl;
	h.removeMin();
	cout<<h.min().name<<endl;
}

int main()
{
	int t;
	cin>>t;
	Heap<Student,Less> H;
	Heap<Student,Less> h;
	while(t--){
		Student *s= new Student;
		cin>>s->name>>s->branch>>s->grade;
		H.insert(*s);
	}
	test_1(h);
	test_2(h);
	h.mergeHeaps(H);
	int i=h.size();
	while(i>0){
		cout<<h.min()<<endl;
		h.removeMin();
		i--;
	}
	return 0;
}*/

template<typename E>
class Comp {                //Sample comparator used for testing the Heap structure.
            public:
                Comp(){}
                bool operator()(E e1,E e2){
                
                }    
         };


template<> 
class Comp<int> {            //Sample comparator template specified for testing the Heap structure.
            public:
                Comp(){}
                bool operator()(int e1,int e2){
                    return (e1<e2);
                }    
         };
int main(){
    /*cout<<"CSTACK\n";
    cStack<int> st(8);
    cout<<st.redsize()<<endl ;
    cout<<st.redempty()<<endl;
    cout<<st.redtop() <<endl ;
    st.redpush(10);
    st.redpush(5);
    st.redpush(14);
    st.redpush(16);  
    cout<<st.redtop()<<endl;
    cout<<st.blueempty()<<endl;
    cout<<st.bluetop()  <<endl;
     cout<<st.redsize()<<endl;
    cout<<st.bluesize() <<endl;
    st.bluepush(10);
    st.bluepush(5);
    st.bluepush(14);
    st.bluepush(11);
    st.bluepush(12);
    st.bluepush(16);
    st.bluepush(14);

    st.bluepop(); 
    cout<<st.bluetop()<<endl;
    st.bluepop(); 
    cout<<st.bluetop()<<endl;
    st.bluepop(); 
    cout<<st.bluetop()<<endl;
    st.bluepop(); 
    cout<<st.bluetop()<<endl;

    cout<<"DEQUE\n";
    Deque<int> de;
    cout<<de.size()<<endl;   
    cout<<de.empty() <<endl;
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.insertFront(4);       
    de.insertBack(10);
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl ; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl ; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    de.removeBack();
    de.insertFront(14);       
    de.insertBack(103);
    de.insertFront(54);       
    de.insertBack(15);
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();

    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();*/

    Heap<int, Comp<int> >d;
    cout<<"HEAP\n";
    d.insert(4);       
    d.insert(10);
    d.insert(14);       
    d.insert(103);
    d.insert(54);       
    d.insert(15);
    d.insert(5);
    d.insert(3);
    d.insert(30);
    int arr[]={5,465,75,75,33,54,2,54,43,53};
    Heap<int, Comp<int> >d1;
    cout<<"HEAP2\n";
    d1.buildHeap(arr,10);
    //cout<<d1.size()<<endl;   
    //cout<<d1.isEmpty() <<endl;
    //cout<<"min "<<d1.min()<<endl; 
    d.mergeHeaps(d1);
    cout<<d.size()<<endl; 
    d.insert(7);
    d.insert(3);
    d.insert(30);
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    d.removeMin();
    cout<<"min "<<d.min()<<endl;
    cout<<d.size()<<endl;
    return 0;
}
    
    
     
