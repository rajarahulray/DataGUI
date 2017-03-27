#include"header.h"
void ingraph()
{
int gd=DETECT,gm,er;
initgraph(&gd,&gm,"C:\\TC\\BGI");
er=graphresult();
if(er!=grOk)
{
gotoxy(25,15);
printf("ERROR IN GRAPHICS DRIVER");
getch();
exit(0);
}
}