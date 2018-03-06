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
Student s[100];
int ID,roll;
string name,email;
string s1,s2,s3,s4,s5;
string column[10];
string key;
int keyValue;


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

    }

    oFile<<endl;

	oFile.close();

	readDatFile();

}

void insertTable( )
{
     string s6,s7,s8,s9,input;
     int i1,i2;

     int index;

     fstream oNumFile,iNumFile;

     iNumFile.open("num.dat", ios::in);
     iNumFile>>index;
     iNumFile.close();

     cout<<index<<endl;

     int write = index+1;

     remove("num.dat");

     oNumFile.open("num.dat", ios::app);
     oNumFile<<write<<endl;
     oNumFile.close();

    //cout<<index<<endl;
     fstream oFile,iFile;

     oFile.open("database.dat", ios::app);

     iFile.open("database.dat", ios::in);

     iFile>>input;

     if(input==s3)
     {
          cin>>i1>>s6>>s7>>i2>>s8>>s9;

          int len=s7.length();
          int space=20-len;

            s[index].ID=i1;
            s[index].name=s7;
            s[index].roll=i2;
            s[index].email=s9;


            oFile<< s[index].ID<<'\t'<<s[index].name;

            for(int i=0;i<space;)
                {
                    oFile<<'\t';
                    i+=4;
                }


            oFile<<s[index].roll<<'\t'<<s[index].email;

            oFile<<endl;




            //cout<<index<<endl;
     }
         /* while(cin>>s6)
          {

                if(s6==")") break;
                c++;
             if(c==1 || c==3)
             {
                 oFile<<s6<<'\t';
                 if(c==1){
                    s[index].ID=s6;
                }
                else
                {
                    s[index].roll=s6;
                }
             }

             else
             {
                oFile<<s6;
                if(c==2)s[index].name=s6;
                else s[index].email=s6;
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
*/
     else cout<<s3<<" Doesn't Exist. "<<endl;


    cout<<endl;

    iFile.close();
    oFile.close();

    readDatFile();

}

void deleteTable(int index)
{
     fstream oFile,iFile;
     string input,col;

     oFile.open("database.dat", ios::app);

     iFile.open("database.dat", ios::in);

     iFile>>input;
     int targetIndex;

     if(input==s3)
     {
         for(int i=0;i<4;i++)
         {
            iFile>>col;
            column[i]=col;
            if(column[i]==key)targetIndex=i;
         }

         int gotValue;

         if(targetIndex==0)
         {
            cout<<"Index is : "<<index<<endl;

             for(int j=0;j<index;j++)
             {
                 if(s[j].ID==keyValue)gotValue=j;
                    else cout<<"Invalid index"<<endl;
             }

          }

         iFile.close();
         oFile.close();

         remove("database.dat");


         //fstream oFile,iFile;

         oFile.open("database.dat", ios::app);

         for(int i=0;i<4;i++)
         {
             oFile<<column[i]<<'\t';
         }

         for(int i=0;i<index;i++)
         {
             if(i!=gotValue)oFile<<s[i].ID<<'\t'<<s[i].name<<'\t'<<s[i].roll<<'\t'<<s[i].email<<'\t';

         }

         oFile.close();

     }

     else cout<<s3<<" Doesn't Exist. Can't perform the deletion "<<endl;


     readDatFile();

}


int main()
{
    int f=2;
    string where,sem;
    int gh;
    int indexp=0;
    int init=1;

    fstream iNumFile;

 iNumFile.open("num.dat", ios::app);
     iNumFile<<init<<endl;
     iNumFile.close();

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


        if(s1=="DELETE")
        {
            cin>>s2>>s3>>where>>key>>s4>>keyValue>>sem;

            deleteTable(indexp);
        }


       /* for(int i=0;i<indexp;i++)
        {
            cout<<s[i].ID<<'\t'<<s[i].name<<endl;
        }*/

	return 0;
}
