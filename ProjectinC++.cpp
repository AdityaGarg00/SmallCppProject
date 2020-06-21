//Header Files
#include<stdio.h>
#include <fstream>

#include<iostream>
#include<conio.h>
#include<string.h>
//Class
using namespace std;
class Student

{


    char sname[20],city[20];
    int age;

    public:
    int rno,cls;
    void insertData()
    {
        cout<<"======ENTER INFORMATION========";
        cout<<"\nEnter Name as String   :-> ";
        cin>>sname;
        cout<<"\nEnter RollNo as integer:-> ";
        cin>>rno;
        cout<<"\nEnter age as integer   :-> ";
        cin>>age;
        cout<<"\nEnter class as integer :-> ";
        cin>>cls;
        cout<<"\nEnter city as String   :-> ";
        cin>>city;
    }

    void printData()
    {
        cout<<"\n"<<sname<<"\t"<<rno<<"\t"<<age<<"\t"<<cls<<"\t"<<city;
    }


    void searchData()
    {
        cout<<"\n====== INFORMATION Of Rollno "<<rno<<"========";
        cout<<"\n Name   :-> "<<sname;
        cout<<"\n RollNo :-> "<<rno;
        cout<<"\n AGE    :-> "<<age;
        cout<<"\n CLASS  :-> "<<cls;
        cout<<"\n CITY   :-> "<<city;
    }
};

//LOGIN
int login()
{
    char password[20];
    cout<<"===Enter PASSWORD =====:->";
    cin>>password;
    if(strcmp(password,"12345")==0)
    return(1);
    else
    return(0);
}
//main
int main()
{
    Student S;
    int ch;
    ifstream F1;
    ofstream F2;
    int x;

    x=login();

    if(x==1)
    {
        do
        {
            cout<<"\n================";
            cout<<"\n Enter 1 To insert Data";
            cout<<"\n Enter 2 To delete Data";
            cout<<"\n Enter 3 To search Data By RollNo";
            cout<<"\n Enter 4 To print Data";
            cout<<"\n Enter 5 To Clear all Data";
            cout<<"\n Enter 6 To search By Class";
            cout<<"\n Enter 0 To Exit";
            cout<<"\n Enter Your Choice:-> \n ";
            cin>>ch;
            cout<<"\n================";
            if(ch==1)                 //write S into FILE
            {
                S.insertData();
                F2.open("abc1.txt",ios::app);
                F2.write((char*)&S,sizeof(S));
                F2.close();
            }
            //else if(ch==2)
            //	S.delData();//Do It your self
            else if(ch==3)
            {
                int R;

                cout<<"\n ==Enter Roll No :-> \n";
                cin>>R;
                F1.open("abc1.txt");
                while(F1.read((char*)&S,sizeof(S)))
                {
                    if(S.rno==R)
                    {
                        S.searchData();
                    }
                }
                F1.close();
            }
            else if(ch==6)
            {
                int C;

                cout<<"\n ==Enter CLASS :-> \n";
                cin>>C;


                F1.open("abc1.txt");
                cout<<"\n====== FULL REPORT========";
                cout<<"\n Name\tRollNo\tAge\tClass\tCity \n";

                while(F1.read((char*)&S,sizeof(S)))
                {
                    if(C==S.cls)
                    {
                        S.printData();
                    }
                }
                F1.close();
                cout<<"\n===============================";
            }

            else if(ch==4)
            {

                F1.open("abc1.txt");
                cout<<"\n====== FULL REPORT========";
                cout<<"\n Name\tRollNo\tAge\tClass\tCity ";

                while(F1.read((char*)&S,sizeof(S)))
                {
                    S.printData();
                }
                F1.close();
                cout<<"\n===============================";
            }

            else if(ch==5)
            {
                F2.open("abc1.txt");
                F2.close();
            }
            else if(ch!=0)
            cout<<"Wrong Choice";
        }
    while(ch!=0);
    cout<<"\n\n=======================================";
    cout<<"\nThanks For Using This Small Application ";
    cout<<"\n=======================================";

    }

    else
    {
        cout<<"\n    * Wrong Password *";
    }

    getch();
}
