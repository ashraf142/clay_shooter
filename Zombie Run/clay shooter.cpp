/*
Game: Skeet Shooting
Name: Ashraf Ullah
ID: 011142143
last modified: December 22, 2015
*/

#include"iGraphics.h"
#include<Winuser.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>


int x,y,tarx,tary;
int r1=15,r2=15;
int l=0,r=0;
int i1=0,i2=0,n1=0,n2=0;
int disx = GetSystemMetrics(SM_CXSCREEN);//display
int disy = GetSystemMetrics(SM_CYSCREEN);
RECT rectWork = {0};
int sktx1=0,skty1=disy-450;//cd
int sktx2=disx,skty2=disy-450;
int start=0,end=0;
char players_Name[50];
int point;


/* 
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	diff = difftime(stop, start);
	iClear();

	iShowBMP(0,0,"Graphics//frst.bmp");

	if(start==0)//front page 
	{
		iShowBMP(disx/2-130,disy/2+100,"Graphics//icon.bmp");
		iShowBMP(0,0,"Graphics//start.bmp");
		iSetColor(0,0,0);
		iText(disx/2-120,disy/2,"shoot start to start playing",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(disx/2-146,disy/2-30,"or shoot exit to quit playing",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iShowBMP(disx-138,0,"Graphics//exit.bmp");

	//mouse er coordinate
	POINT cursorPos;
	GetCursorPos(&cursorPos);//function
	x = (int) cursorPos.x-40;
	y = (int) cursorPos.y-4;
	//mouse er coordinate

	//y axis borabor problem solve
	if(y>=disy/2||y<=disy/2)
		tary=disy/2+(disy/2-y);
	tary-=18;//target
	tarx=x+30;
	//y axis borabor problem solve

	//shooting point
	iSetColor(255,0,0);
	iFilledCircle(tarx,tary,8);
	iCircle(tarx,tary,18);
	iLine(tarx+22,tary,tarx-22,tary);
	iLine(tarx,tary+22,tarx,tary-22);
	//shooting point

	if(start&&end==0)//after pressing start button
	{
		if(sktx1>=disx||skty1>=disy||l)
		{
			sktx1=0;
			skty1=disy-450;//n - er value ek ek dike speed change korar jonnu
			l=0;//l - left e shoot er kaj
			if(i1==3)// i - dik change kore
				i1=0;
			if(i1==0)
				n1=0;
			if(i1==1)
				n1=15;
			if(i1==2)
				n1=20;
			i1++;
		}

		else
		{
			if(n1==20)//shot kora nahoy and , display er vitore thake
				skty1+=10;

			else
				skty1+=r1;
			sktx1+=r1+n1;
			iSetColor(255,178,102);
			iFilledEllipse(sktx1,skty1,32,15);//disk color
		}

		if(sktx2<=0||skty2>=disy||r)
		{
			sktx2=disx;
			skty2=disy-450;
			r=0;
			if(i2==3)
				i2=0;
			if(i2==0)
				n2=0;
			if(i2==1)
				n2=20;
			if(i2==2)
				n2=15;
			i2++;
		}

		else
		{
			if(n2==20)
				skty2+=10;

			else
				skty2+=r2;
			sktx2-=r2+n2;
			iSetColor(255,178,102);
			iFilledEllipse(sktx2,skty2,32,15);
		}
	}
	printf("X= %d, Y= %d",tarx,tary);
	system("cls");
}

/* 
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(tarx<=sktx1+32&&tarx>=sktx1-32&&tary<=skty1+15&&tary>=skty1-15)//left disk shoot
		{
			l=1;;point++;
		}

		if(tarx<=sktx2+32&&tarx>=sktx2-32&&tary<=skty2+15&&tary>=skty2-15)//right disk shoot
		{
			r=1;point++;
		}

		if(tarx>=0&&tarx<=128&&tary>=0&&tary<=43)//start button shoot
		{
			start=1;
		}
		if(tarx>=disx-138&&tarx<=disx-10&&tary>=0&&tary<=43)//exit button shoot
		{
			ShowCursor(TRUE);
			ShowWindow(FindWindow("Shell_TrayWnd",""), SW_SHOW);
			ShowWindow(FindWindow("Button","Start"), SW_SHOW);
			exit(0);
		}

		if(l==0||r==0)// on shoot
			PlaySound("music\\Gun_Fire_Sound.wav",NULL,SND_ASYNC);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 27)   // Esc key ASCII value = 27
	{
		//do something with Esc
		
		ShowCursor(TRUE);
		ShowWindow(FindWindow("Shell_TrayWnd",""), SW_SHOW);
		ShowWindow(FindWindow("Button","Start"), SW_SHOW);
		exit (0);
	}
	if(key == 'q')
	{
		//do something with 'q'
		
		ShowCursor(TRUE);
		ShowWindow(FindWindow("Shell_TrayWnd",""), SW_SHOW);
		ShowWindow(FindWindow("Button","Start"), SW_SHOW);
		exit (0);
	}
	if(key == 32)
	{
		//do something with space
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use 
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_RIGHT)
	{
		//place your codes for other keys here
	}

}

int main()
{
	//place your own initialization codes here. 

	printf("enter your name: ");
	fflush(stdin);
	gets(players_Name);

	ShowCursor(FALSE);//pc cursor chole jay
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWork, 0);// monitor er size ber hoy
	ShowWindow(FindWindow("Shell_TrayWnd",""), SW_HIDE);// system tray hide kore
	ShowWindow(FindWindow("Button","Start"), SW_HIDE);//start menu er button hide kore
	iInitialize(rectWork.right-rectWork.left,rectWork.bottom-rectWork.top, "skeet shooter");// monitor size >> x axis: rectWork.right-rectWork.left  ;   y axis: rectWork.bottom-rectWork.top
	return 0;
}