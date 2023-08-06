#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
void headMessage();
void regi();
void log();

////////////////////////////////////////////////////

class account
{
private:
    char name[101];
    int number;
    int password;
public:
    void getdata();
    void showdata();
    int retnum();
    int retpass();
};
void account::getdata()
{
    cout<<"Please Enter your Name:"<<endl;
    cin>>name;
    cout<<"please Enter your Number:"<<endl;
    cin>>number;
    cout<<"please Enter your Password (Integer Only):"<<endl;
    cin>>password;
}
void account::showdata()
{
    cout<<"n\t\t\t  Name is:"<<name<<endl;
}

int account::retnum()
{
    return number;
}
int account::retpass()
{
    return password;
}

class student : public account

{
      private:

       int batch,regi_num,roll,season;
       char dep[101];

      public:

        void get()
        {
            account::getdata();
            cout<<"Enter your Batch:"<<endl;cin>>batch;
            cout<<"Enter your Registration Number:"<<endl;cin>>regi_num;
            cout<<"Enter your Roll Number:"<<endl;cin>>roll;
            cout<<"Enter your Season:"<<endl;cin>>season;
            cout<<"Enter your Department Name:"<<endl;cin>>dep;
        }
        void show()
        {   cout<<"\n\n\n\n\n";
            cout<<"\n\t\t\t**-**-**-**-**-**-**-**-**-**-**"<<endl;
            cout<<"\n\t\t\t--------------------------------"<<endl;
            account::showdata();
            cout<<"\n\t\t\t  Batch Name:"<<batch<<endl;
            cout<<"\n\t\t\t  Registration Number:"<<regi_num<<endl;
            cout<<"\n\t\t\t  Roll Number:"<<roll<<endl;
            cout<<"\n\t\t\t  Season:"<<season<<endl;
            cout<<"\n\t\t\t  Department Name:"<<dep<<endl;
            cout<<"\n\t\t\t**-**-**-**-**-**-**-**-**-**-**"<<endl;
            cout<<"\n\t\t\t--------------------------------"<<endl;
        }

        void si()
        {
        student p;
        ifstream l;
        l.open("registration.dat",ios::binary | ios::in);
        while(l.read(reinterpret_cast<char*>(&p),sizeof(student)))
         {
         p.show();
         }
         l.close();
        }
};

///////////////////////////////////////////////////////////////////

class book

{
   private:
       char name[101];
       char writer[101];
       int bookcode;
   public:
       void getbook()
       {
          cout<<"============================="<<endl;

          cout<<"Enter Book Name"<<endl;
          cin>>name;
          cout<<"Enter Writer Name"<<endl;
          cin>>writer;
          cin.ignore();
          cout<<"Enter book code:"<<endl;
          cin>>bookcode;

          cout<<"============================="<<endl;
       }
       void showbook()
       {   cout<<"-----------------------------------"<<endl;
           cout<<"             BOOK ZONE             "<<endl;
           cout<<"-----------------------------------"<<endl;
           cout<<" Book Name is:"<<name<<endl;
           cout<<" Writer Name is:"<<writer<<endl;
           cout<<" Book Code:"<<bookcode<<endl;
           cout<<"-----------------------------------"<<endl;
           cout<<"-----------------------------------"<<endl;
       }
       int retbc()
       {
           return bookcode;
       }
      void  bookfw();
      void  bookfr();
      void sb();
};

void book::bookfw()

{
    book b;
    ofstream of;
    of.open("book.dat",ios::binary | ios::out | ios::app);
    if(!of)
        {
        cout<<"Book File not create...."<<endl;
        }
    b.getbook();
    of.write(reinterpret_cast<char*>(&b),sizeof(book));
    cout<<"Book stroe successfull....."<<endl;
    of.close();
}

void book::bookfr()

{
    book a;
    bool found = false;
    int code;
    cout<<"Input Code :";
    cin>>code;
    ifstream ipf;
    ipf.open("book.dat",ios::binary | ios::in);
    if(!ipf)
        {
        cout<<"Book file not create...."<<endl;
        }
    while(ipf.read(reinterpret_cast<char*>(&a),sizeof(book)))
        {
        if(a.retbc()==code)
            {
            cout<<"Book is available "<<endl;
            a.showbook();
            cout<<endl;
            found = true;
            break;
            }
        }
    if(found==false)
        {
        cout<<"Book not found ..... "<<endl;
        }
}

void book:: sb()

{
    book l;
    ifstream i;
    i.open("book.dat",ios::binary | ios::in);
    while(i.read(reinterpret_cast<char*>(&l),sizeof(book)))
     {
         l.showbook();
     }
    i.close();
}

////////////////////////////////////////////////////////////////////

void regi()
{
    student ac;
    ofstream outFile;
    outFile.open("registration.dat",ios::binary | ios::out | ios::app);
    if(!outFile)
        {
        cout<<"File not create...."<<endl;
        }
    ac.get();
    outFile.write(reinterpret_cast<char*>(&ac),sizeof(student));
    cout<<"Registration successfull"<<endl;
    outFile.close();
}


//////////////////////////////////////////////////////////////////////////////////////////

void log()
{
    student ac;
    bool found = false;
    int phone;
    int pass;
    cout<<"Input Phone :";
    cin>>phone;
    cout<<"Input pass :";
    cin>>pass;
    ifstream inFile;
    inFile.open("registration.dat",ios::binary | ios::in);
    if(!inFile){
        cout<<"File not create...."<<endl;
    }
    while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(student))){
        if(ac.retnum()==phone && ac.retpass()==pass){
            cout<<"Login success "<<endl;
            ac.show();
            cout<<endl;
            found = true;
            break;
        }
    }
    if(found==false){
        cout<<"Account not found ..... "<<endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

void headMessage()
{
    cout<<"\n\n\n\n\n";
    cout<<"\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout<<"\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout<<"\n\t\t\t        =               WELCOME  TO                 =";
    cout<<"\n\t\t\t        =            CENTERAL LIBRARY               =";
    cout<<"\n\t\t\t        =               MANAGEMENT                  =";
    cout<<"\n\t\t\t        =               SYSTEM,JU                   =";
    cout<<"\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout<<"\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout<<"\n\n\n\n\n";
    cout<<"\n\n\n\t\t\t Enter any key to continue.....";
    getch();
}

////////////////////////////////////////////////////////////////////////////////////////////

class liberarian
{
private:
    int pass=1952;
public:
    void introl()
    {
        system("cls");
        cout<<"\n\n\n\n\n";
        cout<<"\n\t\t\t-------------------------------"<<endl;
        cout<<"\n\t\t\t            WELCOME            "<<endl;
        cout<<"\n\t\t\t       ****LIBERARIAN****      "<<endl;
        cout<<"\n\t\t\t-------------------------------"<<endl;
        cout<<"\n\t\t\t Please Choose Any Option"<<endl;
        cout<<"\n\t\t\t 1 to View Booklist"<<endl;
        cout<<"\n\t\t\t 2 to Add Book"<<endl;
        cout<<"\n\t\t\t 3 to Search For a Book"<<endl;
        cout<<"\n\t\t\t 4 to View Student Information"<<endl;
        cout<<"\n\t\t\t 5 to Go to previous Menue"<<endl;
        cout<<"\n\t\t\t-------------------------------"<<endl;
        cout<<"\n\t\t\t-------------------------------"<<endl;
    }
    int retp()
    {
        return pass;
    }
    void lf()
    {
       while(1)
       {
        book c;
        student s;
        int t;
        cout<<"Please Enter your choice:"<<endl;
        cin>>t;
          if(t==1)
          {
              c.sb();
          }
          else if(t==2)
          {
              c.bookfw();
          }
          else if(t==3)
          {
              c.bookfr();
          }
          else if(t==4)
            {
              s.si();
            }
          else
            {
            break;
            }
       }
    }
};

////////////////////////////////////////////////////////////////////////////////

int main()

{
    headMessage();
    liberarian l;
    system("cls");

    while(1)
    {
        cout<<"\n\n\n\n\n";
        cout<<"\n\t\t\t**-**-**-**-**-**-**-**-**-**-**"<<endl;
        cout<<"\n\t\t\t--------------------------------"<<endl;

        cout<<"\n\t\t\t 1 to Register For Student"<<endl;
        cout<<"\n\t\t\t 2 to Student Log In"<<endl;
        cout<<"\n\t\t\t 3 to Librarian Log In"<<endl;
        cout<<"\n\t\t\t 4 to Close the program"<<endl;

        cout<<"\n\t\t\t--------------------------------"<<endl;
        cout<<"\n\t\t\t**-**-**-**-**-**-**-**-**-**-**"<<endl;

        int ch;
        cout<<"Enter your Choice:"<<endl;
        cin>>ch;
        if(ch==1)
        {
            system("cls");
            regi();
        }
        else if(ch==2)
        {
            system("cls");
            log();
        }
        else if(ch==3)
        {
            int pin;
            cout<<"Please Enter your password:";
            cin>>pin;
            if(l.retp()==pin)
            {
                system("cls");
                l.introl();
                l.lf();
            }
        }
        else
        {
           return 0;
        }

    }
}


