#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

struct Student
{
    int ID;
    string name;
    int roll;
    string email;
};

int cnt=0,c=0;

int ID,roll;
string name,email;
string s1,s2,s3,s4,s5;
string column[10];
string key;
string colName,cId;
int in;
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
    oFile.open("info.dat", ios::app);

    if(s1=="CREATE")oFile<< s3<<endl<<endl;

    if(s4=="(")
    {
        cin>>s4>>s5;
        while(s4!=")")
        {
            cnt++;
           // numRow++;


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

     fstream oNumFile,iInfo,iNumFile;

     iNumFile.open("num.dat", ios::in);
     iNumFile>>index;
     iNumFile.close();

     //cout<<index<<endl;

     int write = index+1;

     remove("num.dat");

     oNumFile.open("num.dat", ios::app);
     oNumFile<<write<<endl;
     oNumFile.close();

     fstream oFile,iFile;

     oFile.open("database.dat", ios::app);

     iFile.open("database.dat", ios::in);

     iFile>>input;

     string tableName=s3;
     int numRows=write;

     iInfo.open("info.dat", ios::app);
     iInfo<<tableName<<'\t'<<numRows<<'\t'<<4<<'\t'<<endl;
     iInfo.close();




     if(input==s3)
     {
          cin>>i1>>s6>>s7>>i2>>s8>>s9;

          int len=s7.length();
          int space=20-len;

          oFile<< i1<<'\t'<<s7;

          for(int i=0;i<space;)
          {
              oFile<<'\t';
              i+=4;
          }

          oFile<<i2<<'\t'<<s9;

          oFile<<endl;

     }

     else cout<<endl<<s3<<" Doesn't Exist. "<<endl;

     cout<<endl;

     iFile.close();
     oFile.close();

     readDatFile();
}

void deleteTable()
{
     fstream oFile,iFile;
     string input,col;

     oFile.open("database.dat", ios::app);
     iFile.open("database.dat", ios::in);

     iFile>>input;
     int targetIndex;
     int col1,col3;
     string col2,col4;

     if(input==s3)
     {
         for(int i=0;i<4;i++)
         {
            iFile>>col;
            column[i]=col;
            if(column[i]==key)targetIndex=i;
         }

         int gotValue;
         int index;

         fstream iNumFile;

         iNumFile.open("num.dat", ios::in);
         iNumFile>>index;
         iNumFile.close();

         Student *s = new Student[index];

         iFile>>col1>>col2>>col3>>col4;

         for(int j=0;j<index;j++)
         {
              s[j].ID=col1;
              s[j].name=col2;
              s[j].roll=col3;
              s[j].email=col4;

              iFile>>col1>>col2>>col3>>col4;

         }

         cout<<index<<endl;

         for(int i=0;i<index;i++)
         {
            cout<<s[i].ID<<'\t'<<s[i].name<<s[i].roll<<'\t'<<s[i].email<<'\t'<<endl;
         }

         if(targetIndex==0)
         {
             //cout<<"Index is : "<<index<<endl;
             for(int j=0;j<index-1;j++)
             {
                 if(s[j].ID==keyValue)gotValue=j;
                    else cout<<"Invalid index"<<endl;
             }
         }

         iFile.close();
         oFile.close();

         remove("database.dat");

         oFile.open("database.dat", ios::app);

         oFile<<input<<endl;

         for(int i=0;i<4;i++)
         {
             if(i==1)
             {
                 int len= column[i].length();
                 int space=20-len;

                 oFile<<column[i];

                 for(int i=0;i<space;)
                 {
                    oFile<<'\t';
                    i+=4;
                 }
             }

             else
             {
                 oFile<<column[i];
                 oFile<<'\t';
             }
         }

         oFile<<endl;

         for(int i=0;i<index-1;i++)
         {
             if(i!=gotValue)
             {
                int len=(s[i].name).length();
                int space=20-len;

                oFile<< s[i].ID<<'\t'<<s[i].name;

                for(int i=0;i<space;)
                {
                    oFile<<'\t';
                    i+=4;
                }

                oFile<<s[i].roll<<'\t'<<s[i].email<<'\t'<<endl;
             }
         }

         oFile.close();
     }

     else cout<<s3<<" Doesn't Exist. Can't perform the deletion "<<endl;

     readDatFile();

}

void updateTable()
{
     fstream oFile,iFile;
     string input,col;

     oFile.open("database.dat", ios::app);
     iFile.open("database.dat", ios::in);

     iFile>>input;
     int targetIndex;
     int col1,col3;
     string col2,col4;

     if(input==s3)
     {
         for(int i=0;i<4;i++)
         {
            iFile>>col;
            column[i]=col;
            if(column[i]==colName)targetIndex=i;
         }

         int gotValue;
         int index;

         fstream iNumFile;

         iNumFile.open("num.dat", ios::in);
         iNumFile>>index;
         iNumFile.close();

         Student *s = new Student[index];

         iFile>>col1>>col2>>col3>>col4;

         for(int j=0;j<index;j++)
         {
              s[j].ID=col1;
              s[j].name=col2;
              s[j].roll=col3;
              s[j].email=col4;

              iFile>>col1>>col2>>col3>>col4;

         }

         for(int i=0;i<index;i++)
         {
            cout<<s[i].ID<<'\t'<<s[i].name<<s[i].roll<<'\t'<<s[i].email<<'\t'<<endl;
         }

            //cout<<"Index is : "<<index<<endl;
             for(int j=0;j<index-1;j++)
             {
                 if(s[j].ID==in)
                 {
                    /*if(targetIndex==0)
                    {
                        int x;
                        istringstream iss;
                        iss>>keyValue;
                        iss<<x;
                        s[j].ID=x;
                    }*/

                    if(targetIndex==1)
                    {
                        s[j].name=keyValue;
                    }

                    /*else if(targetIndex==2)
                    {
                        int x;
                        istringstream iss(keyValue);
                        iss<<x;
                        s[j].roll=x;
                    }*/

                    else if(targetIndex==4)
                    {
                        s[j].email=keyValue;
                    }
                 }

                 else cout<<"Invalid index"<<endl;
             }

         iFile.close();
         oFile.close();

         remove("database.dat");

         oFile.open("database.dat", ios::app);

         oFile<<input<<endl;

         for(int i=0;i<4;i++)
         {
             if(i==1)
             {
                 int len= column[i].length();
                 int space=20-len;

                 oFile<<column[i];

                 for(int i=0;i<space;)
                 {
                    oFile<<'\t';
                    i+=4;
                 }
             }

             else
             {
                 oFile<<column[i];
                 oFile<<'\t';
             }
         }

         oFile<<endl;


         for(int i=0;i<index-1;i++)
         {

             int len=(s[i].name).length();
             int space=20-len;

             oFile<< s[i].ID<<'\t'<<s[i].name;

             for(int i=0;i<space;)
             {
               oFile<<'\t';
               i+=4;
             }

             oFile<<s[i].roll<<'\t'<<s[i].email<<'\t'<<endl;
         }

         oFile.close();

     }

     else cout<<s3<<" Doesn't Exist. Can't perform the deletion "<<endl;

     readDatFile();

}

int main()
{
    string where,sem;
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

    else if(s1=="INSERT")
    {
        cin>>s2>>s3>>s4>>s5;
        insertTable();
    }

    else if(s1=="DELETE")
    {
        cin>>s2>>s3>>where>>key>>s4>>keyValue>>sem;
        deleteTable();
    }

    else if(s1=="UPDATE")
    {
        cin>>s3>>s2>>colName>>s4>>keyValue>>where>>cId>>s5>> in>>sem;
        updateTable();
    }

	return 0;
}
