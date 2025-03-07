#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

#define pi 3.14285714

class transformations
{
	double vertices[3][3];             
	double t_matrix[3][3];             
	double result[3][3];
	
	public:
	transformations(){};
	
	void get_vertices();
	void display_triangle();
	void display_triangle_result();
	
	void multiplication();
	void copyback();
	
	void scaling(double a,double d);

};


void transformations::get_vertices()
{
	int i=0;
	
	for(i=0;i<3;i++)
	{
		cout<<"\nEnter vertex "<<i+1<<":";
		cout<<"\nx1 : ";
		cin>>vertices[i][0];
		result[i][0]=vertices[i][0];
	
		cout<<"y1 : ";
		cin>>vertices[i][1];
		result[i][1]=vertices[i][1];
	
		vertices[i][2]=result[i][2]=1;
	}
}


void transformations::display_triangle()
{
	int i=0;
	
	for(i=0;i<2;i++)
	     line(vertices[i][0],vertices[i][1],vertices[i+1][0],vertices[i+1][1]);
	line(vertices[i][0],vertices[i][1],vertices[0][0],vertices[0][1]);
}


void transformations::display_triangle_result()
{
	int i=0;
	
	for(i=0;i<2;i++)
	     line(result[i][0],result[i][1],result[i+1][0],result[i+1][1]);
	line(result[i][0],result[i][1],result[0][0],result[0][1]);
}


void transformations::copyback()
{
	int i=0,j=0;
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			result[i][j]=vertices[i][j];
}


void transformations::multiplication()
{
	double r[3][3];
	int i=0,j=0,k=0;
	
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				r[i][j]=0;
				for(k=0;k<3;k++)
					r[i][j]+=result[i][k]*t_matrix[k][j];
			}
		}
	
	for(i=0;i<3;i++)              
		for(j=0;j<3;j++)
			result[i][j]=r[i][j];
}


void transformations::scaling(double a,double d)
{
	copyback();
	cleardevice();
	
	setcolor(YELLOW);
	display_triangle();
	delay(10);
	getch();
	
	t_matrix[0][0]=a;                     
	t_matrix[0][1]=0;
	t_matrix[0][2]=0;
	t_matrix[1][0]=0;
	t_matrix[1][1]=d;
	t_matrix[1][2]=0;
	t_matrix[2][0]=0;
	t_matrix[2][1]=0;
	t_matrix[2][2]=1;
	
	multiplication();
	
	setcolor(GREEN);
	display_triangle_result();
	delay(10);
	getch();
}


void main()
{
	clrscr();
	int gd=DETECT,gm,choice;
	transformations t1;
	char ch1,ch2;
	double angle,m,n,slope,intercept,a,b,c,d;
	
	do
	{
		cout<<"\n\n\tTWO DIMENSIONAL TRANSFORMATIONS\n";
		cout<<"\nEnter the details of a triangle(i.e. 2-D object)";
		t1.get_vertices();

		initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
		cout<<"\nSCALING..........";
		cout<<"\nEnter the factor of scaling...";
		cout<<"\nAlong the x-axis : ";
		cin>>a;
		cout<<"Along the y-axis : ";
		cin>>d;

		t1.scaling(a,d);
		closegraph();

		cout<<"\n\nDo you want to try with a triangle with different dimensions(Y/N)? ";
		cin>>ch1;

	}
	while(ch1=='y' || ch1=='Y');
}

