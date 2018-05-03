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
//string *rowArr;
string *stringArr;

void structArr(int n)
{
    strArr = new Array[n];
}

void createRowArr(int n)
{
     rowArr = new Student[n];
     // rowArr=new string[n];

 /*   for(int i=0;i<n;i++)
    {

        rowArr[i].ID=0;
        rowArr[i].name=" ";
        rowArr[i].roll=0;
        rowArr[i].email=" ";

    }*/
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
        // doFile.open("databaseNew.txt", ios::out);
        int idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
           // getline(dFile,s);
            getline(dFile,s);
            //doFile<<tableName<<endl;
            getline(dFile,header);
            //doFile<<header<<endl; //headers
          //  getline(dFile,s);
         // getline(dFile,s);

            while(idx!=strArr[i].numOfRows)
            {
                getline(dFile,stringArr[idx]);
                //doFile<<stringArr[idx++]<<endl;
                cout<<endl<<endl<<"stringArr[idx++] : "<<stringArr[idx]<<endl<<endl;
                //getline(dFile,s);
                //cout<<" kkkkkkkkkkkkkk       "<<s<<endl;
                idx++;
              //  cout<<"hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"<<endl;
            }












        /*   dFile>>tableName;
            getline(dFile,s);

            int j;
            string lo;
            for(j=str;j<strArr[i].numOfRows;j++)
            {
               cout<<endl<<endl<<"j : "<<j<<endl<<endl;
               readDatFile();// cout<<endl<<endl<<"strArr[i].numOfRows :"<<strArr[i].numOfRows<<endl<<endl;
               dFile>>rowArr[j].ID;
                cout<<rowArr[j].ID<<endl;
                dFile>>rowArr[j].name;
                cout<<rowArr[j].name<<endl;
                dFile>>rowArr[j].roll;
                cout<<rowArr[j].roll<<endl;
                dFile>>rowArr[j].email;
                cout<<rowArr[j].email<<endl;

                //getline(iFile,lo);
               // cout<<lo<<endl;

                //rowArr[j]=lo;
            }*/


        }

        dFile.close();
        //doFile.close();

        remove("database.txt");

        ofstream aFile;
        aFile.open("database.txt", ios::app);

        for(int i=0;i<numOfTables;i++)
        {
            aFile<<strArr[i].tableName<<endl;

            int str=0;
            aFile<<header<<endl;
            int j;
            for(j=0;j<3;j++)
            {
                aFile<<stringArr[j]<<endl;




              /* int len=(rowArr[j].name).length();
                int space=20-len;

                aFile<<rowArr[j].ID<<'\t'<<rowArr[j].name;

                for(int k=0;k<space;)
                {
                    aFile<<'\t';
                    k+=4;
                }

                aFile<<rowArr[j].roll<<'\t'<<rowArr[j].email<<'\t'<<endl;

                //iFile<<rowArr[j]<<endl;*/


             }

           // str=j;
         }

        if(s1=="CREATE")aFile<< s3<<endl<<endl;

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
          int storeTableNo;
          cin>>i1>>s6>>s7>>i2>>s8>>s9;
          ifstream iInfo;
          iInfo.open("info.txt", ios::in);
          iInfo>>numOfTables;

          structArr(numOfTables);

          for(int i=0;i<numOfTables;i++)
          {
              iInfo>>strArr[i].tableName;
              if(s3==strArr[i].tableName) storeTableNo=i+1;
              iInfo>>strArr[i].numOfRows;
          }

          iInfo.close();

          remove("info.txt");

          ofstream oInfo;
          oInfo.open("info.txt", ios::app);
          oInfo<<numOfTables;
          for(int i=0;i<numOfTables;i++)
          {
            if(i==storeTableNo-1)oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)+1<<endl;
                else oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)<<endl;
          }

          oInfo.close();

          if(storeTableNo==numOfTables)
          {
                int sum=0;
                string s;

                for(int i=0;i<numOfTables;i++)
                {
                    sum+=strArr[i].numOfRows;
                }

                cout<<sum<<endl;

                createRowArr(sum);

                ifstream iFile;
                iFile.open("database.txt", ios::in);

//                oFile>>datNumOfTables;
                string lo;
                int smt=0;
                int j;
                for(int i=0;i<numOfTables;i++)
                {
                    iFile>>input;
                    getline(iFile,s);
                    for(j=smt;j<strArr[i].numOfRows;j++)
                    {
                         /*  getline(oFile,lo);
                         cout<<lo<<endl;
                         rowArr[j]=lo;*/

                        iFile>>rowArr[j].ID;
                        // cout<<rowArr[j].ID<<endl;
                        iFile>>rowArr[j].name;
                        // cout<<rowArr[j].name<<endl;
                        iFile>>rowArr[j].roll;
                        // cout<<rowArr[j].roll<<endl;
                        iFile>>rowArr[j].email;
                        // cout<<rowArr[j].email<<endl;

                    }

                    smt=j;
                }

                iFile.close();

                remove("database.txt");


                ofstream aFile;
                aFile.open("database.txt", ios::app);

               // oFile<<numOfRows<<endl;

                int len=s7.length();
                int space=0;
                space=20-len;
                smt=0;
                for(int i=0;i<numOfTables;i++)
                {
                    aFile<<strArr[i].tableName<<endl;
                     aFile<<s<<endl;

                    for(j=smt;j<strArr[i].numOfRows;j++)
                    {
                        aFile<<rowArr[j].ID<<'\t'<<rowArr[j].name;

                        for(int i=0;i<space;)
                        {
                            aFile<<'\t';
                            i+=4;
                        }

                        aFile<<rowArr[j].roll<<'\t'<<rowArr[j].email;
                        smt=j;

                       // oFile<<rowArr[j]<<endl;
                    }


                }

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

