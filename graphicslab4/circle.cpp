#include<iostream>
#include<graphics.h>
using namespace std;
int main(){
int a,b,r,x,y,p;
int gd = DETECT, gm;
initgraph(&gd, &gm, "");
cout<<"Enter center of circle";
cin>>a>>b;
cout<<"Enter radius of circle";
cin>>r;
setbkcolor(15);
cleardevice();
setcolor(0);
x=0;
y=r;
p=(5/4)-r;
putpixel(x,y,1);
do{
if(p<0)
{
    y=y;
    x=x+1;
    p=p+2*x+1;
}
else{
    y=y-1;
    x=x+1;
    p=p+2*x-2*y+1;
}
putpixel(x+a,y+b,0);
putpixel(y+b,x+a,0);
putpixel(-x+a,y+b,0);
putpixel(-y+b,x+a,0);
putpixel(x+a,-y+b,0);
putpixel(y+b,-x+a,0);
putpixel(-x+a,-y+b,0);
putpixel(-y+b,-x+a,0);
}while(x<=y);
getch();
closegraph();
return 0;
}

