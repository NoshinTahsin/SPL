#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

string s3,s4,s5,s1;
int numOfCol=0;
int needCol;

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

void createRowArr(int n)
{
    rowArr = new Student[n];
}

void createStringArr(int p)
{
    stringArr = new string [p];
}

string *header;
void createHeaderArray(int p)
{
    header=new string[p];
}

void readDatFile()
{
    ifstream iFile;
    iFile.open("database.txt");

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
    ifstream iFile;
    iFile.open("info.txt");

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
    bool flag=false;
    while(showFile>>s )
    {
        if(s==matchName)
        {
            cout<<endl<<"Tablename "<<s<<endl<<endl;
            while(showFile>>s && s!=".")
            {
                cout<<s<<'\t';
                showFile>>s;
                cout<<s<<'\t';
                cout<<endl;
                column++;
            }

            flag=true;

            break;
        }
    }

    if(flag==true)
    {
        cout<<endl<<endl<<"ShowTable operation completed!"<<endl<<endl;
    }

    else
    {
        cout<<endl<<endl<<"Can't show table."<<endl<<"Table doesn't exist."<<endl<<endl;
    }

    showFile.close();

    ifstream iFile;
    iFile.open("info.txt");

    string input;
    while(iFile>>input)
    {
        if(input==matchName)
        {
            iFile>>input;
            cout<<"Number of rows : "<<input<<endl;
            iFile>>input;
            cout<<"Number of columns : "<<input<<endl;
            //cout<<"Number of columns : "<<column<<endl;
            break;
        }
    }

    iFile.close();
}

void createTable()
{
    int sem;
    int numOfTables;

    ifstream iFile;
    iFile.open("info.txt");
    iFile>>numOfTables;
    iFile.close();

    int g=0;

    if(numOfTables==0)
    {
        ofstream oFile;
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
                oFile<<s4<<'\t'<<'\t'<<'\t';
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
        showFile.close();

        cout<<endl<<endl<<"Table created successfully!"<<endl<<endl;
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
        createHeaderArray(sum);

        int str=0;
        string tableName,s;

        ifstream dFile;
        dFile.open("database.txt", ios::in);

        int idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
            getline(dFile,s);
            getline(dFile,header[i]);
            getline(dFile,s);

            int individualTableIndex=0;

            while(individualTableIndex!=strArr[i].numOfRows)
            {
                getline(dFile,stringArr[idx]);
                 idx++;
                 individualTableIndex++;
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
            aFile<<header[i]<<endl<<endl;

            int individualTableIndex=0;

            while(individualTableIndex!=strArr[i].numOfRows)
            {
                        aFile<<stringArr[idx]<<endl;
                        idx++;
                        individualTableIndex++;
            }

            if(i!=numOfTables-1)aFile<<endl;

         }

         ofstream showFile;
         showFile.open("ShowTable.txt",ios::app);

        if(s1=="CREATE")
        {
            aFile<<endl<<s3<<endl<<endl;
            showFile<<s3<<'\t';
        }

        numOfCol=0;

        if(s4=="(")
        {
            cin>>s4>>s5;
            while(s4!=")")
            {
                showFile<<s4<<'\t'<<s5<<'\t';
                numOfCol++;
                aFile<<s4<<'\t'<<'\t'<<'\t';
                cin>>s4>>s5;
            }
        }

        oInfo<<s3<<'\t'<<g<<'\t'<<numOfCol<<endl;
        oInfo.close();

        aFile<<endl;
        showFile<<"."<<endl;
        aFile.close();
        showFile.close();

        cout<<endl<<endl<<"Table created successfully!"<<endl<<endl;
    }

    //readDatFile();
    //readInfo();
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
            {
                oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
            }
        }

        oInfo.close();

        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        createStringArr(sum);

        if(sum==0)
        {
            createHeaderArray(2);
        }

        else
        {
            createHeaderArray(sum);
        }

        string tableName,s;

        ifstream dFile;
        dFile.open("database.txt", ios::in);

        int idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
            getline(dFile,s);
            getline(dFile,header[i]);
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
            aFile<<header[i]<<endl<<endl;

            int individualIndexTable=0;

            while(individualIndexTable!=strArr[i].numOfRows)
            {
                aFile<<stringArr[idx]<<endl;
                idx++;
                individualIndexTable++;
            }

            string ss;

            if(strArr[i].tableName==s3)
            {
                cin>>s7>>ss;

                while(1)
                {
                    aFile<<s7<<'\t'<<'\t'<<'\t';
                    if(ss==")")break;
                    cin>>s7>>ss;
                }

                aFile<<endl;
            }

            if(i!=numOfTables-1)  aFile<<endl;
        }

        aFile.close();
    }

    cout<<endl<<endl<<"Row inserted in "<<s3<<" successfully!"<<endl<<endl;
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

     if(numOfTables==0)
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
            iInfo>>strArr[i].numCol;
        }

        iInfo.close();

        remove("info.txt");

        ofstream oInfo;
        oInfo.open("info.txt", ios::app);
        oInfo<<numOfTables<<endl;

        for(int i=0;i<numOfTables;i++)
        {
            if(strArr[i].tableName==s3)
            {
                oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)-1<< " "<<strArr[i].numCol<<endl;
                needCol=strArr[i].numCol;
            }

            else
            {
                oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
            }
        }

        oInfo.close();

        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        sum=sum+1;

        createStringArr(sum);

        if(sum==0)
        {
            createHeaderArray(2);
        }

        else
        {
            createHeaderArray(sum);
        }

        string tableName,s;

        ifstream dFile;
        dFile.open("database.txt", ios::in);

        int idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
            getline(dFile,s);
            getline(dFile,header[i]);
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
            aFile<<header[i]<<endl<<endl;

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

    cout<<endl<<endl<<"Row deleted from "<<s3<<" successfully!"<<endl<<endl;
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
     string s3;

     if(numOfTables==0)
     {
         cout<<"Can't update. Create a table  first."<<endl;
     }

     else
     {
        string  where,row,equ;
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
            iInfo>>strArr[i].numCol;
        }

        iInfo.close();

        remove("info.txt");

        ofstream oInfo;
        oInfo.open("info.txt", ios::app);
        oInfo<<numOfTables<<endl;;

        for(int i=0;i<numOfTables;i++)
        {
            oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;

            if(strArr[i].tableName==s3)
            {
                needCol=strArr[i].numCol;
            }
           // cout<<"needcol"<< "   "<<needCol<<endl;
        }

        oInfo.close();

        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        createStringArr(sum);
        if(sum==0)
        {
            createHeaderArray(2);
        }

        else
        {
            createHeaderArray(sum);
        }

        string tableName,s;

        ifstream dFile;
        dFile.open("database.txt", ios::in);

        int idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
            getline(dFile,s);
            getline(dFile,header[i]);
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
        aFile.open("database.txt");

        idx=0;

        for(int i=0;i<numOfTables;i++)
        {
            aFile<<strArr[i].tableName<<endl<<endl;
            aFile<<header[i]<<endl<<endl;

            int individualIndexTable=0;

            while(individualIndexTable!=strArr[i].numOfRows)
            {
                if(strArr[i].tableName==s3 &&  individualIndexTable==rowToUpdate-1)
                {
                    int i1,i2;
                    string c,s7,s9;

                    cin>>c>>s7>>s9;
                    aFile<<s7<<'\t'<<'\t'<<'\t';

                    for(int y=0;y<needCol-1;y++)
                    {
                        cin>>s7>>s9;
                        aFile<<s7<<'\t'<<'\t'<<'\t';
                        //cout<<"s7"<<"  "<<s7<<endl;
                    }

                    aFile<<endl;

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

        aFile.close();
    }

    cout<<endl<<endl<<"Row updated in "<<s3<<" successfully!"<<endl<<endl;
}

void selectInfo()
{
    string checker;
    string from,s3;
    int numOfTables;

    cin>>checker;

    ofstream recordFile;
    recordFile.open("selectRecord.txt", ios :: app);

    if(checker=="*")
    {
        cin>>from>>s3;

        string userName,userID;

        cout<<endl<<"Enter your name : "<<endl;
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

        if(numOfTables==0)
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
                iInfo>>strArr[i].numCol;
            }

            iInfo.close();

            remove("info.txt");

            ofstream oInfo;
            oInfo.open("info.txt", ios::app);
            oInfo<<numOfTables<<endl;;

            for(int i=0;i<numOfTables;i++)
            {
                oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
            }

                oInfo.close();

                int sum=0;

                for(int i=0;i<numOfTables;i++)
                {
                    sum+=strArr[i].numOfRows;
                }

                createStringArr(sum);

                if(sum==0)
                    createHeaderArray(2);
                else
                    createHeaderArray(sum);

                string tableName,s;

                ifstream dFile;
                dFile.open("database.txt", ios::in);

                int idx=0;

                for(int i=0;i<numOfTables;i++)
                {
                    dFile>>tableName;
                    getline(dFile,s);
                    getline(dFile,s);
                    getline(dFile,header[i]);
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
                        cout<<header[i]<<endl<<endl;

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
                    aFile<<header[i]<<endl<<endl;

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].numOfRows)
                    {
                        aFile<<stringArr[idx]<<endl;
                        idx++;
                        individualIndexTable++;
                    }

                    if(i!=numOfTables-1)  aFile<<endl;
                }

                aFile.close();
        }
    }

    else
    {
        string col1,col2;
        string userName,userID;

        col1=checker;
        cin>>col2>>from>>s3;


        cout<<endl<<"Enter your name : "<<endl;
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
                iInfo>>strArr[i].numCol;
            }

            iInfo.close();

            remove("info.txt");

            ofstream oInfo;
            oInfo.open("info.txt", ios::app);
            oInfo<<numOfTables<<endl;;

            for(int i=0;i<numOfTables;i++)
            {
                oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
                if(s3==strArr[i].tableName) numOfCol=strArr[i].numCol;
            }

            oInfo.close();

            int sum=0;

            for(int i=0;i<numOfTables;i++)
            {
                sum+=strArr[i].numOfRows;
            }

            createStringArr(sum);
            if(sum==0)
                createHeaderArray(2);
            else
                createHeaderArray(sum);

            string tableName,s;

            ifstream dFile;
            dFile.open("database.txt", ios::in);

            int idx=0;

            for(int i=0;i<numOfTables;i++)
            {
                dFile>>tableName;
                getline(dFile,s);
                getline(dFile,s);
                getline(dFile,header[i]);
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

                    splitFile<<header[i]<<endl;

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
                aFile<<header[i]<<endl<<endl;

                int individualIndexTable=0;

                while(individualIndexTable!=strArr[i].numOfRows)
                {
                    aFile<<stringArr[idx]<<endl;
                    idx++;
                    individualIndexTable++;
                }

                if(i!=numOfTables-1)
                    aFile<<endl;
            }

            aFile.close();

            ifstream splitFileRead;
            splitFileRead.open("split.txt");

            string colHeader;
            int storeCol1,storeCol2;

            for(int i=0;i<numOfCol;i++)
            {
                splitFileRead>>colHeader;
                if(colHeader==col1)
                {
                    cout<<colHeader<<'\t'<<'\t'<<'\t';
                    storeCol1=i;
                }

                else if(colHeader==col2)
                {
                    cout<<colHeader<<'\t'<<'\t'<<'\t';
                    storeCol2=i;
                }
            }

            cout<<endl;

            string colValue;

            for(int i=0;i<storeNumberOfRows;i++)
            {
                for(int j=0;j<numOfCol;j++)
                {
                    splitFileRead>>colValue;
                    if(j==storeCol1)
                    {
                        cout<<colValue<<'\t'<<'\t'<<'\t';
                    }

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

