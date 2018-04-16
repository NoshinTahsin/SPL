  #include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

string s3,s4,s5,s1;

struct Student
{
    int ID;
    string name;
    int roll;
    string email;
};

struct Array
{
    string tableName;
    int numOfRows;
};

Array *strArr;
Student *rowArr;

void structArr(int n)
{
    strArr = new Array[n];
}

void createRowArr(int n)
{
    rowArr = new Student[n];
}

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
    fstream iInfo,oFile;

    int sem;
    int numOfTables;

    iInfo.open("info.dat", ios::in);
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
    }

    else
    {
        iInfo.open("info.dat", ios::in);
        iInfo>>numOfTables;

        structArr(numOfTables);

        for(int i=0;i<numOfTables;i++)
        {
            iInfo>>strArr[i].tableName;
            iInfo>>strArr[i].numOfRows;
        }

        iInfo.close();

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
        string tableName,s;

        fstream iFile;
        iFile.open("database.dat", ios::in);

        for(int i=0;i<numOfTables;i++)
        {
            iFile>>tableName;
            getline(iFile,s);

            int j;

            for(j=str;j<strArr[i].numOfRows;j++)
            {
                iFile>>rowArr[j].ID;
                iFile>>rowArr[j].name;
                iFile>>rowArr[j].roll;
                iFile>>rowArr[j].email;
            }

            str=j;
        }

        iFile.close();

        remove("database.dat");

        iFile.open("database.dat", ios::app);

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

        if(s1=="CREATE")iFile<< s3<<endl<<endl;

        if(s4=="(")
        {
            cin>>s4>>s5;
            while(s4!=")")
            {
                if(s5=="int")
                {
                    iFile<<s4<<'\t';
                }

                else if(s5=="VARCHAR")
                {
                    iFile<<s4;
                    int len=s4.length();
                    int space=20-len;

                    for(int i=0;i<space;)
                    {
                        iFile<<'\t';
                        i+=4;
                    }

                }

                cin>>s4>>s5;
            }
        }

        iFile<<endl;

        iFile.close();
    }

    readDatFile();
    readInfo();
    readNum();
}

void insertTable()
{
     string s6,s7,s8,s9,input;
     int i1,i2;

     int index;

     fstream iInfo,oFile,iFile;

     int sem;
     int numOfTables;

     iInfo.open("info.dat", ios::in);
     iInfo>>numOfTables;
     iInfo.close();
     int g=0;

     if(numOfTables==0)       //for the first table entry
     {
         cout<<"Can't insert. Create a table first."<<endl;
     }

     else if(numOfTables==1)
     {
          iInfo.open("info.dat", ios::in);
          iInfo>>numOfTables;

          structArr(numOfTables);

          iInfo>>strArr[0].tableName;
          iInfo>>strArr[0].numOfRows;

          iInfo.close();

          remove("info.dat");

          iInfo.open("info.dat", ios::app);
          iInfo<<numOfTables;
          iInfo<<strArr[0].tableName<<" "<<(strArr[0].numOfRows)+1<<endl;
          iInfo.close();

          iFile.open("database.dat", ios::in);
          iFile>>input;
          iFile.close();

          oFile.open("database.dat", ios::app);

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
     }

     else
     {
          int storeTableNo;
          cin>>i1>>s6>>s7>>i2>>s8>>s9;
          iInfo.open("info.dat", ios::in);
          iInfo>>numOfTables;

          structArr(numOfTables);

          for(int i=0;i<numOfTables;i++)
          {
              iInfo>>strArr[i].tableName;
              if(s3==strArr[i].tableName) storeTableNo=i+1;
              iInfo>>strArr[i].numOfRows;
          }

          iInfo.close();

          remove("info.dat");

          iInfo.open("info.dat", ios::app);
          iInfo<<numOfTables;
          for(int i=0;i<numOfTables;i++)
          {
            if(i==storeTableNo-1)iInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)+1<<endl;
                else iInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)+1<<endl;
          }

          iInfo.close();

          if(storeTableNo==numOfTables)
          {
                int sum;
                string s;

                for(int i=0;i<numOfTables;i++)
                {
                    sum+=strArr[i].numOfRows;
                }

                createRowArr(sum);

                oFile.open("database.dat", ios::in);

//                oFile>>datNumOfTables;

                int smt=0;
                int j;
                for(int i=0;i<numOfTables;i++)
                {
                    oFile>>input;
                    getline(oFile,s);
                    for(j=smt;j<strArr[i].numOfRows;j++)
                    {
                        oFile>>rowArr[j].ID>>rowArr[j].name>>rowArr[j].roll>>rowArr[j].email;
                    }
                }

                oFile.close();

                remove("database.dat");

                oFile.open("database.dat", ios::in);

               // oFile<<numOfRows<<endl;

                int len=s7.length();
                int space=20-len;

                for(int i=0;i<numOfTables;i++)
                {
                    oFile<<strArr[i].tableName<<endl;
                    oFile<<s<<endl;

                    for(j=smt;j<strArr[i].numOfRows;j++)
                    {
                        oFile<<rowArr[j].ID<<'\t'<<rowArr[j].name;

                         for(int i=0;i<space;)
                        {
                            oFile<<'\t';
                            i+=4;
                        }

                        oFile<<rowArr[j].roll<<'\t'<<rowArr[j].email;
                    }


                }

                oFile<< i1<<'\t'<<s7;

                for(int i=0;i<space;)
                {
                    oFile<<'\t';
                    i+=4;
                }

                oFile<<i2<<'\t'<<s9;

                oFile<<endl;


                oFile.close();


          }

     }


    readDatFile();
    readInfo();
    readNum();


}

int main()
{
    string s2;
    int init=0;
    cout<<"Enter command : "<<endl;
    cin>>s1;

    fstream iNumFile;
    fstream iInfo;

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

    else cout<<"j"<<endl;

    return 0;
}

