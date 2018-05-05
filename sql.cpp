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
string *stringArr;

void structArr(int n)
{
    strArr = new Array[n];
}

void createRowArr(int n)
{
     rowArr = new Student[n];
}

void createStringArr(int p)
{
    stringArr = new string [p];
}

void readDatFile()
{
    fstream iFile;
    iFile.open("database.txt", ios::in | ios::out);

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
    iFile.open("info.txt", ios::in | ios::out);

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
    iFile.open("num.txt", ios::in | ios::out);

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
    ifstream iFile;

    int sem;
    int numOfTables;

    iFile.open("info.txt", ios::in);
    iFile>>numOfTables;
    iFile.close();
    int g=0;

    if(numOfTables==0)       //for the first table entry
    {

        remove("info.txt");
        ofstream oFile;
        oFile.open("info.txt", ios::app);
        oFile<<numOfTables+1<<endl;
        oFile<<s3<<'\t'<<g<<endl;
        oFile.close();

        oFile.open("database.txt", ios::app);

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
        ifstream iInfo;
        iInfo.open("info.txt", ios::in);
        iInfo>>numOfTables;

        structArr(numOfTables);

        for(int i=0;i<numOfTables;i++)
        {
            iInfo>>strArr[i].tableName;
            cout<<strArr[i].tableName<<endl;
            iInfo>>strArr[i].numOfRows;
            cout<<strArr[i].numOfRows<<endl;
        }

        iInfo.close();

        remove("info.txt");

        ofstream oInfo;
        oInfo.open("info.txt", ios::app);
        oInfo<<numOfTables+1<<endl;

        for(int i=0;i<numOfTables;i++)
        {
            oInfo<<strArr[i].tableName<<'\t';
            oInfo<<strArr[i].numOfRows<<endl;
        }

        int g=0;
        oInfo<<s3<<'\t'<<g<<endl;
        oInfo.close();

        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        cout<<endl<<endl<<"Sum line 206: "<<sum<<endl<<endl;

        createRowArr(sum);
        createStringArr(sum);

        int str=0;
        string tableName,s,header;

        ifstream dFile;
        ofstream doFile;
        dFile.open("database.txt", ios::in);
         int idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
             getline(dFile,s);
             getline(dFile,header);

            while(idx!=strArr[i].numOfRows)
            {
                getline(dFile,stringArr[idx]);
                 cout<<endl<<endl<<"stringArr[idx++] : "<<stringArr[idx]<<endl<<endl;
                 idx++;
            }
        }

        dFile.close();

        remove("database.txt");

        ofstream aFile;
        aFile.open("database.txt", ios::app);

        for(int i=0;i<numOfTables;i++)
        {
            aFile<<strArr[i].tableName<<endl<<endl;

            int str=0;
            aFile<<header<<endl;
            int j;
            for(j=0;j<3;j++)
            {
                aFile<<stringArr[j]<<endl;
            }

         }

        if(s1=="CREATE")aFile<< endl<<s3<<endl<<endl;

        if(s4=="(")
        {
            cin>>s4>>s5;
            while(s4!=")")
            {
                if(s5=="int")
                {
                    aFile<<s4<<'\t';
                }

                else if(s5=="VARCHAR")
                {
                    aFile<<s4;
                    int len=s4.length();
                    int space=20-len;

                    for(int i=0;i<space;)
                    {
                        aFile<<'\t';
                        i+=4;
                    }
                }

                cin>>s4>>s5;
            }
        }

        aFile<<endl;

        aFile.close();
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
     int sem;
     int numOfTables;

     ifstream iInfo;
     iInfo.open("info.txt", ios::in);
     iInfo>>numOfTables;
     iInfo.close();
     int g=0;

     if(numOfTables==0)       //for the first table entry
     {
         cout<<"Can't insert. Create a table first."<<endl;
     }

     else if(numOfTables==1)
     {
          ifstream iInfo;
          iInfo.open("info.txt", ios::in);
          iInfo>>numOfTables;

          structArr(numOfTables);

          iInfo>>strArr[0].tableName;
          iInfo>>strArr[0].numOfRows;

          iInfo.close();

          remove("info.txt");

          ofstream oInfo;
          oInfo.open("info.txt", ios::app);
          oInfo<<numOfTables<<endl;
          oInfo<<strArr[0].tableName<<" "<<(strArr[0].numOfRows)+1<<endl;
          oInfo.close();

          ifstream iFile;
          iFile.open("database.txt", ios::in);
          iFile>>input;
          iFile.close();

          ofstream oFile;
          oFile.open("database.txt", ios::app);

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

            oFile.close();
     }

     else
     {
          cin>>i1>>s6>>s7>>i2>>s8>>s9;

          ifstream iInfo;
          iInfo.open("info.txt", ios::in);
          iInfo>>numOfTables;

          structArr(numOfTables);

          for(int i=0;i<numOfTables;i++)
          {
              iInfo>>strArr[i].tableName;
              iInfo>>strArr[i].numOfRows;
          }

          iInfo.close();


                if(strArr[numOfTables-1].tableName==s3)
                {
                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                        if(i==numOfTables-1)
                            oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)+1<<endl;
                            else
                                 oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<endl;
                    }

                    oInfo.close();

                    int sum=0;

                    for(int i=0;i<numOfTables;i++)
                    {
                        sum+=strArr[i].numOfRows;
                    }

                    createStringArr(sum);

                    string tableName,s,header;

                    ifstream dFile;
                    dFile.open("database.txt", ios::in);

                    for(int i=0;i<numOfTables;i++)
                    {
                        dFile>>tableName;
                        getline(dFile,s);
                        getline(dFile,s);
                       // getline(dFile,s);
                        //getline(dFile,s);
                        getline(dFile,header);

                        int idx=0;

                        while(idx!=strArr[i].numOfRows)
                        {
                            getline(dFile,stringArr[idx]);
                            cout<<"hmmm"<<endl;
                            cout<<endl<<endl<<"stringArr[idx++] : "<<stringArr[idx]<<endl<<endl;
                            idx++;
                        }
                    }

                    dFile.close();

                    remove("database.txt");

                    ofstream aFile;
                    aFile.open("database.txt", ios::app);

                    for(int i=0;i<numOfTables;i++)
                    {
                        aFile<<strArr[i].tableName<<endl<<endl;
                        aFile<<header<<endl<<endl;

                        int idx=0;
                        while(idx!=strArr[i].numOfRows)
                        {
                            aFile<<stringArr[idx]<<endl;
                            idx++;
                        }
                    }


                    int len=s7.length();
                    int space=20-len;

                    aFile<< i1<<'\t'<<s7;

                    for(int i=0;i<space;)
                    {
                        aFile<<'\t';
                        i+=4;
                    }

                    aFile<<i2<<'\t'<<s9;

                    aFile<<endl;

                    aFile.close();
                }

                else
                {
                    cout<<endl<<"Check tablename ."<<endl<<endl;
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

    iInfo.open("info.txt", ios::app);
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

