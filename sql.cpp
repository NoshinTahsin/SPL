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

int cnt=0,c=0;
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
        cin>>s4>>s5;
        while(s4!=")")
        {
            cnt++;
            if(s5=="int")
            {
                oFile<<s4<<'\t';
            }

            else if(s5=="VARCHAR")
            {
                oFile<<s4;
                int len=s4.length();
                int space=20-len;

                for(int i=0;i<space;)
                {
                    oFile<<'\t';
                    i+=4;
                }

            }


             cin>>s4>>s5;
        }

  //  cin>>sem;

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
          while(cin>>s6)
          {

                if(s6==")") break;
                c++;
             if(c==1 || c==3)oFile<<s6<<'\t';
             else
             {
                oFile<<s6;
                int len=s6.length();
                int space=20-len;

                for(int i=0;i<space;)
                {
                    oFile<<'\t';
                    i+=4;
                }
             }



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
