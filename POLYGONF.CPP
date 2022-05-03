#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>

class point
{
    public:
    int x,y;
};

point p[20];
int inter[20],x,y;
int v,xmin,ymin,xmax,ymax;
int c;

void read()
{
	cout<<"SCAN_FILL ALGORITHM";
	cout<<"\nEnter the no of vertices of polygon : ";
	cin>>v;
	cout<<"Enter the coordinates : \n "  ;
	for(int i=0; i<v; i++)
	{
		cout<<"x"<<(i+1)<<"=";
		cin>>p[i].x;
		cout<<"y"<<(i+1)<<"=";
		cin>>p[i].y;
	}
	
	p[i].x=p[0].x;
	p[i].y=p[0].y;
	xmin=xmax=p[0].x;
	ymin=ymax=p[0].y;
}

void calcs()
{
    for(int i=0;i<v;i++)
    {
		if(xmin>p[i].x)
			xmin=p[i].x;
		if(xmax<p[i].x)
			xmax=p[i].x;
		if(ymin>p[i].y)
			ymin=p[i].y;
		if(ymax<p[i].y)
			ymax=p[i].y;
    }
}

void ints(float z)
{
    int x1,x2,y1,y2,temp;
    c=0;
    for(int i=0;i<v;i++)
    {
		x1=p[i].x;
		y1=p[i].y;
		x2=p[i+1].x;
		y2=p[i+1].y;
		if(y2<y1)
		{
		    temp=x1;
		    x1=x2;
		    x2=temp;
		    temp=y1;
		    y1=y2;
		    y2=temp;
		}
		if(z<=y2&&z>=y1)
		{
		    if((y1-y2)==0)
		    	x=x1;
		    else
			{
				x=((x2-x1)*(z-y1))/(y2-y1);
				x=x+x1;
		    }
		    if(x<=xmax && x>=xmin)
		    	inter[c++]=x;
		}
    }
}

void sort(int z)
{
    int temp,j,i;

	for(i=0;i<v;i++)
	{
	    line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
	}
	
	delay(100);
	for(i=0; i<c;i+=2)
	{
	   delay(50);
	   line(inter[i],z,inter[i+1],z);
	}
}

void display()
{
    float s;
    s=ymin+0.01;
    cleardevice();
    while(s<=ymax)
    {
		ints(s);
		sort(s);
		s++;
	}
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    setcolor(RED);
    read();
    calcs();
    cleardevice();
    display();
    getch();
    return 0;
}

