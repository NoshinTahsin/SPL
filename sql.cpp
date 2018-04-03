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

void readInfo()
{
    fstream iFile;
    iFile.open("info.dat", ios::in | ios::out);

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

void readNum()
{
    fstream iFile;
    iFile.open("num.dat", ios::in | ios::out);

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
    int numOfTables;

    iInfo.open("info.dat", ios::app);
    iInfo>>numOfTables;
    iInfo.close();
    int g=0;

    if(numOfTables==0)       //for the first table entry
    {

        remove("info.dat");

        iInfo.open("info.dat", ios::app);
        iInfo<<numOfTables+1<<endl;
        iInfo<<s3<<'\t'<<g<<endl;
        iInfo.close();

        oFile.open("database.dat", ios::app);
    //oFile.open("info.dat", ios::app);

        if(s1=="CREATE")oFile<< s3<<endl<<endl;

        if(s4=="(")
        {
            cin>>s4>>s5;
            while(s4!=")")
            {
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
        readInfo();
        readNum();
    }

    else
    {
        iInfo.open("info.dat", ios::app);
        iInfo>>numOfTables;
        iInfo.close();

        structArr(numOfTables);

        for(int i=0;i<numOfTables;i++)
        {
            iInfo>>strArr[i].tableName;
            iInfo>>strArr[i].numOfRows;
        }

        remove("info.dat");

        iInfo.open("info.dat", ios::app);
        iInfo<<numOfTables+1<<endl;

        for(int i=0;i<numOfTables;i++)
        {
            iInfo<<strArr[i].tableName<<'\t';
            iInfo<<strArr[i].numOfRows<<endl;
        }

        int sum;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        createRowArr(sum);

        int g=0;
        iInfo<<s3<<'\t'<<g<<endl;
        iInfo.close();

        int str=0;

        for(int i=0;i<numOfTables;i++)
        {
            iFile>>tableName;
            getLine(iFile,s);

            for(int j=str;j<strArr[i].numOfRows;j++)
            {
                iFile>>rowArr[j].ID;
                iFile>>rowArr[j].name;
                iFile>>rowArr[j].roll;
                iFile>>rowArr[j].email;
            }

            str=j;
        }

        remove("database.dat");


        for(int i=0;i<numOfTables;i++)
        {
            iFile<<strArr[i].tableName<<endl;

            int str=0;

            for(int j=str;j<strArr[i].numOfRows;j++)
            {
                int len=(rowArr[j].name).length();
                int space=20-len;

                iFile<<rowArr[j].ID<<'\t'<<rowArr[j].name;

                for(int k=0;k<space;)
                {
                    iFile<<'\t';
                    k+=4;
                }

                iFile<<rowArr[j].roll<<'\t'<<rowArr[j].email<<'\t'<<endl;

                str=j;
             }
         }

        oFile.open("database.dat", ios::app);
    //oFile.open("info.dat", ios::app);

        if(s1=="CREATE")oFile<< s3<<endl<<endl;

        if(s4=="(")
        {
            cin>>s4>>s5;
            while(s4!=")")
            {
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
        readInfo();
        readNum();
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
      numRows=write;

     remove("info.dat");
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
     readInfo();
     readNum();
}


int main()
{
    int init=0;
    cout<<"Enter command : "<<endl;
    cin>>s1;

    fstream iNumFile;
    fstream iInfo;

    iNumFile.open("num.dat", ios::app);
    iNumFile<<init<<endl;
    iNumFile.close

    iNumFile.open("num.dat", ios::app);
    iNumFile>>init;
    iNumFile.close();

    iInfo.open("info.dat", ios::app);
    iInfo<<init;
    iInfo.close();


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

    return 0;

}

