#include<iostream>
#include<fstream>

using namespace std;

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
string s1,s2,s3,s4;

void createTable()
{
    ofstream oFile;
	oFile.open("database.txt");

    if(s4=="(")
    {
        cin>>s4;
        while(s4!=")")
        {

            oFile<<s4<<'\t';
            cin>>s4;
        }

    }
    oFile<<endl;

    cout<<"Enter ID,name,roll and email : "<<endl;
	cin>>ID>>name>>roll>>email;

    while(1)
    {
        s.ID=ID;
        s.name=name;
        s.roll=roll;
        s.email=email;
        oFile<<endl<<s.ID << '\t' <<s.name<< '\t'<<s.roll<<'\t'<<s.email<<'\t'<<endl;
    	cin>>ID;
    	if(ID==0)break;
    	cin>>name>>roll>>email;
    }

    if(s1=="CREATE")oFile<<endl<<"Table name : "<< s3<<endl;

	oFile.close();

}
int main()
{
/*CREATE TABLE Persons (
    ID int,
    name varchar(255),
    roll int,
    email varchar(255),
 );*/
    cout<<"Enter command : "<<endl;
    cin>>s1>>s2>>s3>>s4;

	if(s1=="CREATE")createTable();

	return 0;
}
