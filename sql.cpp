//Selected whole table
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

        oFile<<endl<<endl;
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

     if(numOfTables==0)
     {
         cout<<"Can't insert. Create a table first."<<endl;
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


                    remove("info.txt");

                    ofstream oInfo;
                    oInfo.open("info.txt", ios::app);
                    oInfo<<numOfTables<<endl;;

                    for(int i=0;i<numOfTables;i++)
                    {
                        if(strArr[i].tableName==s3)
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
                                                aFile<<stringArr[idx]<<endl;
                                                idx++;
                                                individualIndexTable++;
                                    }

                                    if(strArr[i].tableName==s3)
                                    {
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
                        cout<<"sum "<<sum<<endl;

                    string tableName,s,header;

                    ifstream dFile;
                    dFile.open("database.txt", ios::in);

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                       // getline(dFile,s);
                                     dFile>>tableName;
                                     getline(dFile,s);
                                     getline(dFile,s);
                       // getline(dFile,s);

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
                       // getline(dFile,s);
                                     dFile>>tableName;
                                     getline(dFile,s);
                                     getline(dFile,s);
                       // getline(dFile,s);

                        // getline(dFile,s);
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
                                                           // writeTheUpdatedRow();
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

    if(checker=="*")
     {
     cin>>from>>s3;

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
                    cout<<"sum "<<sum<<endl;

                    string tableName,s,header;

                    ifstream dFile;
                    dFile.open("database.txt", ios::in);

                       int idx=0;
                    for(int i=0;i<numOfTables;i++)
                    {
                       // getline(dFile,s);
                                     dFile>>tableName;
                                     getline(dFile,s);
                                     getline(dFile,s);

                        // getline(dFile,s);
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




     }

    readDatFile();
    readInfo();
    readNum();
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

    else cout<<"j"<<endl;



    return 0;
}

