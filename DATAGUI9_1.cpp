/*  DataGUI: A C program which performs GUI operations for file handling.
    Copyright (C) 2016  Raja Rahul Ray

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

/*PERFECTO....*/
#include"header.h"
#include"ingraph.h"
#include"key.h"
#include"mouse.h"

union REGS i,o;

void layout();
void menu();
void tpdn();
void create();
void temp();
void fname();

void fname()
{
	char fname[10];
	outtextxy(234,222,"Enter the file name");
	gotoxy(35,18);
	gets(fname);
	rename("temp.txt",fname);
	if (rename("temp.txt",fname) == 0)
	   printf("Renamed to %s.\n", fname);
	else
	   perror("rename");

	//outtextxy(234,222,"File Saved.");
	layout();
}

void temp()
{
	cleardevice();
	setbkcolor(1);
	menu();
	gotoxy(2,5);
	FILE *p;
	int key,x,y,cl;
	char ch[40];
	p=fopen("temp.txt","a");
	if(p==NULL)
	{
		cleardevice();
		outtextxy(125,222,"Error in loading program......");
		delay(100);
		exit(0);
	}
	while(strlen(gets(ch))>0)
	{
		mshow();
		mpos(x,y,cl);
		fputs(ch,p);
		fputs("\n",p);
		/*if(cl==2)
		{
			if(strlen(ch)>0)
			goto save;
		else
			layout();
		} */
	}
	fclose(p);
	cleardevice();
	rectangle(100,150,500,300);
	outtextxy(155,180,"Do You Want To Save The File...");
	rectangle(180,230,235,250);
	rectangle(315,230,370,250);
	outtextxy(195,237,"YES");
	outtextxy(330,237,"NO");
	while(!kbhit())
	{
		//getkey(key);
		mshow();
		mpos(x,y,cl);
		if(x>=180&&x<=235&&y>=230&&y<=250&&cl==1)
		{
			rectangle(182,232,233,248);
			delay(100);
			cleardevice();
			fname();
		}
		if(x>=315&&x<=370&&y>=230&&y<=250&&cl==1)
		{
			remove("temp.txt");
			rectangle(317,232,368,248);
			delay(100);
			cleardevice();
			//outtextxy(234,222,"File not Saved.");
			layout();
		}
	}
}

void create()
{
	char ch[30],fn[20];
	FILE *q;
	rectangle(100,150,500,300);
	outtextxy(210,152,"Enter the file name to create..");
	gotoxy(30,14);
	gets(fn);
	// make the directory..
	// make provisions for checking ambiguity of file name...
	q=fopen(fn,"w");
	if(q==NULL)
	{
		cleardevice();
		outtextxy(125,222,"Error in loading file......");
		delay(100);
		exit(0);
	}
	cleardevice();
	layout();
	gotoxy(1,5);
	while(strlen(gets(ch))>0)
	{
		fputs(ch,q);
		fputs("\n",q);
	}
	fclose(q);
	layout();
}

void menu()
{
	rectangle(0,1,639,497);
	rectangle(0,1,639,50);
	rectangle(50,10,110,40);
	outtextxy(60,20,"FILE");
	rectangle(140,10,200,40);
	outtextxy(160,20,"OPEN");
	rectangle(230,10,290,40);
	outtextxy(250,20,"READ");
	rectangle(320,10,380,40);
	outtextxy(330,20,"APPEND");
	rectangle(410,10,470,40);
	outtextxy(420,20,"EXIT");
}

void tpdn()
{
	/*rectangle(52,100,128,140);
	outtextxy(60,120,"File");
	rectangle(50,60,130,200);*/
	rectangle(50,50,130,75);
	outtextxy(60,60,"Create");
	rectangle(50,75,130,100);
	outtextxy(60,85,"Op2");
	rectangle(50,100,130,125);
	outtextxy(60,110,"Op3");
	rectangle(50,125,130,150);
	outtextxy(60,135,"Exit");
	/*int key;
	getkey(key);    */
	int x,y,cl;
	setbkcolor(1);
	mshow();
	while(!kbhit())
	{
		mpos(x,y,cl);
		if(x>=50&&x<=130&&y>=50&&y<=75&&cl==1)
		{
			rectangle(52,52,128,73);
			delay(150);
			cleardevice();
			create();
		}
		if(cl==2)
			layout();
	}
}

void open()
{
	char fn[50];
	int c;
	FILE *p;
	rectangle(150,100,450,200);
	outtextxy(155,120,"Enter the file name to be opened");
	gotoxy(35,10);
	gets(fn);
	p=fopen(fn,"r");
	if(p==NULL)
	{
		cleardevice();
		outtextxy(160,150,"Oppps.....FILE Does not Exist.");
		outtextxy(160,160,"Press any key to go back to main menu..");
		getch();
	}
	else
	{
		closegraph();
		c = getc(p);
		while(c != EOF)
		{
			putchar(c);
			c = getc(p);

		}
		fclose(p);
		//printf("Testing...1234... something is not right...");
		getch();
	}
	ingraph();
	layout();
	menu();
}

void layout()
{
	ingraph();
	cleardevice();
	int x,y,cl;
	setbkcolor(1);
	menu();
	while(!kbhit())
	{
		mshow();
		mpos(x,y,cl);
		if(x>=140&&x<=200&&y>=10&&y<=40&&cl==1)
		{
			rectangle(142,12,198,38);
			delay(150);
			cleardevice();
			open();
		}
		if(x>=50&&x<=110&&y>=10&&y<=40&&cl==1)
		{
			rectangle(52,12,108,38);
			delay(150);
			cleardevice();
			menu();
			tpdn();
		}
		if(x>=230&&x<=290&&y>=10&&y<=40&&cl==1)
		{
			rectangle(232,12,288,38);
			delay(150);
			cleardevice();
			menu();
		}
		if(x>=320&&x<=380&&y>=10&&y<=40&&cl==1)
		{
			rectangle(322,12,378,38);
			delay(150);
			cleardevice();
			menu();
		}
		if(x>=410&&x<=470&&y>=10&&y<=40&&cl==1)
		{
			rectangle(412,12,468,38);
			delay(150);
			cleardevice();
			exit(0);
		}
		if(x>=1&&x<=639&&y>=50&&y<=497&&cl==1)
			temp();
	}
	closegraph();
}

void main()
{
	layout();
}
