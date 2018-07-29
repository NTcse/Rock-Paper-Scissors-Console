#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
void thongbao(int &);
char xnhan(char &);
int mncore(int&);
void tg(int&time);
void tiso(int &);
void kq(int &);
int quytac(int &);
int random(int &r);
int ktsnguyen(int &n);
int nhap(int &n);
void menu();
void changeTextColor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
int mncore(int win,int lost,int draw,int i,int core,char &l,int &max)
{
	int moc;
	if(max<=core)
		max=core;
	cout<<"\nTHANH TICH HIEN TAI";
	cout<<"\nSo ban: "<<i<<"\tScore: "<<core<<"\tMAX SCORE: "<<max;
	cout<<"\nWin: "<<win<<"\tDraw: "<<draw<<"\tLost: "<<lost<<endl;
	moc=core;
	if(core==100)
	{
		cout<<"\nCHUC MUNG BAN DA CHINH PHUC DUOC TRO CHOI";
		cout<<"\nBAN THAT KIEN NHAN KHI DA CHOI "<<i<<" BAN ĐE CHIEN THANG\n";
		xnhan(l);
	}
	else if(core>100&&core%50==0)
	{
		cout<<"\nCHUC MUNG BAN DA DAT MOC CAO HON CUA TRO CHOI";
		cout<<"\nBAN THAT KIEN NHAN KHI DA CHOI "<<i<<" BAN ĐE DAT COT MOC "<<core<<" KHI DA CHINH PHUC TRO CHOI\n";
		xnhan(l);
	}
	else
		if(moc%5==0 && moc!=0 && core!=100 &&!(core>100&&core%50==0))
		{
			cout<<"\nCHUC MUNG BAN ĐA DAT MOC "<<moc<<" ĐIEM";
			cout<<"\nHAY CO GAN CHINH PHUC CAC MOC TIEP THEO\n";
		}
	return 0;
}
void menu()
{
	cout<<"GAME KEO BUA BAO THACH THUC 100 DIEM";
	cout<<"\nQuy dinh: 1.Keo 2.Bua 3.Bao";
	cout<<"\nMoi ban lua chon...Nhap 0 de thoat...\n";
}
int ktsnguyen(int &n)
{
	/*char c = _getch();
	int kt=0;
	while (kt==0) {
		if (_kbhit()) {			
			switch (c) {
				case '1': { cout << "Ban chon 1\n";kt=1; n=1; break;}
				case '2': { cout << "Ban chon 2\n";kt=1; n=2; break;}
				case '3': { cout << "Ban chon 3\n";kt=1; n=3; break;}
				case '0': { cout << "Ban chon 0\n";kt=1; n=0; break;}
				default : { cout<<" khac";kt=1;n=4; break;}
			}
		}}*/
	char check;
		cin.get(check);
		system("cls");
		if(int (check)>47 & int (check)<58)
			n=int (check)-48;
		else
			n=4;
    return n;
}
int nhap(int &n)
{
	menu();
	do{
		ktsnguyen(n);
		system("cls");
		if(n==1||n==2||n==3||n==0)
			break;
		else
		{
			cout<<"Lua chon cua ban khong dung quy dinh\n";
			menu();
		}
	}while (n!=1||n!=2||n!=3||n==0);
	system("cls");
	return n;
}
int random(int &r)
{
	srand(time(NULL));
	r = rand() % 3 + 1;
	return r;
}
int quytac(int &n,int r)
{
	switch (n)
	{
	case 1:
		{
			if(r==3)
			{system("color 9");return 1;}
			else if(r==2)
			{system("color D");return 2;}
			else
			{system("color F");return 0;}
		}
	case 2:
		{
			if(r==3)
			{system("color D");return 2;}
			else if(r==2)
			{system("color F");return 0;}
			else
			{system("color 9");return 1;}
		}
	case 3:
		{
			if(r==3)
			{system("color F");return 0;}
			else if(r==2)
			{system("color 9");	return 1;}
			else 
			{system("color D");return 2;}
		}
	}
}
void thongbao(int &n, int r)
{
	cout<<"\tKET QUA LUA CHON CUA BAN";
	cout<<"\nBan chon ";
	switch(n)
	{
	case 1: 
		{
			cout<<"Keo";
			break;
		}
	case 2:
		{
			cout<<"Bua";
			break;
		}
	case 3:
		{
			cout<<"Bao";
			break;
		}
	};
cout<<"\nMay chon ";
	switch(r)
	{
	case 1: 
		{
			cout<<"Keo";
			break;
		}
	case 2:
		{
			cout<<"Bua";
			break;
		}
	case 3:
		{
			cout<<"Bao";
			break;
		}
	};
}
void kq(int &n,int &r,int &win,int &lost,int &draw,int &core)
{	
	switch(quytac(n,r))
	{
	case 1:
		cout<<"\nBan thang\t\*YOU WIN\*\n";
		win++;
		core++;
		break;
	case 2:
		cout<<"\nBan thua roi\t_YOU LOST_\n";
		lost++;
		if(core!=0)
		core--;
		break;
	case 0:
		system("color 6");
		cout<<"\nBan va May hoa nhau\t=DRAW=\n";
		draw++;
	};
}
void tiso(int &i,int &win,int &lost,int &draw,int &core,char &l,int max)
{
	cout<<"\tTHONG BAO QUA TRINH CHOI ";
	cout<<"\nGAME KEO BUA BAO THACH THUC 100 DIEM";
	mncore(win,lost,draw,i,core,l,max);
	if(core>=100)
		cout<<"\nBan da chinh phuc duoc tro choi KEO BUA BAO THACH THUC 100 DIEM";
	else
		cout<<"\nBan chua chinh phuc duoc tro choi KEO BUA BAO THACH THUC 100 DIEM...Hay co len";
	cout<<"\nChuc ban luon vui ve :) "<<endl;
}
char xnhan(char &l)
{
	system("color C");
	char kt='C';
	cout<<"Ban that su muon thoat?";
	cout<<"\nNhap Y de dong y / Nhap bat ky de choi lai\n";
	cin>>kt;
	system("cls");
	if(kt=='Y'||kt=='y')
		l='T';
	else
		l='C';
	return l;
}
void tg(int&time)
{
	while(time!=0)
	{
		cout<<"\b\b"<<time<<"s";
		Sleep(998);
		time--;
	}
}
int main ()
{
	char l;
	int n,r=0,win=0,lost=0,draw=0,i=0,core=0,max=0,time;
	do
	{
	system("color F");
	time=3;
	nhap(n);
	if(n!=0)
	{
	random(r);
	quytac(n,r);
	thongbao(n,r);
	kq(n,r,win,lost,draw,core);
	i++;
	mncore(win,lost,draw,i,core,l,max);
	cout<<"Se tiep tuc sau:   ";
	tg(time);
	system("cls");
	}
	else
	{
		time=5;
		xnhan(l);
	}
	}while(l!='T' && l!='t');
	system("color A");
	tiso(i,win,lost,draw,core,l,max);
	cout<<"Cua so se dong sau:   ";
	tg(time);
	return 0;
}