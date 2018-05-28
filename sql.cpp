 #include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

string s3,s4,s5,s1;
int numOfCol=0;

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
    int numCol;
};

Array *strArr;
Student *rowArr;
string *stringArr;

void structArr(int n)
{
    strArr = new Array[n];
}

string *header;

void headerArr(int n)
{
       header=new  string[n];
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

void readSelectRecordFile()
{
            ifstream iFile;
            iFile.open("selectRecord.txt");

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

void showTable(string matchName)
{
            ifstream showFile;
            showFile.open("ShowTable.txt");
            string s;
            int column=0;
            while(showFile>>s )
            {
                        if(s==matchName)
                        {
                        cout<<"Tablename "<<s<<endl<<endl;
                        while(showFile>>s && s!=".")
                        {
                                    cout<<s<<'\t';
                                    showFile>>s;
                                    cout<<s<<'\t';
                                    cout<<endl;
                                    column++;
                        }
                        break;
                        }
            }

            showFile.close();

             fstream iFile;
            iFile.open("info.txt", ios::in | ios::out);

            string input;
        while(iFile>>input)
        {
            if(input==matchName)
            {
                        iFile>>input;
                        cout<<"Number of rows : "<<input<<endl;
                           cout<<"Number of columns : "<<column<<endl;

                        break;
            }
        }

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
    fstream oFile;

    if(numOfTables==0)       //for the first table entry
    {
        oFile.open("database.txt", ios::app);

        ofstream showFile;
        showFile.open("ShowTable.txt");
        if(s1=="CREATE")
        {
                    oFile<< s3<<endl<<endl;
                    showFile<<s3<<'\t';
        }

        if(s4=="(")
        {
            cin>>s4>>s5;

            while(s4!=")")
            {
                numOfCol++;

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
                 //cout<<"NumOfCol  "<<numOfCol<<endl;

            showFile<<s4<<'\t'<<s5<<'\t';
                cin>>s4>>s5;
            }
        }

        oFile<<endl<<endl;
        oFile.close();

        remove("info.txt");
        oFile.open("info.txt", ios::app);
        oFile<<numOfTables+1<<endl;
        oFile<<s3<<'\t'<<g<<'\t'<<numOfCol<<endl;
        oFile.close();

        showFile<<"."<<endl;
        showFile<<numOfCol<<endl;
        showFile.close();
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
            iInfo>>strArr[i].numOfRows;
            iInfo>>strArr[i].numCol;
        }

        iInfo.close();

        remove("info.txt");

        ofstream oInfo;
        oInfo.open("info.txt", ios::app);
        oInfo<<numOfTables+1<<endl;

        for(int i=0;i<numOfTables;i++)
        {
            oInfo<<strArr[i].tableName<<'\t';
            oInfo<<strArr[i].numOfRows<<'\t';
             oInfo<<strArr[i].numCol<<endl;
        }



        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

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
            getline(dFile,s);

            int indiv=0;
            while(indiv!=strArr[i].numOfRows)
            {
                getline(dFile,stringArr[idx]);
                 idx++;
                 indiv++;
            }
        }

        dFile.close();

        remove("database.txt");

        ofstream aFile;
        aFile.open("database.txt", ios::app);

        idx=0;
        for(int i=0;i<numOfTables;i++)
        {
            aFile<<strArr[i].tableName<<endl<<endl;

            int str=0;
            aFile<<header<<endl<<endl;

             int   indiv=0;
            while(indiv!=strArr[i].numOfRows)
            {
                        aFile<<stringArr[idx]<<endl;
                        idx++;
                        indiv++;
            }

            if(i!=numOfTables-1)aFile<<endl;

         }

         ofstream showFile;
         showFile.open("ShowTable.txt",ios::app);

        if(s1=="CREATE")
        {
                    aFile<< endl<<s3<<endl<<endl;
                    showFile<<s3<<'\t';
        }

        int numcol=0;
        if(s4=="(")
        {
            cin>>s4>>s5;
            while(s4!=")")
            {
                showFile<<s4<<'\t'<<s5<<'\t';
                        numcol++;
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
        showFile<<"."<<endl;
        showFile<<numOfCol<<endl;
        aFile.close();
        showFile.close();

          int g=0;
        oInfo<<s3<<'\t'<<g<<'\t'<<numcol<<endl;
        oInfo.close();
    }

    readDatFile();
    readInfo();
    readNum();
}

void insertTable()
{
     string s6,s7,s8,s9,input;
     int i1,i2;
     int needCol=0;

     int index;
     int sem;
     int numOfTables;

     ifstream iInfo;
     iInfo.open("info.txt", ios::in);
     iInfo>>numOfTables;
     iInfo.close();
     int g=0;

     if(numOfTables==0)
     {
         cout<<"Can't insert. Create a table first."<<endl;
     }

     else
     {
        //  cin>>i1>>s6>>s7>>i2>>s8>>s9;

          ifstream iInfo;
          iInfo.open("info.txt", ios::in);
          iInfo>>numOfTables;

          structArr(numOfTables);

          for(int i=0;i<numOfTables;i++)
          {
              iInfo>>strArr[i].tableName;
              iInfo>>strArr[i].numOfRows;
               iInfo>>strArr[i].numCol;
          }

          iInfo.close();


                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                        if(strArr[i].tableName==s3)
                        {
                            oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)+1<< " "<<strArr[i].numCol<<endl;
                            needCol=strArr[i].numCol;
                        }
                            else
                                 oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
                    }

                    oInfo.close();

                    int sum=0;

                    for(int i=0;i<numOfTables;i++)
                    {
                        sum+=strArr[i].numOfRows;
                    }

                    headerArr(numOfTables);

                    createStringArr(sum);
                        cout<<"sum "<<sum<<endl;

                    string tableName,s,header;

                    ifstream dFile;
                    dFile.open("database.txt", ios::in);

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {

                                    dFile>>tableName;
                                    getline(dFile,s);
                                    getline(dFile,s);
                                    getline(dFile,header);
                                   /* fstream head;
                                    head.open("Header.txt");
                                    head<<header<<endl;
                                    head.close();

                                   //   fstream head;
                                    head.open("Header.txt");
                                    head>>header[i];
                                    head.close();*/


                                    getline(dFile,s);

                                    int individualIndexTable=0;

                                   while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                getline(dFile,stringArr[idx]);
                                                idx++;
                                                individualIndexTable++;
                                    }

                                   if(i!=numOfTables-1)
                                   {
                                               getline(dFile,s);
                                    }
                    }

                    dFile.close();

                    remove("database.txt");

                    ofstream aFile;
                    aFile.open("database.txt", ios::app);

                     cout<<"467 "<<endl;
                     idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                                    aFile<<strArr[i].tableName<<endl<<endl;
                                    ifstream show;
                                    show.open("ShowTable.txt");
                                    string name;
                                    while(show>>name)
                                    {
                                                if(name==strArr[i].tableName)
                                                {
                                                            show>>name;
                                                            while(name!=".")
                                                            {
                                                            aFile<<name;

                                                              show>>name;
                                                              if(name!="INT")
                                                              {
                                                                       int len=name.length();
                                                                        int space=20-len;

                                                                        for(int i=0;i<space-4;)
                                                                        {
                                                                                    aFile<<'\t';
                                                                                    i+=4;
                                                                        }
                                                              }

                                                               aFile<<'\t';

                                                               show>>name;

                                                            }

                                                }
                                    }

                                    aFile<<endl;
                                    show.close();

                                    int individualIndexTable=0;
                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                aFile<<stringArr[idx]<<endl;
                                                idx++;
                                                individualIndexTable++;
                                    }

                                    string c1,c2,s9;
                                    if(strArr[i].tableName==s3)
                                    {

                                                    cin>>s7>>c1;
                                                     cin>>s9>>c2;

                                                aFile<<s7<<'\t'<<s9;

                                                  for(int k=0;k<needCol-2;k++)
                                                  {

                                                              int len=s9.length();
                                                int space=20-len;

                                                   for(int i=0;i<space;)
                                                {
                                                            aFile<<'\t';
                                                            i+=4;
                                                }

                                                cin>>s9>>c2;
                                                aFile<<s9;

                                                  }

                                                aFile<<endl;
                                    }

                                  if(i!=numOfTables-1)  aFile<<endl;
                    }

                   aFile.close();
    }

    readDatFile();
    readInfo();
    readNum();
}


void deleteRow()
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
         cout<<"Can't delete. Create a table  first."<<endl;
     }

     else
     {

            string from,where,row,equ;
            int rowToDelete;
            cin>>from>>s3>>where>>row>>equ>>rowToDelete;

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

                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                        if(strArr[i].tableName==s3)
                            oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)-1<<endl;
                            else
                                 oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<endl;
                    }

                    oInfo.close();

                    int sum=0;

                    for(int i=0;i<numOfTables;i++)
                    {
                        sum+=strArr[i].numOfRows;
                    }

                    sum=sum+1;

                    createStringArr(sum);

                    string tableName,s,header;

                    ifstream dFile;
                    dFile.open("database.txt", ios::in);

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {

                                    dFile>>tableName;
                                    getline(dFile,s);
                                    getline(dFile,s);
                                    getline(dFile,header);
                                    getline(dFile,s);

                                    int individualIndexTable=0;

                                   while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                getline(dFile,stringArr[idx]);
                                                idx++;
                                                individualIndexTable++;
                                    }

                                   if(i!=numOfTables-1)
                                   {
                                               getline(dFile,s);
                                   }
                    }

                    dFile.close();

                    remove("database.txt");

                    ofstream aFile;
                    aFile.open("database.txt", ios::app);

                     cout<<"467 "<<endl;
                     idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                                    aFile<<strArr[i].tableName<<endl<<endl;
                                    aFile<<header<<endl<<endl;

                                    int individualIndexTable=0;

                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                if(strArr[i].tableName==s3 &&  individualIndexTable==rowToDelete-1)
                                                {
                                                            idx++;
                                                            individualIndexTable++;
                                                }

                                                else
                                                {
                                                            aFile<<stringArr[idx]<<endl;
                                                            idx++;
                                                            individualIndexTable++;
                                                }
                                    }

                                  if(i!=numOfTables-1)  aFile<<endl;
                    }
    }

    readDatFile();
    readInfo();
    readNum();
}


void updateRow()
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
         cout<<"Can't update. Create a table  first."<<endl;
     }

     else
     {
            string s3,where,row,equ;
            int rowToUpdate;
            cin>>s3>>where>>row>>equ>>rowToUpdate;

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

                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                            oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)<<endl;
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

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                                    dFile>>tableName;
                                     getline(dFile,s);
                                     getline(dFile,s);
                                    getline(dFile,header);
                                    getline(dFile,s);

                                    int individualIndexTable=0;

                                   while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                getline(dFile,stringArr[idx]);
                                                idx++;
                                                individualIndexTable++;
                                    }

                                   if(i!=numOfTables-1)
                                   {
                                               getline(dFile,s);
                                   }
                    }

                    dFile.close();

                    remove("database.txt");

                    ofstream aFile;
                    aFile.open("database.txt", ios::app);

                     idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                                    aFile<<strArr[i].tableName<<endl<<endl;
                                    aFile<<header<<endl<<endl;

                                    int individualIndexTable=0;

                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                if(strArr[i].tableName==s3 &&  individualIndexTable==rowToUpdate-1)
                                                {
                                                            int i1,i2;
                                                            string c,s7,s9;

                                                            cin>>i1>>c>>s7>>i2>>c>>s9;

                                                            int len=s7.length();
                                                            int space=20-len;

                                                            aFile<< i1<<'\t'<<s7;

                                                            for(int i=0;i<space;)
                                                            {
                                                                        aFile<<'\t';
                                                                        i+=4;
                                                            }

                                                            aFile<<i2<<'\t'<<s9<<endl;

                                                            idx++;
                                                            individualIndexTable++;
                                                }

                                                else
                                                {
                                                            aFile<<stringArr[idx]<<endl;
                                                            idx++;
                                                            individualIndexTable++;
                                                }
                                    }

                                  if(i!=numOfTables-1)  aFile<<endl;
                    }
    }

    readDatFile();
    readInfo();
    readNum();
}

void selectInfo()
{
    string checker;
    string  from,s3;
    cin>>checker;
    int numOfTables;

    ofstream recordFile;
    recordFile.open("selectRecord.txt", ios :: app);

    if(checker=="*")
     {
     cin>>from>>s3;

     string userName,userID;

     cout<<"Enter your name : "<<endl;
     getline(cin,userName);
     getline(cin,userName);
     cout<<"Enter user ID : "<<endl;
     cin>>userID;

     recordFile<<endl<<endl<<userName<<endl;
     recordFile<<userID<<endl;

     recordFile<<endl<<"Checked "<<s3<<endl<<endl;

     ifstream iInfo;
     iInfo.open("info.txt", ios::in);
     iInfo>>numOfTables;
     iInfo.close();
     int g=0;

     if(numOfTables==0)       //for the first table entry
     {
         cout<<"Can't Select. Create a table  first."<<endl;
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
              iInfo>>strArr[i].numOfRows;
          }

          iInfo.close();

                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                            oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)<<endl;
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

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                                    dFile>>tableName;
                                    getline(dFile,s);
                                    getline(dFile,s);
                                    getline(dFile,header);
                                    getline(dFile,s);

                                    int individualIndexTable=0;

                                   while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                getline(dFile,stringArr[idx]);
                                                idx++;
                                                individualIndexTable++;
                                    }

                                   if(i!=numOfTables-1)
                                   {
                                               getline(dFile,s);
                                   }
                    }

                    dFile.close();

                    remove("database.txt");

                    ofstream aFile;
                    aFile.open("database.txt", ios::app);

                     idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {

                                int backUpIdx=idx;
                                if(strArr[i].tableName==s3)
                                {
                                    cout<<endl<<endl<<strArr[i].tableName<<endl<<endl;
                                    cout<<header<<endl<<endl;

                                    int individualIndexTable=0;

                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                cout<<stringArr[idx]<<endl;
                                                individualIndexTable++;
                                                idx++;
                                    }
                                }

                                idx=backUpIdx;

                                    aFile<<strArr[i].tableName<<endl<<endl;
                                    aFile<<header<<endl<<endl;

                                    int individualIndexTable=0;

                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                aFile<<stringArr[idx]<<endl;
                                                idx++;
                                                individualIndexTable++;
                                    }

                                  if(i!=numOfTables-1)  aFile<<endl;
                    }
            }
        }


     else
     {
            string col1,col2;
            col1=checker;
            cin>>col2>>from>>s3;

            string userName,userID;

            cout<<"Enter your name : "<<endl;
            getline(cin,userName);
             getline(cin,userName);
            cout<<"Enter user ID : "<<endl;
            cin>>userID;

            recordFile<<endl<<endl<<userName<<endl;
            recordFile<<userID<<endl;

            recordFile<<endl<<"Checked "<<col1<<" and "<<col2<<" from "<<s3<<endl<<endl;

     ifstream iInfo;
     iInfo.open("info.txt", ios::in);
     iInfo>>numOfTables;
     iInfo.close();
     int g=0;

     if(numOfTables==0)       //for the first table entry
     {
         cout<<"Can't update. Create a table  first."<<endl;
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
              iInfo>>strArr[i].numOfRows;
          }

          iInfo.close();

                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                            oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)<<endl;
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

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                                    dFile>>tableName;
                                     getline(dFile,s);
                                     getline(dFile,s);
                                      getline(dFile,header);
                                    getline(dFile,s);

                                    int individualIndexTable=0;

                                   while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                getline(dFile,stringArr[idx]);
                                                idx++;
                                                individualIndexTable++;
                                    }

                                   if(i!=numOfTables-1)
                                   {
                                               getline(dFile,s);
                                   }
                    }

                    dFile.close();

                    remove("database.txt");

                    ofstream aFile;
                    aFile.open("database.txt", ios::app);

                     idx=0;
                     int storeNumberOfRows=0;
                    for(int i=0;i<numOfTables;i++)
                    {

                                int backUpIdx=idx;
                                if(strArr[i].tableName==s3)
                                {
                                    cout<<endl<<endl<<strArr[i].tableName<<endl<<endl;

                                    ofstream  splitFile;
                                    splitFile.open("Split.txt");

                                    splitFile<<header<<endl;

                                    int individualIndexTable=0;

                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                splitFile<<stringArr[idx]<<endl;
                                                individualIndexTable++;
                                                idx++;
                                    }

                                    splitFile.close();

                                    storeNumberOfRows=strArr[i].numOfRows;
                                }



                                idx=backUpIdx;

                                    aFile<<strArr[i].tableName<<endl<<endl;
                                    aFile<<header<<endl<<endl;

                                    int individualIndexTable=0;

                                    while(individualIndexTable!=strArr[i].numOfRows)
                                    {
                                                aFile<<stringArr[idx]<<endl;
                                                idx++;
                                                individualIndexTable++;
                                    }

                                  if(i!=numOfTables-1)  aFile<<endl;
                    }


                    ifstream splitFileRead;
                    splitFileRead.open("split.txt");

                        string s7="abcdef";
                      int len=s7.length();
                        int space=20-len;

                    string colHeader;
                    int storeCol1,storeCol2;
                    for(int i=0;i<numOfCol;i++)
                    {
                                splitFileRead>>colHeader;
                                if(colHeader==col1)
                                {
                                            cout<<colHeader;

                                                for(int t=0;t<space;)
                                                {
                                                            cout<<'\t';
                                                            t+=4;
                                                }


                                            storeCol1=i;
                                }

                                else if(colHeader==col2)
                                {
                                                cout<<colHeader;
                                                for(int t=0;t<space;)
                                                {
                                                            cout<<'\t';
                                                            t+=4;
                                                }
                                                storeCol2=i;
                                }
                    }

                    cout<<endl;

                     string colValue;

                     for(int i=0;i<storeNumberOfRows;i++)
                     {
                                 for(int j=0;j<4;j++)
                                 {
                                         splitFileRead>>colValue;
                                         if(j==storeCol1)
                                         {
                                                cout<<colValue;
                                                for(int t=0;t<space;)
                                                {
                                                            cout<<'\t';
                                                            t+=4;
                                                }                                         }

                                          if(j==storeCol2)
                                         {
                                                cout<<colValue<<endl;
                                         }
                                 }
                     }

                        splitFileRead.close();
            }
     }

     recordFile.close();
     readSelectRecordFile();
}

int main()
{
    int exit=1;
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

    else if(s1=="DELETE")
    {
            deleteRow();
    }

    else if(s1=="UPDATE")
    {
            updateRow() ;
    }

    else if(s1=="SELECT")
   {
            selectInfo();
   }

   else if(s1=="Show")
   {
               string  table;
               cin>>table;
               showTable(table);
   }

    else cout<<"Command Invalid!"<<endl;

    return 0;
}

