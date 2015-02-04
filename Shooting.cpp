#include<stdlib.h>
#include <GL/glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include<conio.h>
#include <string.h>
#include<dos.h>
#define WIDTH 640
#define HEIGHT 480
#define N 10000
char s[14]="SHOOTING GAME";
void init(void){
	glClearColor(0.0,0.0,0.0,1.0);
	glPointSize(2.0);
}
void Timer(int ex)
{
	glutPostRedisplay();
	glutTimerFunc(50,Timer,0);
}
int r=25,flag=-1,i=0;
int k[2]={0,0},z[N];
int a=5,b=2;
char id;
int no=0;
int cx=0,cntkey=0,sqy=0;
int cy=r,epx=-280,epy[N],score=0;
int cnt=1,s2[2]={20,40},s1[2]={10,20},x[2]={50,120},y[2]={240,240};
 void elliplot(int Xc,int Yc,int ex,int ey,int p)
  {
	   int j;
	   float srand;
	   glColor4f(1.0,0.0,0.0,1.0);
       glVertex2i((Xc+ex)+p,(Yc+ey));
	   for(j=0;j<2;j++)
	   {
			for(int i=1;i<=s1[j];i++)
			{
				if((Xc+ex)+p==(x[j]+i) && (Yc+ey)==y[j]+k[j])
				{
					s1[j]=15;
					s2[j]=20;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc+ex)+p==(x[j]+i) && ((Yc+ey)==(y[j]+ k[j] + s2[j])))
				{
					s1[j]=15;
					s2[j]=15;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			
			}
			for(int i=1;i<=s2[j];i++)
			{
				if((Xc+ex)+p==(x[j]) && (Yc+ey)==(y[j] + k[j] + i))
				{
					s1[j]=12;
					s2[j]=22;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc+ex)+p==(x[j] + s1[j]) && ((Yc+ey)==(y[j]+ k[j] + i)))
				{
					s1[j]=7;
					s2[j]=25;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
	   }
       glVertex2i((Xc+ex)+p,(Yc-ey));
	    for(j=0;j<2;j++)
	   {
			for(int i=1;i<=s1[j];i++)
			{
				if((Xc+ex)+p==(x[j]+i) && (Yc-ey)==y[j]+k[j])
				{
					s1[j]=30;
					s2[j]=20;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc+ex)+p==(x[j]+i) && ((Yc-ey)==(y[j] + k[j] + s2[j])))
				{
					s1[j]=15;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
			for(int i=1;i<=s2[j];i++)
			{
				if((Xc+ex)+p==(x[j]) && (Yc-ey)==y[j] + k[j] + i)
				{
					s1[j]=12;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc+ex)+p==(x[j] + s1[j]) && ((Yc-ey)==(y[j]+ k[j] + i)))
				{
					s1[j]=15;
					s2[j]=20;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
	   }
       glVertex2i((Xc-ex)+p,(Yc+ey));
	    for(j=0;j<2;j++)
	   {
			for(int i=1;i<=s1[j];i++)
			{
				if((Xc-ex)+p==(x[j]+i) && (Yc+ey)==y[j]+k[j])
				{
					s1[j]=30;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc-ex)+p==(x[j]+i) && ((Yc+ey)==(y[j]+k[j] + s2[j])))
				{
					s1[j]=25;
					s2[j]=65;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
			for(int i=1;i<=s2[j];i++)
			{
				if((Xc-ex)+p==(x[j]) && (Yc+ey)==y[j] + k[j] + i)
				{
					s1[j]=50;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc-ex)+p==(x[j] + s1[j]) && ((Yc+ey)==(y[j]+ k[j] + i)))
				{
					s1[j]=15;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
	   }
       glVertex2i((Xc-ex)+p,(Yc-ey));
	    for(j=0;j<2;j++)
	   {
			for(int i=1;i<=s1[j];i++)
			{
				if((Xc-ex)+p==(x[j]+i) && (Yc-ey)==y[j]+k[j])
				{
					s1[j]=40;
					s2[j]=60;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc-ex)+p==(x[j]+i) && ((Yc-ey)==(y[j]+k[j] + s2[j])))
				{
					s1[j]=50;
					s2[j]=50;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
			for(int i=1;i<=s2[j];i++)
			{
				if((Xc-ex)+p==(x[j]) && (Yc-ey)==(y[j] + k[j] + i))
				{
					s1[j]=10;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
				if((Xc-ex)+p==(x[j] + s1[j]) && ((Yc-ey)==(y[j]+ k[j] + i)))
				{
					s1[j]=20;
					s2[j]=30;
					srand=(rand()/100)-140;
					x[j]=(int)(srand);
					y[j]=250;
					k[j]=0;
					score++;
				}
			}
	   }
  }

  void txt()
  {
	    glColor4f(0.0,1.0,0.0,1.0);
		glRasterPos2i(120,-220);
		for(int i=0;i<14;i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
		}
  }
void ellip(int Xc,int Yc,int q)
{
	int ey=b;
	int ex=0;
    float px=0;
    float py=2*(a*a*ey);
    float p=((b*b)-(a*a*b)+(0.25*a*a));
    elliplot(Xc,Yc,ex,ey,q);
    while(px<py)
    {
		ex++;
		px += (2*b*b);
		if(p<0)
		{
			p=p+(b*b)+(px);
		}
		else
		{
			ey--;
			py -= (2*a*a);
			p=p+(b*b)-(py)+(px);
		}
	elliplot(Xc,Yc,ex,ey,q);
    }
		p=(((b*b)*(ex+0.5)*(ex+0.5))+((a*a)*(ey-1)*(ey-1))-(a*a*b*b));
		while(ey>0)
		{
			ey--;
			py -= (2*a*a);
			if(p>0)
			{
				p=p+(a*a)-(py);
			}
			else
			{
				ex++;
				px += (2*b*b);
				p=p+(a*a)-(py)+(px);
			}
			elliplot(Xc,Yc,ex,ey,q);
    }
}
void sq(int y,int s)
{
	glColor4f(1.0,1.0,0.0,1.0);
	for(int i=1;i<=s;i++)
	{
		glVertex2i(-317,y + i);
		glVertex2i(-317 + i,y);
		glVertex2i(-317 + i, y + s);
		glVertex2i(-317 + s,y + i);
	}
}
void rect(int x,int y,int s1,int s2,int t)
{
	glColor4f(0.0,1.0,1.0,1.0);
	for(int i=1;i<=s1;i++)
	{
		glVertex2i(x + i,y + t);
		glVertex2i(x + i, y + s2 + t);
	}
	for(int i=1;i<=s2;i++)
	{
		glVertex2i(x,y + i + t);
		glVertex2i(x + s1,y + i + t);
	}
}
void display(void)
{
	float srand;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	txt();
	glColor4f(0.0,1.0,1.0,1.0);
	glBegin(GL_POINTS);
	sq(sqy,40);
	for(i=0;i<cnt;i++)
	{
		epy[i]=sqy+20;
		ellip(epx,epy[i],z[i]);
		if(z[i]+a<=620)
		z[i]=z[i]+10;
	}
	rect(x[0],y[0],s1[0],s2[0],k[0]);
	rect(x[1],y[1],s1[1],s2[1],k[1]);
	for(int i=0;i<2;i++)
	{	
				k[i]=k[i]-10;	
				if((y[i] + k[i])<=-240)
				{
					y[i]=200;
					srand=(rand()/100)-140;
					x[i]=(int)(srand);
					k[i]=0;
					rect(x[i],y[i],s1[i],s2[i],k[i]);
				}
	}
	glEnd();
	glutSwapBuffers();
}
void idle(void)
{
}
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			z[cnt]=0;
			cnt++;
			ellip(epx,epy[cnt],z[cnt]);
		}
			break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
			break;
	default:
		break;
	}
}
void ev(int k,int x,int y)
{
	switch (k)
	{
		case GLUT_KEY_UP:
			cntkey++;
			sqy=0+cntkey*5;
			if(sqy>=200)
			{
				sqy=200;
				cntkey--;
			}
			break;
		case GLUT_KEY_DOWN:
			cntkey--;
			sqy=0+cntkey*5;
			if(sqy<=-240)
			{
				sqy=-240;
				cntkey++;
			}
			break;
	}
	epy[cnt]=sqy+20;
}
void key(unsigned char k,int x,int y)
{
	switch(k)
	{
		case 27:
		case 'q':
			glutDestroyWindow ( id );
			printf("\nHIT : %d \nSCORE : %d",score,score*10);
			getch();
			exit(0);
			break;
    	}	
}
void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WIDTH/2,WIDTH/2-1,-HEIGHT/2,HEIGHT/2-1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(WIDTH,HEIGHT);
	id=glutCreateWindow("SHOOTING GAME");
	init();
	glutIdleFunc(idle);	
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutTimerFunc(0,Timer,0);
	glutMouseFunc(mouse);
	glutSpecialFunc(ev);
	glutKeyboardFunc(key);
	glutMainLoop();	
	return(1);
}
