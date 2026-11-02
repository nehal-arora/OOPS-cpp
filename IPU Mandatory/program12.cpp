#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Student{
	char name[40];
	int age;
	char sex[10];
	float height;
	float weight;
	public:
	void readData(){
		cout<<"Enter the name: ";
		cin>> name;
		cout<<endl<<"Enter the age: ";
		cin>> age;
		cout<<endl<<"Enter sex: ";
		cin>> sex;
		cout<<endl<<"Enter the height:";
		cin>> height;
		cout<<endl<<"Enter the weight:";
		cin>>weight;
	}
	void show(){
		cout<<endl<<"The student details are: "<<endl;
		cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"Sex: "<<sex<<endl<<"Height: "<<height<<endl<<"Weight: "<<weight<<endl;
	}
};
int main(){
	Student s1;
	s1.readData();
	s1.show();
	ofstream out("Student.dat",ios::binary);
	out.write((char *) &s1, sizeof(s1));
	out.close();
	ifstream in("Student.dat",ios::binary);
	Student t;
	in.read((char *) &t, sizeof(t));
	t.show();
	in.close();}