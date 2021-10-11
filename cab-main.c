#include<fstream.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iomanip.h>


class car  //class that contains the driver details
{
  int id;
  char name[20];
  char type[20];
  char pno[11];
  float cost;
  char avail;
  public:
	  void in();

	  void putavail()//makes driver availibilty to no
	  {
	  avail='n';
	  }
	  char getavail()
	  {
	  return avail;
	  }
	  void obill()
	  {cout<<"Driver name     : "<<name<<endl;
	   cout<<"Vehicle type    : "<<type<<endl;
	   cout<<"Contact number  : "<<pno<<endl;
	   }
	  void out()
	  {
	   cout<<id<<setw(5)<<name<<setw(15)<<type<<setw(15)<<cost<<setw(10)<<avail<<setw(20)<<pno<<endl;

	  }
	  car()
	  { avail='y';

	  }
	  car (car &z)
	  {    strcpy(pno,z.pno);
	       id=z.id;
	       strcpy(name,z.name);
	       strcpy(type,z.type);
	       cost=z.cost;
	  }
	  int getid()
	  {
	    return id;
	  }
	  char* gettype()
	  {
	   return type;
	  }
	  float getcost()
	  {
	   return cost;
	  }
	   void out1()
	  {
	   cout<<name<<"    "<<type<<"      "<<cost<<"   "<<endl;
	  }
	  void makeavail()
	  {avail='y';
	  }
	  void putpno()
	  {cout<<"Enter the new contact number : ";
	   cin>>pno;
	  }
	  void putcost()
	  {cout<<"Enter the new cost per kilometer of the driver : ";
	   cin>>cost;
	   }

};
void car::in()
{          car a;
	   fid:
	   cout<<"Enter driver id,name,type,cost,phone number : "<<endl;
	   cin>>id;
	   ifstream fin;

	   fin.open("carz.dat",ios::binary);
	   while(!fin.eof())
		{
		  fin.read((char*)&a,sizeof(a));
		  if(!fin) break;
		  if(id==a.id)
		  {cout<<"id cannot be repeated.Please use another id number ";
		  getch();
		  clrscr();

		  goto fid;
		  }
		}fin.close();
	   cin>>name>>type>>cost>>pno;
  }

void mavail()
{int id;
 cout<<"Enter the driver id whose trip has ended : ";
 cin>>id;
 car a;
 ifstream fin;
 ofstream fout;
 fin.open("carz.dat",ios::binary);
 fout.open("tempd.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&a,sizeof(a));
  if(!fin)break;
  if(id==a.getid())
    {
     a.makeavail();
     fout.write((char*)&a,sizeof(a));
     }
  else
  {fout.write((char*)&a,sizeof(a));
  }
 }

fout.close();
fin.close();
remove("carz.dat");
rename("tempd.dat","carz.dat");
}


void ins()
{
  car obj;
  ofstream fout;
  fout.open("carz.dat",ios::binary|ios::app);
  obj.in();
  fout.write((char*)&obj,sizeof(obj));
  fout.close();
}

void out()
{
 car obj;
 ifstream fin;
 fin.open("carz.dat",ios::binary);
  cout<<"ID"<<setw(5)<<"Name"<<setw(15)<<"Type"<<setw(15)<<"Cost"<<setw(10)<<"Avail"<<setw(20)<<"Phone number"<<endl;
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)
      {
      break;
      }
  obj.out();
 }
fin.close();
}

void bookd()
{
   car obj;
 ifstream fin;
 fin.open("carz.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)break;
  obj.out1();
 }
fin.close();
}

void editd()
{int id;
int op;
char pno[11];
cout<<"Enter the driver id you want to edit : ";
cin>>id;
   car obj;
 ifstream fin;
 ofstream fout;
 fin.open("carz.dat",ios::binary);
 fout.open("tempd.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)break;
  if(id==obj.getid())
    {
     cout<<"1.Contact number ";
     cout<<"\n2.Cost per km "<<endl;
     cin>>op;
     switch(op)
	   {case 1 :  clrscr();
		      obj.putpno();
		      fout.write((char*)&obj,sizeof(obj));
		      cout<<"UPDATED!";
		      break;
	    case 2 :  clrscr();
		      obj.putcost();
		      fout.write((char*)&obj,sizeof(obj));
		      break;

	    }
    }
  else
  {fout.write((char*)&obj,sizeof(obj));
  }
 }

fout.close();
fin.close();
remove("carz.dat");
rename("tempd.dat","carz.dat");
}





void time()
{
  time_t t;
   time(&t);
   printf(" %s\n", ctime(&t));

}




void dele()
{
 car obj;
 int s;
 cout<<"Enter the id to be deleted"<<endl;
 cin>>s;
  ifstream fin;
  ofstream fout;
 fout.open("temp.dat",ios::binary);
 fin.open("carz.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)break;
  if(s!=obj.getid())
  {
    fout.write((char*)&obj,sizeof(obj));
  }
 }
 fout.close();
 fin.close();
  remove("carz.dat");
  rename("temp.dat","carz.dat");
}

class sd //contains source and destination
{
  int sno;
 char source[20];
 char dest[20];
 float km;
 int d ;
  public:
	 void ins();
	 /*
	 {
	  cout<<"enter the sno,source,destination and distances"<<endl;
	  cin>>sno>>source>>dest>>km;
	  } */

	 void bdisp()
	 {
	   cout<<source<<"->"<<dest<<endl;
	   cout<<"Distance : "<<km<<"km"<<endl;
	 }


	 void disp()
	 {
	   cout<<sno<<setw(15)<<source<<setw(15)<<dest<<setw(15)<<km<<endl;
	 }
	 int getsno()
	 {
	   return sno;
	 }
	 float getd()
	 {
	  return km;
	 }

};
void sd::ins()
{int sno;
sd s;
 fno:
cout<<"enter the sno,source,destination and distances"<<endl;
cin>>sno;
ifstream fin;
fin.open("sd.dat",ios::binary);
while(!fin.eof())
     {
      fin.read((char*)&s,sizeof(s));
      if(!fin) break;
      if(sno==s.sno)
	{cout<<"sno cannot be repeated.Please use another serial number ";
	 getch();
	 clrscr();
	 goto fno;
	}
      }fin.close();
     cin>>source>>dest>>km;
  }
void ifile()
{
  sd obj;
  ofstream fout;
  fout.open("sd.dat",ios::binary|ios::app);
  obj.ins();
  fout.write((char*)&obj,sizeof(obj));
  fout.close();

}

void dispfile()
{
    sd obj;
  ifstream fin;
  fin.open("sd.dat",ios::binary);
  cout<<"Sno"<<setw(15)<<setw(15)<<"Source"<<setw(15)<<"Destination"<<setw(15)<<" Distance "<<endl;
  while(!fin.eof())

  {
    fin.read((char*)&obj,sizeof(obj));
    if(!fin)break;
    obj.disp();

  }

  fin.close();
}

void delefile()
{
  sd obj;
  int s;
 cout<<"Enter the id to be deleted : "<<endl;
 cin>>s;
  ifstream fin;
  ofstream fout;
 fout.open("temp1.dat",ios::binary);
 fin.open("sd.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)break;
  if(s!=obj.getsno())
  {
    fout.write((char*)&obj,sizeof(obj));
  }
 }
 fout.close();
 fin.close();
  remove("sd.dat");
  rename("temp1.dat","sd.dat");
}

void editsd()
    {int sn;
    cout<<"Enter the serial number to be editted : ";
    cin>>sn;
    sd obj;
 ifstream fin;
 ofstream fout;
 fin.open("sd.dat",ios::binary);
 fout.open("tempd.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)break;
  if(sn==obj.getsno())
    {cout<<"Enter the new details : ";
     obj.ins();
     fout.write((char*)&obj,sizeof(obj));

    }
  else
  {fout.write((char*)&obj,sizeof(obj));
  }
 }

fout.close();
fin.close();
remove("sd.dat");
rename("tempd.dat","sd.dat");
}

class bill
{ car obj;
  sd t;
  float tprice;
  time_t l;
  float tax;
  float price;

  public :
   bill()
   { l=time(NULL);
     tax=0.18*price;
     tprice=tax+price;
   }

  bill(car n,sd m,float y,time_t x)
      {
       obj=n;
       t=m;
       price=y;
       bill();
       l=x;

       }

  void disp()
  {
  cout<<"_______________________________________________________________" <<endl;
  cout<<"                      RYDES CARS AND TRAVELS                   "<<endl;
  cout<<"_______________________________________________________________"<<endl ;
  printf(" %s\n", ctime(&l));
  cout<<"DRIVER DETAILS "<<endl;
  obj.obill();
   cout<<"_______________________________________________________________"<<endl ;
   cout<<"TRAVEL DETAILS "<<endl;
   t.bdisp();
   cout<<"_______________________________________________________________"<<endl ;
   cout<<" Price     : "<<price<<endl;
   tax=0.18*price;
   tprice=tax+price;
   cout<<"+Tax       : "<<setprecision(2)<<tax<<endl;
   cout<<"           _________"<<endl;
   cout<<" Net Price : "<<setprecision(2)<<tprice<<endl;
    cout<<"_______________________________________________________________"<<endl ;
  }
};

void vbill()
{
    bill obj;
  ifstream fin;
  fin.open("bills.dat",ios::binary);
  int y=0;
  while(!fin.eof())
  {
    fin.read((char*)&obj,sizeof(obj));
    y++;
    if(!fin)break;
    obj.disp();
    getch();
    clrscr();
       /*	if(y%2==0)
     { getch();
      clrscr();
      }*/

  }

  fin.close();

}

void book()
{
  ch:
  time_t ti=time(NULL);
  int n,d;
  int price,op;
  car a,b;
  char c[20],opt;
  cout<<"The types of vehicles we offer : ";
  cout<<"\nSedan \nSUV \nBus"<<endl;
  cout<<"Enter the type of car you want to travel in : ";
  cin>>c;
  int i=0,j,z,f=0,id;

  ifstream fin;
  fin.open("carz.dat",ios::binary);
  while(!fin.eof())
  {
    fin.read((char*)&a,sizeof(a));
    if(!fin)break;
   if (strcmpi(c,a.gettype())==0 && a.getavail()=='y')
   {
    id=a.getid();
    b=a;
    fin.close();
    f=1;
    break;
    }
   i++;
 }
 fin.close();

 ofstream fout;
 fin.open("carz.dat",ios::binary);
 fout.open("tempd.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&a,sizeof(a));
  if(!fin)break;
  if(id==a.getid())
    {
     a.putavail();
     fout.write((char*)&a,sizeof(a));
     }
  else
  {fout.write((char*)&a,sizeof(a));
  }
 }

fout.close();
fin.close();
remove("carz.dat");
rename("tempd.dat","carz.dat");

 if (f==0)
 { cout<<"Requested type doesn't match /not available \n";
 getch();
 return;
 }
  b.out1();
  cout<<endl;
  cout<<"Enter your choice : "<<endl;
  dispfile();
  cin>>n;
  sd obj;
  int f1=0;
  fin.open("sd.dat",ios::binary);
 while(!fin.eof())
 {
  fin.read((char*)&obj,sizeof(obj));
  if(!fin)break;

  if(n==obj.getsno())
  {
    d=obj.getd();
    f1=1;
    break;
  }

  }
  if (f1==1)
  {
  cout<<"Cost of driver : ";
  price=d*b.getcost();
  cout<<"Rs."<<price<<endl;

  }
 fin.close();
 cout<<"Confirm booking ? : ";
 cin>>opt;

 if(opt=='y')
 {
  bill bot(b,obj,price,ti);
   cout<<"Booking has been confirmed \nPress any key to view bill"<<endl;
   getch();
  clrscr();
  bot.disp();getch();
  ofstream fout;
  fout.open("bills.dat",ios::binary|ios::app);
  fout.write((char *)&bot,sizeof(bot));
  fout.close();

 }
 else
   {
  cout<<"1.Book with another driver \n2.I dont wanna book ";
  cin>>op;
     if(1==op)
       {
	  goto ch;
       }
	 else
	   return; //exitmenu
   }

}

int pass()
  {
    int i,x;
    char ch='/0',password[]="p&a",match[20];
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
	{
	 cout<<"*";
	 match[i]=ch;
	 i++;
	}
      else if (ch==8) // if backspace is presssed
       {
	 cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
	 i--;
       }
      else if(ch==13)
    {
	 match[i]='\0'; // if enter is pressed, last character in match[] becomes null
	break;         // for end of string
    }
    else
    {
	 break;
    }
  }
  if(strcmp(match,password)==0)// comparing two strings.. if equal returns 0
  {
   return 1;
  }
  else
  {
   cout<<endl<<"Wrong password"<<endl;
   return 0;
  }
}

void main()
{ int opt,op,dop,sdop,p;
  char u[20];
  clrscr();
  car obj;
  menu:
  do{
  cout<<"_______________________________________________________________" <<endl;
  cprintf("                      RYDES CARS AND TRAVELS                   ");
  cout<<endl;
  textcolor(3);
  cout<<"_______________________________________________________________"<<endl ;

  cout<<"1.Admin \n2.User \n3.Exit"<<endl;
  cin>>opt;
  switch(opt)
	{
	 case 1 :
		   cout<<"Username :";
		   cin>>u;
		   cout<<"Password :";
		   p=pass();
		   if(p==1)
		   {admin:
		   do{
		   getch();
		   clrscr();
		   cout<<"MENU\n1.Manage Drivers \n2.Manage source and destination";
		   cout<<"\n3.View bills \n4.Exit admin menu"<<endl;
		   cin>>op;
		   switch(op)
			  {case 1 : //Manage drivers
				    do{
				    getch();
				    clrscr();
				    cout<<"MENU \n1.Add driver \n2.Delete driver ";
				    cout<<"\n3.Edit drivers \n4.View drivers";
				    cout<<"\n5.End Driver trips ";
				    cout<<"\n6.Exit Manage drivers \n7.Exit to main menu"<<endl;
				    cin>>dop;
				    switch(dop)
					   {case 1 : ins();break;
					    case 2 : dele();out();break;
					    case 3 : editd();break;
					    case 4 : out();break;
					    case 5 : mavail();
						     cout<<"The updated driver records : "<<endl;
						     out();break;
					    case 6 : goto admin;
					    case 7 : clrscr();goto menu;
					    default : cout<<"option doesnt exist ";

					   }

				    }while(1);
				   // break;

			    case 2 : //Manage source destination
				     do{
				     getch();
				     clrscr();
				     cout<<"MENU \n1.Add source and destination\n 2.Delete source and destination ";
				     cout<<"\n3.Edit source and destination \n4.View source and destination";
				     cout<<"\n5.Exit Manage source and destination \n6.Exit to main menu"<<endl;
				     cin>>sdop;
				     switch(sdop)
					   {case 1 : ifile();break;
					    case 2 : delefile();break;
					    case 3 : editsd(); break;
					    case 4 : dispfile();break;
					    case 5 : goto admin;
					    case 6 : clrscr();goto menu;
					    default : cout<<"optio doesnt exist " ;
					   }
				      }while(1);
				     // break;

			      case 3 ://View bills
				      vbill();
				      goto admin;

			      case 4 : clrscr();goto menu;



			  }  }while(1);
		    }
		    else
		    {goto menu;
		    }



	 case 2 :  int uop;
		   do{clrscr();
		   cout<<"MENU \n1.Book a ride \n2.Write a review \n3.View reviews \n4.Exit user menu"<<endl;
		   cin>>uop;
		   switch(uop)
		   {case 1 : book();break;
		    case 2 : ofstream fout;
			     char st[150];
			     fout.open("reviews.txt",ios::app);
			     cout<<"Enter the review and your name (150 characters) : "<<endl;
			     gets(st);
			     fout<<st<<endl;
			     fout.close();
			     break;
		     case 3 :ifstream fin;
			     char s[150];
			     fin.open("reviews.txt");
			     while(!fin.eof())
			     {fin.getline(s,150);
			     if(!fin) break;
			      cout<<s<<endl<<endl;
			      }
			      fin.close();
			      getch();
			      break;
		     case 4 : clrscr();goto menu;

		     default : cout<<"Option doesnt exist ";
		    } }while(1);

	  case 3 : cout<<"Visit us again \1 \3";
		   getch();
		   exit(0);


}
} while(1);

}



