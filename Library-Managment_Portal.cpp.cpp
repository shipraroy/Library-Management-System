#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include <sstream>
#include<conio.h>
using namespace std;

class library
{
    public:
    string bookname,auname,sc,sc1;
    int q,B,p,S;
    library()
    {
        bookname="NO Book Name";
        auname="No Author Name";
        sc="No Publisher Name";
        sc1="No Book ID";
        q=0;S=0;B=0;p=0;
    }
    virtual void student(){}
    virtual void librarian(){}
    virtual void pass(){}
    void see(int);
    int sem(int);
    void show(int);
    void booklist(int);
    int branch(int);
    void get();
    void getdata();


};
class student1:public library
{
  public:
      void student()
    {
    int i;
    library *l;
    student1 s;
    cout<<"\n\t** WELCOME STUDENT **\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
        booklist(1);
    else if(i==2)
        see(1);
    else if(i==3)
    {
        system("cls");
        get();
    }
    else if(i==4)
        exit(0);
    else
    {
        cout<<"\n\t\tPlease enter correct option :(";
        getch();
        system("cls");
        l=&s;
        l->student();
    }
    }

};
class librarian1:public library
{
public:
    void pass()
   {

    library *l;
    librarian1 li;
    int i=0;
    char ch;
    char st[21];
    string ch1,ch2;
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
        ch=_getch();
        if(ch==13)
        {
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            
            cout<<"*";
            st[i]=ch;
            i++;
        }
    }
    fstream file ;
    file.open("temp_pass.txt",ios::out);
    file<<st;
    file.close();
    fstream o_file ;
    o_file.open("password.txt",ios::in);
    file.open("temp_pass.txt",ios::in);
    getline (file,ch1);
    getline(o_file,ch2);
    if(ch1.compare(ch2)==0)
    {
        system("cls");
        l=&li;
        l->librarian();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        get();
    }
}
void librarian()
{
    int i;
    library *l;
    student1 s;
    librarian1 li;
    cout<<"\n\t** WELCOME LIBRARIAN **\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Change Password\n\n\t\t7.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
    switch(i)
    {
    case 1:
        booklist(2);
        break;
    case 2:
        see(2);
        break;
    case 3:
        modify();
        break;
    case 4:
        issue();
        break;
    case 5:
        system("cls");
        get();
        break;
    case 6:
        password();
        break;
    case 7:
        exit(0);
    default:
        cout<<"\n\t\tPlease enter correct option :(";
        getch();
        system("cls");
        l=&li;
        l->librarian();
    }
}
void password()
{
    library *l;
    student1 s;
    librarian1 li;
    int i=0,j=0;
    char ch;
    char st[21];
    string ch1,ch2;
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
        ch=_getch();
        if(ch==13)
        {
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            cout<<"*";
            st[i]=ch;
            i++;
        }
    }
    fstream file ;
    file.open("temp_pass.txt",ios::out);
    file<<st;
    file.close();
    fstream o_file ;
    o_file.open("password.txt",ios::in);
    file.open("temp_pass.txt",ios::in);
    getline (file,ch1);
    getline(o_file,ch2);
    file.close ();
    o_file.close();
    if(ch1.compare(ch2)==0)
    {
        system("cls");
        char gst[21];
        cout<<"\n\t*The Password Should be less than 20 characters & don't use spaces*\n\n";
        cout<<"\n\t\tEnter New Password : ";
        i=0;
        while(1)
        {
            ch=_getch();
            if(ch==13)
            {
                gst[i]='\0';
                break;
            }
            else if(ch==8&&i>0)
            {
                i--;
                cout<<"\b \b";
            }
            else
            {
                cout<<"*";
                gst[i]=ch;
                i++;
            }
        }
        ofstream gg;
        gg.open("password.txt",ios::trunc);
        gg<<gst;
        gg.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        l=&li;
        l->librarian();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\tEnter 1 for retry or 2 for menu";
        cin>>i;
        if(i==1)
        {
            system("cls");
            password();
        }
        else
        {
            system("cls");
            l=&li;
            l->librarian();
        }
    }
}
void modify()
{
    library *l;
    student1 s;
    librarian1 li;
    char ch,st1[100];
    int i=0,b,s1,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
        system("cls");
        b=branch(2);
        system("cls");
        s1=sem(2);
        system("cls");
        fstream intf("Booksdata.txt");
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found\n";
            cout<<"\n\t\tPress any key to continue.....";
            getch();
            intf.close();
            system("cls");
            l=&li;
            l->librarian();
        }
        system("cls");
        string ch;
        fflush(stdin);
        cout<<"\n\t\tEnter Book's ID : ";
        getline(cin,ch);
        system("cls");
        string help;
        string arr[8];
        int k=0;
        string d;
        int r=0,l,c;
        int u,z,v,n;
        while (getline(intf,help))
        {
            bookname="";
            auname="";
            sc1="";
            sc="";
            p=0;
            q=0;
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d=d+ch;
                else
                {
                    arr[k]=d;
                    d="";
                    k++;
                }
            }
            bookname=arr[2];
            auname=arr[3];
            sc1=arr[4];
            sc=arr[5];
            stringstream ge(arr[6]);
            ge>>v;
            stringstream j(arr[7]);
            j>>n;
            p=v;
            q=n;
            stringstream geek(arr[0]);
            geek>>u;
            stringstream gee(arr[1]);
            gee>>z;
            ofstream outf("NewModify.txt",ios::app);
            if(b==u&&s1==z)
            {
                if(ch.compare(arr[5])==0)
                {
                    p=0;
                    q=0;
                    cout<<"\n\t\tEnter the Price : \n";
                    cin>>p;
                    cout<<"\n\t\tEnter the Quantity: \n";
                    cin>>q;
                    cont++;
                }
            }
            outf<<u<<" "<<z<<" "<<bookname<<" "<<auname<<" "<<sc1<<" "<<sc<<" "<<p<<" "<<q<<" "<<"\n";
            outf.close();
        }
        ofstream f ("Booksdata.txt",ios::trunc);
        ifstream f1 ("NewModify.txt");
        ofstream f2;
        string h1;
        while(getline(f1,h1))
        {
            f<<h1<<"\n";
        }
        f.close();
        f1.close();
        f2.open("NewModify.txt",ios::trunc);
        f2.close();
        if(cont==0)
        {
            cout<<"\n\t\tBook Not Found.\n";
            cout<<"\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
        }
        else
            cout<<"\n\t\tUpdate Successful.\n";
    }
    else if(i==2)
    {
        system("cls");
        B=branch(2);
        system("cls");
        S=sem(2);
        system("cls");
        getdata();
        ofstream outf("Booksdata.txt",ios::app);
        outf<<B<<" "<<S<<" "<<bookname<<" "<<auname<<" "<<sc1<<" "<<sc<<" "<<p<<" "<<q<<" "<<"\n";
        outf.close();
        cout<<"\n\t\tBook added Successfully.\n";
    }
    else if(i==3)
    {
        system("cls");
        b=branch(2);
        system("cls");
        s1=sem(2);
        system("cls");
        ifstream intf("Booksdata.txt");
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found\n";
            cout<<"\n\t\tPress any key to continue.....";
            getch();
            intf.close();
            system("cls");
            l=&li;
            l->librarian();
        }
        system("cls");
        string ch;
        fflush(stdin);
        cout<<"\n\t\tEnter Book's ID : ";
        getline(cin,ch);
        system("cls");
        string help;
        string arr[8];
        int k=0;
        string d;
        int r=0,l,c;
        int u,z,v,n;
        while (getline(intf,help))
        {
            bookname="";
            auname="";
            sc1="";
            sc="";
            p=0;
            q=0;
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d=d+ch;
                else
                {
                    arr[k]=d;
                    d="";
                    k++;
                }
            }
            stringstream geek(arr[0]);
            geek>>u;
            stringstream gee(arr[1]);
            gee>>z;
            bookname=arr[2];
            auname=arr[3];
            sc1=arr[4];
            sc=arr[5];
            stringstream ge(arr[6]);
            ge>>v;
            stringstream j(arr[7]);
            j>>n;
            p=v;
            q=n;
            ofstream outf("NewBooksdata.txt",ios::app);
            if (b==u&&s1==z)
            {
                if(ch.compare(sc)!=0)
                {
                    outf<<u<<" "<<z<<" "<<bookname<<" "<<auname<<" "<<sc1<<" "<<sc<<" "<<p<<" "<<q<<" "<<"\n";
                }
                cont++;
            }
            else
            {
                outf<<u<<" "<<z<<" "<<bookname<<" "<<auname<<" "<<sc1<<" "<<sc<<" "<<p<<" "<<q<<" "<<"\n";
            }
        }
        //outf.close();
        ofstream f ("Booksdata.txt",ios::trunc);
        ifstream f1 ("NewBooksdata.txt");
        ofstream f2;
        string h1;
        while(getline(f1,h1))
        {
            f<<h1<<"\n";
        }
        f.close();
        f1.close();
        f2.open("NewBooksdata.txt",ios::trunc);
        f2.close();
        if(cont==0)
        {
            cout<<"\n\t\tBook Not Found.\n";
            cout<<"\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
        }
        else
            cout<<"\n\t\tDeletion Successful.\n";
    }
    else if(i==4)
    {
        system("cls");
        l=&li;
        l->librarian();
    }
    else
    {
        cout<<"\n\t\tWrong Input.\n";
        cout<<"\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    l=&li;
    l->librarian();
}
void issue()
{
    library *l;
    student1 s;
    librarian1 li;
    char st[50],st1[20];
    string stuname,stuid,book,bkid;
    int b,i,s1,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who isuued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
        system("cls");
        b=branch(2);
        system("cls");
        s1=sem(2);
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\t\tEnter Book Name : ";
        getline(cin,book);
        cout<<"\n\t\tEnter Book's ID : ";
        getline(cin,bkid);
        der(bkid,s1,b,1);
        cout<<"\n\t\tEnter Student Name : ";
        getline(cin,stuname);
        cout<<"\n\t\tEnter Student's ID : ";
        getline(cin,stuid);
        cout<<"\n\t\tEnter date : ";
        cin>>d;
        cout<<"\n\t\tEnter month(1-12):";
        cin>>m;
        cout<<"\n\t\tEnter year : ";
        cin>>y;

        ofstream outf("student.txt",ios::app);
        outf<<book<<" "<<bkid<<" "<<stuname<<" "<<stuid<<" "<<d<<"/"<<m<<"/"<<y<<" "<<"\n";
        outf.close();
        cout<<"\n\n\t\tIssue Successfully for 15 days.\n";
    }
    else if(i==2)
    {
        system("cls");
        cout<<"\n\t\t->The Details are :-\n";
        ifstream intf("student.txt");
    if(!intf)
        cout<<"\n\t\tFile Not Found.";
    else
    {
        string help;
        string arr[5];
        int k=0;
        string d,date;

        int r=0;
        while (getline(intf,help))
        {
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d=d+ch;
                else
                {
                    arr[k]=d;
                    d="";
                    k++;
                }
            }
                r++;
                cout<<"\n\t\t** "<<r<<". ** \n";
                book=arr[0];
                bkid=arr[1];
                stuname=arr[2];
                stuid=arr[3];
                date=arr[4];
                 cout<<"\n\t\tStudent Name : "<<stuname;
                 cout<<"\n\n\t\t"<<"Student's ID : "<<stuid;
                 cout<<"\n\n\t\t"<<"Book Name : "<<book;
                 cout<<"\n\n\t\t"<<"Book's ID : "<<bkid;
                 cout<<"\n\n\t\t"<<"Date : "<<date<<"\n";
        }
    }
    intf.close();

    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        string s1,s2;
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        getline(cin,s1);
        cout<<"\n\n\t\tEnter Student's ID : ";
        getline(cin,s2);
        system("cls");
        cout<<"\n\t\t->The Details are :-\n";
        cout<<"\n\n\t\tStudent Name : "<<s1;
        cout<<"\n\n\t\tStudent's ID : "<<s2;
        cout<<"\n\n\t\tIssued books  are :-\n";
        ifstream intf("student.txt");
    if(!intf)
        cout<<"\n\t\tFile Not Found.";
    else
    {
        string help;
        string arr[5];
        int k=0;
        string d,date;

        int r=0;
        while (getline(intf,help))
        {
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d=d+ch;
                else
                {
                    arr[k]=d;
                    d="";
                    k++;
                }
            }
                book=arr[0];
                bkid=arr[1];
                stuname=arr[2];
                stuid=arr[3];
                date=arr[4];
                if(s2.compare(stuid)==0)
                {
                    r++;
                    cont++;
                    cout<<"\n\t\t** "<<r<<". ** \n";
                    cout<<"\n\n\t\t"<<"Book Name : "<<book;
                    cout<<"\n\n\t\t"<<"Book's ID : "<<bkid;
                    cout<<"\n\n\t\t"<<"Date : "<<date<<"\n";
                }

        }
    }
    intf.close();

        if(cont==0)
            cout<<"\n\t\tNo record found.";
    }
    else if(i==4)
    {
        string st,st2;
        system("cls");
         b=branch(2);
        system("cls");
        s1=sem(2);
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\t\tEnter Book's ID : ";
        getline(cin,st);
        der(st,s1,b,2);
        cout<<"\n\n\t\tEnter Student's ID : ";
        getline(cin,st2);
        ifstream intf("student.txt");
         if(!intf)
        cout<<"\n\t\tFile Not Found.";
    else
    {
        string help;
        string arr[5];
        int cnt=0;
        int k=0;
        string d1,date;
         int dd,mm,yy;
        int r=0;
        while (getline(intf,help))
        {
            k=0;

            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d1=d1+ch;
                else
                {
                    arr[k]=d1;
                    d1="";
                    k++;
                }

            }
             book=arr[0];
             bkid=arr[1];
             stuname=arr[2];
             stuid=arr[3];
             date=arr[4];
             fstream f1("Newmodified.txt",ios::app);
             if(st.compare(bkid)==0&&st2.compare(stuid)==0)
             {

               cout<<"\n\t\tEnter new date : ";
               cin>>dd;
               cout<<"\n\t\tEnter new month(1-12):";
               cin>>mm;
               cout<<"\n\t\tEnter new year : ";
               cin>>yy;
               f1<<book<<" "<<bkid<<" "<<stuname<<" "<<stuid<<" "<<dd<<"/"<<mm<<"/"<<yy<<" "<<"\n";
               cnt++;
             }
             else
             {
                 f1<<book<<" "<<bkid<<" "<<stuname<<" "<<stuid<<" "<<date<<" "<<"\n";
             }
        }
        ofstream f ("student.txt",ios::trunc);
        ifstream f1 ("Newmodified.txt");
        ofstream f2;
        string h1;
        while(getline(f1,h1))
        {
            f<<h1<<"\n";
        }
        f.close();
        f1.close();
        f2.open("Newmodified.txt",ios::trunc);
        f2.close();
        if(cnt!=0)
        {
            cout<<"\n\t\tReissued Successfully for next 15 days!!";
        }
    }
    }
    else if(i==5)
    {
        string st,st2;
        system("cls");
         b=branch(2);
        system("cls");
        s1=sem(2);
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\t\tEnter Book's ID : ";
        getline(cin,st);
        der(st,s1,b,2);
        cout<<"\n\n\t\tEnter Student's ID : ";
        getline(cin,st2);
        cout<<"\n\t\tEnter present date : ";
        cin>>d;
        cout<<"\n\t\tEnter present month(1-12):";
        cin>>m;
        cout<<"\n\t\tEnter present year : ";
        cin>>y;
        ifstream intf("student.txt");
         if(!intf)
        cout<<"\n\t\tFile Not Found.";
    else
    {
        string help;
        string arr[5];
        int cnt=0;
        int k=0;
        string d1,date;
         int dd,mm,yy;
        int r=0;
        while (getline(intf,help))
        {
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d1=d1+ch;
                else
                {
                    arr[k]=d1;
                    d1="";
                    k++;
                }

            }
             book=arr[0];
             bkid=arr[1];
             stuname=arr[2];
             stuid=arr[3];
             date=arr[4];
             ofstream f1("Newstudent.txt",ios::app);
             if(st2.compare(stuid)!=0||st.compare(bkid)!=0)
             {
                 f1<<book<<" "<<bkid<<" "<<stuname<<" "<<stuid<<" "<<date<<" "<<"\n";
             }
             else
             {
                 cnt++;
                 string d1,m2,y3;
                 int dd,mm,yy;
                 d1=date.substr(0,2);
                 m2=date.substr(3,2);
                 y3=date.substr(6,4);
                 if(m2[0]=='0')
                    m2=m2[1];
                 if(d1[0]=='0')
                    d1=d1[1];

                 stringstream g1(d1);
                 g1>>dd;
                 stringstream g2(m2);
                 g2>>mm;
                 stringstream g3(y3);
                 g3>>yy;
                 cout<<dd<<mm<<yy;
                fine(dd,mm,yy,d,m,y);
                cout<<"\n\n\t\tReturned Successfuly !!\n";
             }

         }
        ofstream f ("student.txt",ios::trunc);
        ifstream f1 ("Newstudent.txt");
        ofstream f2;
        string h1;
        while(getline(f1,h1))
        {
            f<<h1<<"\n";
        }
        f.close();
        f1.close();
        f2.open("Newstudent.txt",ios::trunc);
        f2.close();

     }
    }
    else if(i==6)
    {
        system("cls");
        l=&li;
        l->librarian();
    }
    else
        cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    l=&li;
    l->librarian();
}
void fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
        years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
        years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
        cout<<"\n\t\tThe Total Fine is Rs.10 per day: "<<n2*10;
    else
        cout<<"\n\t\tReturned on time :) !!\n";
}
void der(string st,int s1,int b,int x)
{
    int i,cnt=0;
    fstream intf("Booksdata.txt");
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found\n";
            cout<<"\n\t\tPress any key to continue.....";
            getch();
            intf.close();
            system("cls");
            librarian();
        }

        string help;
        string arr[8];
        int k=0;
        string d;
        int r=0,l,c;
        int u,z,v,n;
        while (getline(intf,help))
        {
            bookname="";
            auname="";
            sc1="";
            sc="";
            p=0;
            q=0;
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d=d+ch;
                else
                {
                    arr[k]=d;
                    d="";
                    k++;
                }
            }
            bookname=arr[2];
            auname=arr[3];
            sc1=arr[4];
            sc=arr[5];
            stringstream ge(arr[6]);
            ge>>v;
            stringstream j(arr[7]);
            j>>n;
            p=v;
            q=n;
            stringstream geek(arr[0]);
            geek>>u;
            stringstream gee(arr[1]);
            gee>>z;
            if(b==u&&s1==z)
            {
                if(st.compare(sc)==0){
                if(x==1){
                   q--;
                }
                else
                {
                    q++;
                }
                cnt++;
                }
                ofstream outf("NewBooksdata1.txt",ios::app);
      outf<<u<<" "<<z<<" "<<bookname<<" "<<auname<<" "<<sc1<<" "<<sc<<" "<<p<<" "<<q<<" "<<"\n";
            }

        }
      ofstream f ("Booksdata.txt",ios::trunc);
        ifstream f1 ("NewBooksdata1.txt");
        ofstream f2;
        string h1;
        while(getline(f1,h1))
        {
            f<<h1<<"\n";
        }
        f.close();
        f1.close();
        f2.open("NewBooksdata1.txt",ios::trunc);
        f2.close();
    if(cnt==0)
    {
        cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
};
void library::getdata()
{
    int i;
    fflush(stdin);
    cout<<"\n\t\tEnter the details :-\n";
    cout<<"\n\t\tEnter Book's Name : ";
    getline(cin,bookname);
    for(i=0; bookname[i]!='\0'; i++)
    {
        if(bookname[i]>='a'&&bookname[i]<='z')
            bookname[i]-=32;
    }
    cout<<"\n\t\tEnter Author's Name : ";
    getline(cin,auname);
    cout<<"\n\t\tEnter Publication name : ";
    getline(cin,sc1);
    cout<<"\n\t\tEnter Book's ID : ";
    getline(cin,sc);
    cout<<"\n\t\tEnter Book's Price : ";
    cin>>p;
    cout<<"\n\t\tEnter Book's Quantity : ";
    cin>>q;
}

void library::get()
    {
    int i;
    library *l;
    student1 s;
    librarian1 li;
    cout<<"\n\t\t\t\t\t** LIBRARY MANAGEMENT SYSTEM **\n"<<"\n\t\t\t\t\t\tC++ Project\n\n\t\t\t\t     Made by Priyanshi Gupta & Satyam Mishra\n\n";
    cout<<"\n\t\t>>Please Choose Any Option To login \n";
    cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
        system("cls");
        l=&s;
        l->student();
    }
    else if(i==2)
    {
        system("cls");
        l=&li;
        l->pass();
    }
    else if(i==3)
        exit(0);
    else
    {
        cout<<"\n\t\tPlease enter correct option :(";
        getch();
        system("cls");
        get();
    }
   }
void library::see(int x)
{
    int b,s1,cont=0;
    string ch;
    library *l;
    student1 s;
    librarian1 li;
    system("cls");
    b=branch(x);
    system("cls");
    s1=sem(x);
    system("cls");
    ifstream intf("Booksdata.txt");
    if(!intf)
    {
        cout<<"\n\t\tFile Not Found.\n";
        cout<<"\n\t\t->Press any key to continue.....";
        getch();
        system("cls");
        if(x==1){
            l=&s;
            l->student();
        }
        else{
                l=&li;
            l->librarian();
        }
    }
    system("cls");
    fflush(stdin);
    cout<<"\n\t\tEnter Book's ID : ";
    getline(cin,ch);
    system("cls");
    string help;
    string arr[8];
    int k=0;
    string d;
    int r=0;
    int u,z,v,n;
    while (getline(intf,help))
    {
         bookname="";
            auname="";
            sc1="";
            sc="";
            p=0;
            q=0;
            k=0;
        for (int i=0; i<help.length(); i++)
        {
            char ch=help[i];
            if(ch!=' ')
                d=d+ch;
            else
            {
                arr[k]=d;
                d="";
                k++;
            }
        }

        stringstream geek(arr[0]);
        geek>>u;
        stringstream gee(arr[1]);
        gee>>z;
        r=0;
        if (b==u&&s1==z)
        {
            r++;
            bookname=arr[2];
            auname=arr[3];
            sc1=arr[4];
            sc=arr[5];
            stringstream ge(arr[6]);
            ge>>v;
            stringstream j(arr[7]);
            j>>n;
            p=v;
            q=n;
        }

        if(r==1&&(ch.compare(sc)==0))
        {

            cont++;
            show(x);
            r=0;
            break;
        }
    }
    if(cont==0)
    {
        cout<<"\n\t\tThis Book is not available :( \n";
    }
    intf.close();
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
     if(x==1){
            l=&s;
            l->student();
        }
        else{
                l=&li;
            l->librarian();
        }
}
void library::booklist(int i)
{
    int b,s1,r=0;
    library *l;
    student1 s;
    librarian1 li;
    system("cls");
    b=branch(i);
    system("cls");
    s1=sem(i);
    system("cls");
    ifstream intf("Booksdata.txt");
    if(!intf)
        cout<<"\n\t\tFile Not Found.";
    else
    {
        string help;
        string arr[8];
        int k=0;
        string d;
        int r=0;
        int u,z,v,n;
        cout<<"\n\t    * Book List * \n\n";
        while (getline(intf,help))
        {
            k=0;
            for (int i=0; i<help.length(); i++)
            {
                char ch=help[i];
                if(ch!=' ')
                    d=d+ch;
                else
                {
                    arr[k]=d;
                    d="";
                    k++;
                }
            }
            stringstream geek(arr[0]);
            geek>>u;
            stringstream gee(arr[1]);
            gee>>z;
            if (b==u&&s1==z)
            {
                r++;
                cout<<"\n\t\t** "<<r<<". ** \n";
                bookname=arr[2];
                auname=arr[3];
                sc1=arr[4];
                sc=arr[5];
                stringstream ge(arr[6]);
                ge>>v;
                stringstream j(arr[7]);
                j>>n;
                p=v;
                q=n;
                show(i);
            }
        }
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(i==1){
            l=&s;
        l->student();

    }else{
        l=&li;
        l->librarian();
    }
}
void library::show(int i)
{
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<auname<<endl;
    cout<<"\n\t\tBook's ID : "<<sc<<endl;
    cout<<"\n\t\tBook's Publication : "<<sc1<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<p<<endl;
        cout<<"\n\t\tBook's Quantity : "<<q<<endl;
    }
}
int library::branch(int x)
{
    int i;
     library *l;
    student1 s;
    librarian1 li;
    cout<<"\n\t\t>>Please Choose one Branch :-\n";
    cout<<"\n\t\t1.Computer science Engineering\n\n\t\t2.Electronic Communication Engineering\n\n\t\t3.Go to menu\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
    switch(i)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        system("cls");
        if(x==1){
                l=&s;
            student();
        }
        else{
                l=&li;
            l->librarian();
        }
        break;
    default :
        cout<<"\n\t\tPlease enter correct option :(";
        getch();
        system("cls");
        branch(x);
    }
}

int library::sem(int x)
{
    int i;
     library *l;
    student1 s;
    librarian1 li;
    cout<<"\n\t\tPlease choose the Semester\n\n\n";
    cout<<"\t\t1.1st Semester \n\n\t\t2.2nd Semester\n\n\t\t3.3rd Semester\n\n\t\t4.4th Semester\n\n";
    cout<<"\t\t5.5th Semester\n\n\t\t6.6th semester\n\n\t\t7.7th Semester\n\n\t\t8.8th Semester\n\n\t\t9.Go back\n\n\t\t10.Go to main menu \n\n";
    cout<<"\n\t Enter the choice :";
    cin>>i;
    switch(i)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 4;
        break;
    case 5:
        return 5;
        break;
    case 6:
        return 6;
        break;
    case 7:
        return 7;
        break;
    case 8:
        return 8;
        break;
    case 9:
        system("cls");
        l=&li;
        l->librarian();
        break;
    case 10:
        system("cls");
        get();
        break;
    default:
        cout<<"\n\t\tPlease enter the correct option:\n";
        getch();
        system("cls");
        if(x==1)
        {
            l=&s;
            l->student();
        }
        else if(x==2);
        {
            l=&li;
            l->librarian();
        }
    }
}


int main()
{

    library obj;
    obj.get();
    getch();
    return 0;
}
