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
string s1,s2,s3,s4,s5;


void readDatFile()
{
    fstream iFile;
    iFile.open("database.dat", ios::in | ios::out);
    if(iFile.is_open())
    {
        string input;
        while(getline(iFile,input))
        {
            cout<<input<<endl;
        }
    }

    cout<<endl;

    iFile.close();

}

void createTable()
{
    fstream oFile;

    int sem;

    oFile.open("database.dat", ios::app);

    if(s1=="CREATE")oFile<< s3<<endl<<endl;

    if(s4=="(")
    {
        cin>>s4;
        while(s4!=")")
        {

            oFile<<s4<<'\t';
            cin>>s4;
        }

    cin>>sem;

    }
    oFile<<endl;

	oFile.close();

	readDatFile();

}

void insertTable()
{
     string s6,s7,s9,input;

     fstream oFile,iFile;

     oFile.open("database.dat", ios::app);

     iFile.open("database.dat", ios::in);

     iFile>>input;

     if(input==s3)
     {
          while(cin>>s6>>s7)
          {
             oFile<<s6<<'\t';
             if(s7==")") break;
          }

           oFile<<endl;

     }

     else cout<<s3<<" Doesn't Exist. "<<endl;


    cout<<endl;

    iFile.close();
    oFile.close();

    readDatFile();

}


int main()
{
    int f=2;
    string s;
    int gh;


        cout<<"Enter command : "<<endl;
         cin>>s1;


        if(s1=="CREATE")
        {
            cin>>s2>>s3>>s4;
            createTable();
        }


         if(s1=="INSERT")
        {
            cin>>s2>>s3>>s4>>s5;
             insertTable();
        }



	return 0;
}
