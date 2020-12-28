//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HEADER FILE USED IN THE PROGRAM
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// PROTOTYPE OF GLOBAL FUNCTIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void step();
void tstep();
void intro();
void modify();
void Display();
int CountRecord();
void Deletion();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DEFINATION OF CLASSES
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class student
{
9
Long roll;
float pc;
char name[20],pass[20];
int ph,ch,ma;
public:
void take(); //S1
void show(); //S2
void addf(); //S3
void seef(); //S4
void seeall(); //S5
void login(); //S6
int seeroll(); //S7
int seepass(char p[]); //S8
};
class teacher
{
char name[20],pass[20];
long roll;
public:
void take(); //T1
void addf(); //T2
void login(); //T3
int seeroll(); //T4
int seepass(char p[]); //T5
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DEFINATION OF A FUNCTION USED IN CLASS STUDENT
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void student::take() //S1
{
cout<<"\nEnter Student Roll no :";
cin>>roll;
10
cout<<"\nEnter Student Name :";
gets(name);
cout<<"\nEnter Student Password :";
gets(pass);
cout<<"\nEnter Physics marks :";
cin>>ph;
cout<<"\nEnter Chemistry marks :";
cin>>ch;
cout<<"\nEnter Mathematics marks :";
cin>>ma;
pc=((ma+ph+ch)/3);
}
void student::show() //S2
{
clrscr();
cout<<"\n\n\n\t\t\t\tREPORT CARD";
cout<<"\n\n\nStudent Id : "<<roll;
cout<<"\nStudent Name : "<<name;
cout<<"\nStudent Password : "<<pass;
gotoxy(33,13);
cout<<"Marks Obtained";
gotoxy(23,15);
cout<<"Physics Chemistry Maths Percentage";
gotoxy(22,16);
for(int i=1;i<=36;i++)
{
cout<<"-";
}
gotoxy(25,17);
cout<<ph<<"\t "<<ch<<"\t "<<ma<<"\t "<<pc<<"%";
}
void student::addf() //S3
{
student a;
11
fstream b;
b.open("std01.dat",ios::binary|ios::app);
a.take();
b.write((char*)&a,sizeof(a));
b.close();
}
void student::seef() //S4
{
student a;
fstream b;
b.open("std01.dat",ios::binary|ios::in);
while(b.read((char*)&a,sizeof(a)))
{
a.show();
}
b.close();
}
void student::seeall() //S5
{
fstream F;
student a;
F.open("std01.dat",ios::binary|ios::in);
if(!F)
{
cout<<"\n\t Unable to open file";
}
if(F)
{
// Read a record & checks for end of file
cout<<"\n\nRoll no\tName\tPhysics\tChemistry Maths Percentage\n";
for(int i=1;i<=55;i++)
{
cout<<"-";
12
}
while(F.read((char*)&a,sizeof(a)))
{
cout<<endl<<a.roll<<"\t"<<a.name<<"\t"<<a.ph<<"\t"<<a.ch<<"\t"<<" "<<a.ma<<"\t"<<" "<<a.pc;
}
}
F.close();
getch();
}
void student::login() //S6
{
student a;
fstream b;
randomize();
int h,r=(random(1000)+1000);
b.open("std01.dat",ios::binary|ios::in);
int droll,s=0;
char apass[20];
cout<<"\nEnter student roll no :";
cin>>droll;
cout<<"\nEnter student password :";
gets(apass);
cout<<"\n\nSecurity pin is "<<r;
cout<<"\nEnter security pin : ";
cin>>h;
if(h==r)
{
while(b.read((char*)&a,sizeof(a)))
{
if(droll==a.seeroll() && a.seepass(apass)==0)
{
s+=1;
13
a.show();
gotoxy(2,24);
cout<<"Press ENTER to logout";
}
}
if(s==0)
{
cout<<"\nNo record found ";
}
}
if(h!=r)
{ char q;
cout<<"\nSecurity pin is not correct";
cout<<"\nIf you want to continue pres Y else any key :";
cin>>q;
if(q=='Y')
{
a.login();
}
if(q!='Y')
{
step();
}
}
b.close();
}
int student::seeroll() //S7
{
return roll;
}
int student::seepass(char p[]) //S8
{
14
return strcmp(pass,p);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//DEFINATION OF A FUNCTION USED IN CLASS TEACHER
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void teacher::take()
{
cout<<"\nEnter Teacher Id :";
cin>>roll;
cout<<"\nEnter Name :";
gets(name);
cout<<"\nEnter password :";
gets(pass);
}
void teacher::addf()
{
teacher a;
fstream b;
b.open("tec01.dat",ios::binary|ios::app);
a.take();
b.write((char*)&a,sizeof(a));
b.close();
}
int teacher::seeroll()
{
return roll;
}
int teacher::seepass(char p[])
{
return strcmp(pass,p);
}
void teacher::login()
15
{
teacher a;
fstream b;
randomize();
b.open("tec01.dat",ios::binary|ios::in);
int droll;
int s=0;
int h,r=(random(1000)+1000);
char apass[20];
cout<<"\nEnter teacher id : ";
cin>>droll;
cout<<"\nExnter password : ";
gets(apass);
cout<<"\n\nSecurity pin is "<<r;
cout<<"\nEnter security pin : ";
cin>>h;
int x[10];
int z;
z=strcmpi(apass,"123HKS");
if(h==r)
{
if(droll==101 && z==0 )
{
clrscr();
cout<<"\n\nNOTE : You have enterd pre defined teacher id and password";
cout<<"\n\nThe process of adding a new teacher start\n";
a.addf();
s=s+1;
cout<<"\nA new teacher is added to the list";
getch();
step();
}
16
while(b.read((char*)&a,sizeof(a)))
{
if(droll==a.seeroll() && a.seepass(apass)==0)
{
s=s+1;
tstep();
getch();
}
}
if(s==0)
{
cout<<"\nNo teacher found with follwoing details \nPres enter";
getch();
step();
}
b.close();
}
if(h!=r)
{ char q;
cout<<"\nSecurity pin is not correct";
cout<<"\nIf you want to continue pres 'Y' else any key :";
cin>>q;
if(q=='Y')
{
a.login();
}
if(q!='Y')
{
step();
}
}
}
17
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DEFINATION OF A GLOBAL FUNCTIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void modify()
{
clrscr();
fstream F1, F2;
student s1,s2;
int found=0,Ino;
F1.open("std01.dat", ios::binary | ios::in |ios::app);
F2.open("Temp.dat", ios::binary | ios::app);
if(!F1)
{
cout<<"\n\t Unable to open file because file does not exixt";
getch();
}
if(F1)
{
cout<<"\n\tEnter student roll no to modify : ";
cin>>Ino;
while(F1.read((char*)&s1,sizeof(s1)))
{
if(s1.seeroll()==Ino)
{
if(found==0)
{
cout<<"\nPlease Enter The New Details of student"<<endl;
s2.addf();
found+=1;
}
}
if(s1.seeroll()!=Ino)
18
{
F2.write((char*)&s1,sizeof(s1));
}
}
F1.close();
F2.close();
remove("std01.dat");
rename("Temp.dat","std01.dat");
if(found==0)
cout<<"\n\t Record Not found";
else
cout<<"\n\t Record Updated";
}
}
int CountRecord()
{
fstream F;
student s1;
int count=0;
F.open("std01.dat", ios::binary | ios::in);
if(!F)
{
cout<<"\n\t Unable to open file";
getch();
return 0;
}
else
{
// Read a record & checks for end of file
while(F.read((char*) &s1, sizeof(s1)))
{
count++;
}
F.close();
19
return count;
}
}
void Deletion(int Ino)
{
fstream F1, F2;
student s1, Snew;
int Delete=0;
F1.open("std01.dat", ios::binary | ios::in |ios::app);
if(!F1)
{
cout<<"\n\t Unable to open file because file does not exixt";
getch();
}
F2.open("Temp.Dat", ios::binary | ios::app | ios::in);
// User input Item No. to be deleted
if(F1){
while(F1.read((char*) &s1, sizeof(s1)))
// Read a record & checks for end of file
{
if(s1.seeroll()!= Ino)
{
F2.write((char*) &s1, sizeof(s1));
}
else
{
Delete++;
}
}
F1.close();
F2.close();
remove("std01.dat");
rename("Temp.Dat","std01.dat");
if(Delete==0)
20
cout<<"\n\t Record Not found";
else
cout<<"\n\t Record deleted";
}
}
void intro()
{
clrscr();
gotoxy(31,4);
cout<<"DELHI PUBLIC SCHOOL";
gotoxy(30,5);
cout<<"---------------------";
gotoxy(36,7);
cout<<"JABALPUR";
gotoxy(35,8);
cout<<"----------";
gotoxy(32,10);
cout<<"CLASS XII PROJECT";
gotoxy(31,11);
cout<<"-------------------";
gotoxy(18,13);
cout<<"TOPICE :- SCHOOL CUM CLASS MANAGMENT PROGRAM";
gotoxy(17,14);
cout<<"----------------------------------------------";
gotoxy(1,20);
cout<<"SUBMITTED BY : HITESH KUMAR";
cout<<"\n\nSUBMITTED TO : Mr. SANJAY MUKERJEE";
getch();
}
void tstep()
{ clrscr();
gotoxy(34,2);
cout<<"TEACHER MENU";
21
gotoxy(33,3);
cout<<"--------------";
cout<<"\n\n1.Add new student data\n2.Delete student data";
cout<<"\n3.Modify student data\n4.See all student data";
cout<<"\n5.Count number of student\n6.Logout";
int a;
student s;
teacher t;
cout<<"\n\nEnter your choice :";
cin>>a;
if(a==1)
{
clrscr();
gotoxy(30,2);
cout<<"Adding a new student";
gotoxy(33,4);
cout<<"Student details\n";
s.addf();
getch();
tstep();
}
if(a==2)
{
int Ino;
cout<<"\n\tEnter student roll no : ";
cin>>Ino;
Deletion(Ino);
getch();
tstep();
}if(a==3)
{
modify();
getch();
tstep();
22
}if(a==4)
{
s.seeall();
tstep();
}if(a==5)
{
cout<<"\n\nNo of student is/are "<<CountRecord();
getch();
tstep();
}if(a==6)
{
step();
}else
{
exit(1);
}
}
void step()
{
clrscr();
gotoxy(32,4);
cout<<"ABC PUBLIC SCHOOL";
gotoxy(31,5);
cout<<"-------------------";
gotoxy(34,7);
cout<<"Login Portal\n\n\n1.Login as Teacher\n2.Login as Student\n3.Close";
int a;
student s;
teacher t;
cout<<"\n\nEnter your choice : ";
cin>>a;
if(a==1)
{
23
clrscr();
gotoxy(25,2);
cout<<"LOGIN PORTAL FOR TEACHERS\n";
t.login();
getch();
step();
}
if(a==2)
{
clrscr();
gotoxy(25,2);
cout<<"LOGIN PORTAL FOR STUDENTS\n";
s.login();
getch();
}
if(a==3)
{
clrscr();
gotoxy(30,3);
cout<<"THANKS FOR YOUR TIME";
gotoxy(27,9);
cout<<"PREPARED BY : HITESH KUMAR";
getch();
exit(1);
}
else
{
getch();
clrscr();
step();
}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
24
// THE VOID MAIN FUNCTION OF PROGRAM
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main()
{
clrscr();
intro();
step();
}

