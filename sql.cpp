#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	struct Student
	{
		int ID;
		string name;
		int roll;
		string email;
	};
	
	Student s;
	
	int ID,roll;
	string name,email;
	
	cin>>ID>>name>>roll>>email;
	
	s.ID=ID;
	s.name=name;
	s.roll=roll;
	s.email=email;
	
	ofstream oFile;
	oFile.open("Struct.txt");
	oFile<<"Student ID: "<< s.ID <<endl;
	oFile<<"Student name: "<< s.name <<endl;
	oFile<<"Student roll: "<< s.roll <<endl;
	oFile<<"Student email: "<< s.email <<endl;
	
	oFile.close();
	
	ifstream iFile;
	iFile.open("input.txt");
	
	iFile>>ID>>name>>roll>>email;
	
	cout<<ID<<endl<<name<<endl<<roll<<endl<<email<<endl;
	
	oFile.close();
	
	return 0;
}
