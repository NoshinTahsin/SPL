#include<iostream>
#include<fstream>

using namespace std;

int main()
{
/*CREATE TABLE Persons (
    ID int,
    name varchar(255),
    roll int,
    email varchar(255),
 );*/
    cout<<"Enter command : "<<endl;
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
	struct Student
	{
		int ID;
		string name;
		int roll;
		string email;
	};

	Student s;
     cout<<"Enter ID,name,roll and email : "<<endl;

	int ID,roll;
	string name,email;

	cin>>ID>>name>>roll>>email;

	s.ID=ID;
	s.name=name;
	s.roll=roll;
	s.email=email;

	ofstream oFile;
	oFile.open("database.txt");
    if(s1=="CREATE")cout<<"Table name : "<< s3<<endl;
    if(s4=="(")
    {
                    cin>>s4;
        while(s4!=")")
        {

            oFile<<s4<<'\t';
                        cin>>s4;
        }

    }

 	oFile<<endl<<s.ID << '\t' <<s.name<< '\t'<<s.roll<<'\t'<<s.email<<'\t'<<endl;

	oFile.close();



	return 0;
}
