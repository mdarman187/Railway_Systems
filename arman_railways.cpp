#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<fstream.h>

char f[10]="f";
char s[10]="s";
int pos,ad,flag,f1,d,m,i,amt;
float tamt;

class login
{
public:
char id[100];
char pass[100];
char *password;

void getid()
{
cout<<"Enter your id:";gets(id);
password=getpass("Enter the password:");
strcpy(pass,password);
}

void displayid()
{
cout<<"Id:";puts(id);
cout<<"Password:";puts(pass);
}

};

class detail
{
public:
int tno;
char tname[100];
char bp[100];
char dp[100];
int c1,c1fare;
int c2,c2fare;
int d,m,y;

void getdetail()
{
cout<<"Enter the details as follows\n";
cout<<"Train no:";cin>>tno;
cout<<"Train name:";gets(tname);
cout<<"Boarding point:";gets(bp);
cout<<"Destination pt:";gets(dp);
cout<<"No of seats in first class & fare per ticket:";
cin>>c1>>c1fare;
cout<<"No of seats in second class & fare per ticket:";
cin>>c2>>c2fare;
cout<<"Date of travel:";cin>>d>>m>>y;
}

void showdetail()
{
cout<<tno<<"\t"<<tname<<"\t"<<bp<<"\t"<<dp<<"\t";
cout<<c1<<"\t"<<c1fare<<"\t"<<c2<<"\t"<<c2fare<<"\t";
cout<<d<<"-"<<m<<"-"<<y<<"\t"<<endl;
}

};

class reserve
{
public:
int pnr;
int tno;
char tname[100];
char bp[10];
char dp[100];
char pname[10][100];
int age[20];
char clas[10];
int nosr;
int i;
int d,m,y;
float amc;

void reservedetail();

void showreservedetail();
};

void reserve::reservedetail()
{
cout<<"Enter the details as follows\n";
cout<<"Train no:";cin>>tno;
cout<<"Train name:";gets(tname);
cout<<"Boarding point:";gets(bp);
cout<<"De rstination pt:";gets(dp);
cout<<"No of seats required:";cin>>nosr;
for(i=0;i<nosr ;i++)
{
cout<<"Passenger name:";gets(pname[i]);
cout<<"Passenger age:";cin>>age[i];
}
cout<<"Enter the class f-first class s-second class:";
gets(clas);
cout<<"Date of travel:";cin>>d>>m>>y;
cout<<"............END OF GETTING DETAILS............\n";
}

void reserve::showreservedetail()
{
cout<<"...............................................\n";
cout<<"...............................................\n";
cout<<"Pnr no:"<<pnr;
cout<<"\nTrain no:"<<tno;
cout<<"\nTrain name:";puts(tname);
cout<<"Boarding point:";puts(bp);
cout<<"Destination pt:";puts(dp);
cout<<"No of seats reserved:"<<nosr;
for(i=0;i<nosr;i++)
{
cout<<"Passenger name:";puts(pname[i]);
cout<<"Passenger age:"<<age[i];
}
cout<<"\nYour class:";puts(clas);
cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
cout<<"\nYou must pay:"<<amc<<endl;
cout<<"***********************************************\n";
cout<<".........END OF RESERVATION.................\n";
cout<<"***********************************************\n";
}

class cancel
{
public:
int p;
int tno;
char tname[100];
char bp[10];
char dp[100];
char pname[10][100];
int age[20];
int i;
char clas[10];
int nosc;
int d,m,y;
float amr;

void canceldetail();
void showcanceldetail();

};

void cancel::canceldetail()
{
cout<<"Enter the details as follows\n";
cout<<"Pnr no:";cin>>p;
cout<<"Date of cancellation:";cin>>d>>m>>y;
cout<<"...........END OF GETTING DETAILS...........\n";
}

void cancel::showcanceldetail()
{
cout<<"...........................................\n";
cout<<"...........................................\n";
cout<<"Pnr no:"<<p;
cout<<"\nTrain no:"<<tno;
cout<<"\nTrain name:";puts(tname);
cout<<"Boarding point:";puts(bp);
cout<<"Destination pt:";puts(dp);
cout<<"\nYour class:";puts(clas);cout<<endl;
cout<<"no of seats to be cancelled:"<<nosc;cout<<endl;
for(i=0;i<nosc;i++)
{
cout<<"Passenger name:";puts(pname[i]);
cout<<"passenger age:"<<age[i];
}
cout<<"\nDate of cancellation:"<<d<<"-"<<m<<"-"<<y;cout<<endl;
cout<<"\nYou can collect:"<<" Rs "<<amr<<endl;
cout<<"*****************************************\n";
cout<<".........END OF CANCELLATION.............\n";
cout<<"*****************************************\n";
}

void manage();
void can();
void user();
void database();
void res();
void reserve1();
void displaypassdetail();
void cancel1();

void main()
{
clrscr();
int ch;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	cout<<"\n\n\n\n\n\n\n\n\Press any key to continue!!";
	getch();

do
{
cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
cout<<"1.Administrator mode\n2.User mode\n3.Exit\n";
cout<<"Enter your choice:";
cin>>ch;
cout<<endl;

switch(ch)
{
case 1:
database();
break;
case 2:
user();
break;
case 3:
exit(0);
}

}while(ch<=3);
getch();
}

void database()
{
char *password;
char *pass="indian";
password=getpass("Enter the admininistrator password:");
detail a;
fstream f;
int ch;
char c;
if(strcmp(pass,password)!=0)
{
cout<<"Enter the password correctly \n";
cout<<"You are not permitted to logon this mode\n";
goto h;
}
if(strcmp(pass,password)==0)
{
char c;
do
{
cout<<"...........ADMINISTRATOR MENU...........\n";
cout<<"1.Create detail data base\n2.Update details\n";
cout<<"3.Display details\n4.User management\n";
cout<<"5.Display passenger details\n6.Return to main menu\n";
cout<<"Enter your choice:";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
f.open("dhoni.dat",ios::out|ios::binary);
do
{
a.getdetail();
f.write((char *)&a,sizeof(a));
cout<<"Do you want to add one more record?\n";
cout<<"y-for Yes\nn-for No\n";
cin>>c;
}while(c=='y'||c=='Y');
f.close();
break;
case 2:
f.open("dhoni.dat",ios::in|ios::out|ios::binary|ios::app);
a.getdetail();
f.write((char *)&a,sizeof(a));
f.close();
break;
case 3:
f.open("dhoni.dat",ios::in|ios::out|ios::binary|ios::app);
f.seekg(0);
while(f.read((char *)&a,sizeof(a)))
{
a.showdetail();
}
f.close();
break;
case 4:
manage();
break;
case 5:
displaypassdetail();
break;
}
}while(ch<=5);

f.close();
}
h:
}
void reserve1()
{
int ch;
do
{
cout<<"1.Reserve\n2.Return to the main menu\n";
cout<<"Enter your choice:";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
res();
break;
}
}while(ch==1);
getch();
}
void res()
{
detail a;
reserve b;
fstream f1,f2;
time_t t;
f1.open("dhoni.dat",ios::in|ios::out|ios::binary);
f2.open("kohli.dat",ios::in|ios::out|ios::binary|ios::app);
int ch;
b.reservedetail();
while(f1.read((char *) &a,sizeof(a)))
{
if(a.tno==b.tno)
{
if(strcmp(b.clas,f)==0)
{
if(a.c1>=b.nosr)

{
amt=a.c1fare;
pos=f1.tellg();
ad=sizeof(a.c1);
f1.seekp(pos-(7*ad));
a.c1=a.c1-b.nosr;
f1.write((char *)&a.c1,sizeof(a.c1));
{
b.amc=b.nosr*amt;
}
srand((unsigned) time(&t));
b.pnr=rand();
f2.write((char *) & b,sizeof(b));
b.showreservedetail();
cout<<"------------------------------------------------------\n";
cout<<"--------------Your ticket is reserved-----------\n";
cout<<"-----------------End of reservation menu-------\n";
}
else
{
cout<<"**********Sorry req seats not available********\n";

}
}
else if(strcmp(b.clas,s)==0)
{
if(a.c2>=b.nosr)
{
amt=a.c2fare;
pos=f1.tellg();
ad=sizeof(a.c2);
f1.seekp(pos-(5*ad));
a.c2=a.c2-b.nosr;
f1.write((char *) & a.c2,sizeof(a.c2));
{
b.amc=b.nosr*amt;
}
f2.write((char *) & b,sizeof(b));
b.showreservedetail();
cout<<"---------------------------------------\n";
cout<<"--------Your ticket is reserved--------\n";
cout<<"------------End of reservation---------\n";
}
else
{
cout<<"********Sorry req no of seats not available*******\n";
}
}
getch();
goto h;
}
else
{
flag=0;
}
}
if(flag==0)
{
cout<<"............Wrong train no......................\n";
cout<<"......Enter the train no from the data base.....\n";
}
f1.close();
f2.close();
getch();
h:
}
void displaypassdetail()
{
fstream f;
reserve b;
f.open("kohli.dat",ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char *)&b,sizeof(b)))
{
b.showreservedetail();
}
f.close();
getch();
}
void cancel1()
{
detail a;
reserve b;
cancel c;
fstream f1,f2,f3;
f1.open("dhoni.dat",ios::in|ios::out|ios::binary);
f2.open("kohli.dat",ios::in|ios::out|ios::binary);
f3.open("sehwag.dat",ios::in|ios::out|ios::binary);
cout<<"**********CANCELLATION MENU*********\n";
c.canceldetail();
while(f2.read((char *)&b,sizeof(b)))
{
 if(b.pnr==c.p)
   {
     flag=1;
     c.tno=b.tno;
     strcpy(c.tname,b.tname);
     strcpy(c.bp,b.bp);
     strcpy(c.dp,b.dp);
     c.nosc=b.nosr;
     for(int j=0;j<c.nosc;j++)
     {
       strcpy(c.pname[j],b.pname[j]);
       c.age[j]=b.age[j];
     }
     strcpy(c.clas,b.clas);
     if(strcmp(c.clas,f)==0)
     {
       while(f1.read((char *)&a,sizeof(a)))
       {
	if(a.tno==c.tno)
	 {
	  a.c1=a.c1+c.nosc;
	  d=a.d;
	  m=a.m;
	  pos=f1.tellg();
	  ad=sizeof(a.c1);
	  f1.seekp(pos-(7*ad));
	  f1.write((char *) & a.c1,sizeof(a.c1));
	  tamt=b.amc;
	  if((c.d==d)&&(c.m==m))
	  {
	   cout<<"You are cancelling at the date of departure\n";
	   c.amr=tamt-((tamt*60)/100);
	  }
	  else if(c.m==m)
	  {
	   cout<<"You are cancelling at the month of departure\n";
	   c.amr=tamt-((tamt*50)/100);
	  }
	  else if(m>c.m)
	  {
	   cout<<"You are cancelling one month before the date of departure\n";
	   c.amr=tamt-((tamt*20)/100);
	  }
	  else
	  {
	   cout<<"Cancelling after the departure\n";
	   cout<<"Your request cannot be completed\n";
	  }
	  goto h;
	 }
	}
       }
       else if(strcmp(c.clas,s)==0)
       {
	while(f1.read((char *) & a,sizeof(a)))
	{
	 if(a.tno==c.tno)
	 {
	  a.c2=a.c2+c.nosc;
	  d=a.d;
	  m=a.m;
	  pos=f1.tellg();
	  ad=sizeof(a.c2);
	  f1.seekp(pos-(5*ad));
	  f1.write((char *) & a.c2,sizeof(a.c2));
	  tamt=b.amc;
	  if((c.d==d)&&(c.m==m))
	  {
	  cout<<"You are cancelling at the date of departure\n";
	  c.amr=tamt-((tamt*60)/100);
	  }
	  else if(c.m==m)
	  {
	  cout<<"You are cancelling at the month of departure\n";
	  c.amr=tamt-((tamt*50)/100);
	  }
	  else if(m>c.m)
	  {
	  cout<<"You are cancelling one month before the date of departure\n";
	  c.amr=tamt-((tamt*20)/100);
	  }
	  else
	  {
	   cout<<"Cancelling after the departure\n";
	   cout<<"Your request cannot be completed\n";
	  }
	 goto h;
	}
       }
      }
     }
   }
  h:
  if(flag==0)
  {
   cout<<"Enter the correct pnr no\n";
  }
  else
  {
   c.showcanceldetail();
  }
f1.close();
f2.close();
f3.close();
getch();
}
void can()
{
int ch;
do
{
cout<<".................CANCELLATION MENU.........\n";
cout<<"1.Cancel\n2.Return to the main menu\n";
cout<<"Enter your choice:";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
cancel1();
break;
}
}while(ch==1);
getch();
}
void user()
{
login a;
int ch;
cout<<"*****************************************************\n";
cout<<"***********WELCOME TO THE USER MENU**\n";
cout<<"****************************************************\n";
char *password;

fstream f;
f.open("kumble.dat",ios::in|ios::out|ios::binary);
char id[100];
puts("Enter your id:");gets(id);
password=getpass("Enter your password:");
while(f.read((char *) & a,sizeof(a)))
{
if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
{
do
{
cout<<"1.Reserve\n2.Cancel\n3.Return to the main menu\n";
cout<<"Enter your choice:";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
reserve1();
break;
case 2:
cancel1();
break;
}
}while(ch<=2);
goto j;
}
else
{
d=1;
}
}
if(d==1)
{
cout<<"Enter your user id and password correctly\n";
}

getch();

j:
}
void manage()
{
int ch;
fstream f;
char c;
login a;
cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
do
{
cout<<"1.Create id data base\n2.Add details\n";
cout<<"3.Display details\n4.Return to the main menu\n";
cout<<"Enter your choice:";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
f.open("kumble.dat",ios::out|ios::binary);
do
{
a.getid();
f.write((char *) & a,sizeof(a));
cout<<"Do you want to add one more record\n";
cout<<"y-Yes\nn-No\n";
cin>>c;
}while(c=='y');
f.close();
break;
case 2:
f.open("kumble.dat",ios::in|ios::out|ios::binary|ios::app);
a.getid();
f.write((char *) & a,sizeof(a));
f.close();
break;
case 3:
f.open("kumble.dat",ios::in|ios::out|ios::binary);

f.seekg(0);
while(f.read((char *) & a,sizeof(a)))
{
a.displayid();
}
f.close();
break;
}
}while(ch<=3);
getch();
}