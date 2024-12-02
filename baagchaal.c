
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
rectangle(5,5,400,400);
line(5,202.5,400,202.5);
line(202.5,5,202.5,400);
line(5,202.5,202.5,5);
line(202.5,5,400,202.5);
line(5,202.5,202.5,400);
line(202.5,400,400,202.5);
line(5,400,400,5);
line(5,5,400,400);
line(5,103.75,400,103.75);
line(5,301.25,400,301.25);
line(103.75,5,103.75,400);
line(301.25,5,301.25,400);
circle(202.5,202.5,100);
getch();
closegraph();
}