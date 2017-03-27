#include"header.h"
union REGS in,out;
void mpos(int &x,int &y,int &cl)
{
	in.x.ax=3;
	int86(51,&in,&out);
	x=out.x.cx;
	y=out.x.dx;
	cl=out.x.bx;
}
void mshow()
{
	in.x.ax=1;
	int86(51,&in,&out);
}
  void rstmpt(int x1,int y1,int x2,int y2)
          {
                 in.x.ax=7;
                 in.x.cx=x1;
                 in.x.dx=x2;
                 int86(51,&in,&out);
                 in.x.ax=8;
                 in.x.cx=y1;
                 in.x.dx=y2;
                 int86(51,&in,&out);
	  }
/*void gmouse()
{
int g=DETECT,m,er,x,y,cl;
	initgraph(&g,&m,"C:\\TURBOC3\\BGI");
	er=graphresult();
	if(er!=grOk)
	{
	gotoxy(35,15);
	printf("ERRO In GRAPHICS DRIVER");
	}
	in.x.ax=1;
	int86(51,&in,&out);
	mpos(x,y,cl);
	gotoxy(15,15);
	printf("%d %d %d",x,y,cl);
	getch();
	closegraph();
}*/