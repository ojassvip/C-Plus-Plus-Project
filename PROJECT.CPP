#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void mainmenu();
class CD
{
	private:
		int bno;
		char bname[30];
		char aname[30];
		char type[10];
		int nocopy;
		char yredit[5];
		float cost;

	public:
		CD()
		{
			bno=0;
			nocopy=0;
			cost=0;
		}
int rbno()                //for asscessing private member outside class
{
	return bno;
}

char *rbname()
{
	return bname;
}
char *ran()
{
	return aname;
}

void accept()
{
	clrscr();
	int count=0;
	fstream f1;
	f1.open("CD.dat",ios::in|ios::binary);
	while(f1.read((char*)this,sizeof(CD)))
	count++;
	if(count==0)
	bno=1;
	else
	bno++;
	f1.close();
	cout<<"\nEnter The CD Number:-   "<<bno;
	cout<<"\nEnter The CD Title:-   ";
	gets(bname);
	cout<<"\nEnter Singer's Name:-   ";
	gets(aname);
	cout<<"\nEnter The Type of The CD:-   ";
	gets(type);
	cout<<"\nEnter No. of Copies:-   ";
	cin>>nocopy;
	cout<<"\nEnter Year of Release:-   ";
	cin>>yredit;
	cout<<"\nEnter the Cost of CD:-   ";
	cin>>cost;
}

void accept1()
{
	cout<<"\nEnter The CD Title:-   ";
	gets(bname);
	cout<<"\nEnter Singer's Name:-   ";
	gets(aname);
	cout<<"\nEnter The Type of The CD:-   ";
	gets(type);
	cout<<"\nEnter No. of Copies:-   ";
	cin>>nocopy;
	cout<<"\nEnter Year of Release:-   ";
	cin>>yredit;
	cout<<"\nEnter the Cost of The CD:-   ";
	cin>>cost;
}

void read();
void search();
void searchbname();
void shaname();
void shtype();
void shcost();
void shrelease();
};

void write()
{
	fstream f1("CD.dat",ios::app|ios::binary);
	CD e;
	e.accept();
	f1.write((char*)&e,sizeof(e));
	cout<<"\nRECORD ADDED SUCCESSFULLY!!!!!!!!!!\n";
	getch();
	f1.close();
}
void CD::read()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{

		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
		}

		else
			row++ ;
	}
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;
}
void update()
{
	clrscr();
	fstream f1("CD.dat",ios::in|ios::out|ios::binary);
	CD e;
	int n,flag=0,record=0;;
	cout<<"\nEnter CD No. to be Modified\n";
	cin>>n;
	while(f1.read((char*)&e,sizeof(e)))
	{
	record++;
	if(e.rbno()==n)
	{
	cout<<"\nEnter New Values\n";
	e.accept1();
	f1.seekp((record-1)*sizeof(e));
	f1.write((char*)&e,sizeof(e));
	cout<<"\n\n\n\nRecord Modified Sucessfully\n\n\n";
	getch();
	flag=1;
	break;
}
}
if(!flag)
	cout<<"\nRecord Not Found!!!!!!!\n";delay(200);
	f1.close();

}
void del()
{
	clrscr();
	fstream f1,f2;
	f1.open("CD.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::binary);
	CD e;
	int n,flag=0;
	cout<<"\nEnter CD Number to be Deleted\n";
	cin>>n;
	while(f1.read((char*)&e,sizeof(e)))
{
if(e.rbno()!=n)
	f2.write((char*)&e,sizeof(e));
else
	flag=1;
}
if(flag)
	cout<<"\nRecord Deleted!!!!!!!\n";
else
	cout<<"\nRecord Not Found!!!!!\n";getch();
	f1.close();
	f2.close();
	remove("CD.dat");
	rename("temp.dat","CD.dat");
}
void CD::search()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	int n;
	cout<<"\n\nEnter the CD number to be searched\n";
	cin>>n;
	clrscr();
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{
		if(bno==n)
       {
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";

		}
		else
			row++ ;
	}       }
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;
}
void CD::searchbname()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	char n[20];
	cout<<"\n\nEnter the CD name to be searched\n";
	gets(n);
	clrscr();
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{
	if(strcmpi(bname,n)==0)
	{
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
		}

		else
			row++ ;
	}       }
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;

}

void CD::shaname()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	char n[20];
	cout<<"Enter the singer's name whose CDs is to be searched\n";
	gets(n);
	clrscr();
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{
	if(strcmpi(aname,n)==0)
	{
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
		}

		else
			row++ ;
	}       }
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;

}

void CD::shtype()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	char n[20];
	cout<<"Enter the Type of CDs to searched\n";
	gets(n);
	clrscr();
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{
	if(strcmpi(type,n)==0)
	{
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
		}

		else
			row++ ;
	}       }
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;

}
void CD::shrelease()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	char n[20];
	cout<<"Enter the Year of Release to be searched\n";
	gets(n);
	clrscr();
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{
	if(strcmpi(yredit,n)==0)
	{
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
		}

		else
			row++ ;
	}       }
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;

}

void CD::shcost()
{
	clrscr() ;
	fstream file ;
	file.open("CD.dat",ios::in|ios::binary);
	file.seekg(0) ;
	int n;
	cout<<"Enter the minimum cost to see the CDs\n";
	cin>>n;
	clrscr();
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CDS" ;
	gotoxy(1,3) ;
	cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
	while (file.read((char *) this, sizeof(CD)))
	{
		if(cost>n)
		 {
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<bno;
		gotoxy(14,row) ;
		cout<<bname;
		gotoxy(27,row) ;
		cout<<aname;
		gotoxy(42,row) ;
		cout<<type;
		gotoxy(55,row) ;
		cout<<yredit;
		gotoxy(66,row) ;
		cout<<nocopy;
		gotoxy(74,row) ;
		cout<<cost;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			cout<<"LIST OF CDS" ;
			gotoxy(1,5) ;
			cout<<"\nCD No.    CD Name    Singer's Name    Type       Release    Sale     Cost\n\n";
		}

		else
			row++ ;
	}
	}
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;
}

void backup()
{
	char ch;
	cout<<"\n Are You Sure That You Want To Create A Backup? (y/n)\n";
	cin>>ch;

	if(ch=='y')
	{
		CD e;
		fstream f1,f2;
		f1.open("CD.dat",ios::in|ios::binary);
		f2.open("susa.dat",ios::out|ios::binary);
		while(f1.read((char*)&e,sizeof(e)))
		{
			f2.write((char*)&e,sizeof(e));
		}
	f1.close();
	f2.close();
	}
	cout<<"\n\nBackup Created!!!!!!";getch();
}
void restore()
{
	char ch;
	cout<<"\n Are You Sure You Want to Restore The Last Backup File? (y/n)\n";
	cin>>ch;

	if(ch=='y')
	{
		remove("CD.dat");
		rename("susa.dat","CD.dat");
		cout<<"\n\nBackup File Restored....";
	}
else
	cout<<"\nFile not Restored!!!!\n\n";
}
void menu()
{
	char ch1;
	CD b;
	int ch;
while(1)
{
clrscr();
cout<<"\n\n\n\t\t****************************************\n";
cout<<"\n\t\t\t       Search Menu\n";
cout<<"\n\t\t****************************************\n";
cout<<"\t\t\t1. Search by CD Number\n\t\t\t2. Search by CD Name\n"
<<"\t\t\t3. Search by Singer Name\n\t\t\t4. Search by Release\n"
<<"\t\t\t5. Search by Type\n\t\t\t6. Search by Cost\n"
<<"\t\t\t7. Back to Previous Menu\n\t\t\t8. Exit\n";
cout<<"\n\t\t****************************************\n";
cout<<"\n\n\n\t\tEnter your choice: ";
gotoxy(35,22);
cin>>ch;

switch(ch)
{
	case 1:
		b.search();
		break;
	case 2:
		b.searchbname();
		break;
	case 3:
		b.shaname();
		break;
	case 4:
		b.shrelease();
		break;
	case 5:
		b.shtype();
		break;
	case 6:
		b.shcost();
		break;
	case 7:
		mainmenu();
		break;
	case 8:
		exit(0);
	default:
		cout<<"\n\n\nInvalid Choice\n\n\n";
}
}
}
void mainmenu()
{
int ch;
char ch1;
CD b;
while(1)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\t\t    ****************************************\n\n";
cout<<"\t\t****** M . A . I . N  -  M . E . N . U *******\n";
cout<<"\n\t\t    ****************************************\n";
cout<<"\n\t\t\t1. Add a Record\n\t\t\t2. Display All The Records\n"
<<"\t\t\t3. Modify a Record\n\t\t\t4. Search a Record\n"
<<"\t\t\t5. Delete a Record\n\t\t\t6. Create a Backup\n"
<<"\t\t\t7. Restore the Last Backup File\n\t\t\t8. Exit\n";
cout<<"\n\t\t    ****************************************\n";
cout<<"\n\n\n\t\t   Enter Your Choice: ";
gotoxy(38,29);
cin>>ch;
switch(ch)
{
	case 1:
		write();
		break;
	case 2:
		b.read();
		break;
	case 3:
		update();
		break;
	case 4:
		menu();
		break;
	case 5:
		del();
		break;
	case 6:
		backup();
		break;
	case 7:
		restore();
		break;
	case 8:
{			clrscr();
			gotoxy(26,10);
			delay(200);
			cout<<"T";
			delay(100);
			cout<<"h";
			delay(100);
			cout<<"a";
			delay(100);
			cout<<"n";
			delay(100);
			cout<<"k";
			delay(100);
			cout<<" Y";
			delay(50);
			cout<<"o";
			delay(100);
			cout<<"u";
			delay(100);
			cout<<" F";
			delay(100);
			cout<<"o";
			delay(100);
			cout<<"r";
			delay(100);
			cout<<" V";
			delay(100);
			cout<<"i";
			delay(100);
			cout<<"s";
			delay(100);
			cout<<"i";
			delay(100);
			cout<<"t";
			delay(100);
			cout<<"i";
			delay(100);
			cout<<"n";
			delay(100);
			cout<<"g";
			delay(50);
			cout<<" M";
			delay(100);
			cout<<"y";
			delay(100);
			cout<<" P";
			delay(100);
			cout<<"r";
			delay(100);
			cout<<"o";
			delay(100);
			cout<<"j";
			delay(100);
			cout<<"e";
			delay(100);
			cout<<"c";
			delay(100);
			cout<<"t";
			getch();
			gotoxy(32,12);
			cout<<" HAVE A NICE DAY " ;
			getch();

exit(0);
}
default:
cout<<"\n\n\nInvalid Choice\n\n\n";
}
}
}

void main()
{
	clrscr();
	textcolor(GREEN);
	char ch1;
	int ch;
	char pass[15];
	gotoxy(30,15);
cout<<"Enter your Password   :  ";
gotoxy(55,15);
pass[0]=getch();
cout<<"*";
pass[1]=getch();
cout<<"*";
pass[2]=getch();
cout<<"*";
pass[3]=getch();
cout<<"*";
pass[4]=getch();
cout<<"*";
pass[5]=getch();
cout<<"*";
pass[6]=getch();
cout<<"*";

pass[7]='\0';
getch();
CD b;
if(strcmpi(pass,"ojassvi")==0)
{
 clrscr();
 cout<<"\n\n\n\n\n\t\t\t\tWELCOME TO MY PROJECT \n\n\n\n\t\t\t\tCD Management System\n\n\n\n\t\t\t\tMUSIC WORLD"
     <<"\n\n\n\t\t\tMade by:";
delay(100);
cout<<"O";
delay(100);
cout<<"J";
delay(100);
cout<<"A";
delay(100);
cout<<"S";
delay(100);
cout<<"S";
delay(100);
cout<<" V";
delay(100);
cout<<"I";
delay(100);
cout<<" ";
delay(100);
cout<<"P";
delay(100);
cout<<"R";
delay(100);
cout<<"A";
delay(100);
cout<<"D";
delay(100);
cout<<"H";
delay(100);
cout<<"A";
delay(100);
cout<<"N";
gotoxy(25,25);
cout<<"      Press any Key to Continue\n";
getch();
mainmenu();
}
else
cout<<"\n\n\n\nInvalid Password!!!!!!Try Again.....\n\n\n";
getch();
}




