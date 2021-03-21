#include<windows.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;
#define SPEED 40.0


float rain = 0.0;
bool rainDay = false;
bool night = false;
float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;
int Light=1,Day=1,Plane=0,Comet=0,xm=900,train=0,board=1,Village=1;
char ch;

void declare(char *string)
{
     while(*string)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void draw_object()
{
    int l;
    if(Day==1)
    {
    //sky
    glColor3f(0.0,0.9,0.9);
    glBegin(GL_QUADS);
    glVertex2f(0,380);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,380);
    glEnd();

    //sun


        for(l=0;l<=33;l++)
    {
            glColor3f(1.0,0.9,0.0);
            draw_circle(800,625,l);
    }


    //Plane
    if(Plane==1)
    {
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(925+n,625+o);
        glVertex2f(950+n,640+o);
        glVertex2f(1015+n,640+o);
        glVertex2f(1030+n,650+o);
        glVertex2f(1050+n,650+o);
        glVertex2f(1010+n,625+o);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(925+n,625+o);
        glVertex2f(950+n,640+o);
        glVertex2f(1015+n,640+o);
        glVertex2f(1030+n,650+o);
        glVertex2f(1050+n,650+o);
        glVertex2f(1010+n,625+o);
    glEnd();

    }

    //cloud1


        for(l=0;l<=25;l++)
        {
            glColor3f(255.0,255.0,0.0);
            draw_circle(160+m,625,l);

        }


        for(l=0;l<=35;l++)
        {
            glColor3f(255.0,255.0,0.0);
            draw_circle(200+m,625,l);
            draw_circle(225+m,625,l);
        }

        for(l=0;l<=20;l++)
        {
            glColor3f(255.0,255.0,0.0);
            draw_circle(265+m,625,l);
        }

    //cloud2


        for(l=0;l<=20;l++)
        {
            glColor3f(255.0,255.0,0.0);
            draw_circle(370+m,615,l);
    }




        for(l=0;l<=35;l++)
        {

            glColor3f(255.0,255.0,0.0);
            draw_circle(410+m,615,l);
            draw_circle(435+m,615,l);
            draw_circle(470+m,615,l);
        }

    for(l=0;l<=20;l++)
        {
            glColor3f(255.0,255.0,0.0);
            draw_circle(500+m,615,l);
    }
//cloud 3



        for(int c=0;c<=35;c++) //1
        {
            glColor3f(255.0,255.0,0.0);
            draw_circle(30+m,625,c);

        }

         for(int y=0;y<=25;y++)  //2
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(70+m,625,y);

        }

        for(int y=0;y<=35;y++)  //3
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-20+m,625,y);

        }

        for(int y=0;y<=25;y++)  //4
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-60+m,625,y);

        }




          //cloud 4



        for(int c=0;c<=25;c++) //1
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-150+m,625,c);

        }

         for(int y=0;y<=30;y++)  //2
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-185+m,625,y);

        }

        for(int y=0;y<=30;y++)  //3
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-220+m,625,y);

        }

        for(int y=0;y<=25;y++)  //4
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-255+m,625,y);

        }

         //cloud 5



        for(int c=0;c<=25;c++) //1
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-350+m,625,c);

        }

         for(int y=0;y<=35;y++)  //2
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-400+m,625,y);

        }

        for(int y=0;y<=35;y++)  //3
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-450+m,625,y);

        }

        for(int y=0;y<=25;y++)  //4
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(-500+m,625,y);

        }

    //hill

	glColor3ub(34, 177, 76);
    glBegin(GL_QUADS);
    glVertex2i(0,450);
    glVertex2i(0,460);
    glVertex2i(100,550);
    glVertex2i(200,450);
    glEnd();

    glColor3ub(34, 177,76);
    glBegin(GL_TRIANGLES);
    glVertex2i(400,450);
    glVertex2i(500,550);
    glVertex2i(600,450);
    glEnd();


    //hill
    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(100,450);
    glVertex2i(300,550);
    glVertex2i(500,450);
    glEnd();


    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(600,450);
    glVertex2i(700,550);
    glVertex2i(800,450);
    glEnd();


    //hill
    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(800,450);
    glVertex2i(1200,550);
    glVertex2i(1200,450);
    glEnd();

    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,450);
    glVertex2i(900,550);
    glVertex2i(1000,450);
    glEnd();




    //grass
    glColor3f(0.0,0.9,0.0);
    glBegin(GL_QUADS);
    glVertex2f(0,160);
    glVertex2f(0,450);
    glVertex2f(1100,450);
    glVertex2f(1100,160);
    glEnd();

    }


else
{

//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//moon
int l;

	for(l=0;l<=37;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370,625,l);
	}

//star1

glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();

//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();

//star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();

//star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();

//star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

//star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();





//Comet
if(Comet==1)
{
	for(l=0;l<=7;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(300+c,675,l);
	}

glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200+c,675);
	glVertex2f(300+c,682);
	glVertex2f(300+c,668);
	glEnd();
}

//Plane
if(Plane==1)
{

	for(l=0;l<=1;l++)
	{
		glColor3f(1.0,0.0,0.0);
		draw_circle(950+n,625+o,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(954+n,623+o,l);

	}



}


 //hill

	glColor3f(0.0,0.2,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,450);
    glVertex2i(0,460);
    glVertex2i(100,550);
    glVertex2i(200,450);
    glEnd();

    glColor3f(0.0,0.2,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(400,450);
    glVertex2i(500,550);
    glVertex2i(600,450);
    glEnd();


//hill
    glColor3f(0.0,0.2,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(100,450);
    glVertex2i(300,550);
    glVertex2i(500,450);
    glEnd();


   glColor3f(0.0,0.2,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(600,450);
    glVertex2i(700,550);
    glVertex2i(800,450);
    glEnd();


//hill
    glColor3f(0.0,0.2,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(800,450);
    glVertex2i(1200,550);
    glVertex2i(1200,450);
    glEnd();

    glColor3f(0.0,0.2,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,450);
    glVertex2i(900,550);
    glVertex2i(1000,450);
    glEnd();






//grass
glColor3f(0.0,0.3,0.0);
glBegin(GL_QUADS);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

}
//Building1
glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(0,450);
glVertex2f(0,650);
glVertex2f(100,650);
glVertex2f(100,450);
glEnd();

//Building2
glColor3f(1.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex2f(300,670);
glVertex2f(300,450);
glVertex2f(100,450);
glVertex2f(100,670);
glEnd();



glColor3f(128,128,128);
        glBegin(GL_QUADS);  // window
        glVertex2f(20,460);
        glVertex2f(20,630);
        glVertex2f(75,630);
        glVertex2f(75,460);
        glEnd();

        glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(15,550);
glVertex2f(15,543);
glVertex2f(80,543);
glVertex2f(80,550);
glEnd();

 glColor3f(128,128,128);
        glBegin(GL_QUADS);  // wind
        glVertex2f(190,640);
        glVertex2f(190,460);
        glVertex2f(120,460);
        glVertex2f(120,640);
        glEnd();


 glColor3f(128,128,128);
        glBegin(GL_QUADS);  // wind
        glVertex2f(210,640);
        glVertex2f(210,460);
        glVertex2f(280,460);
        glVertex2f(280,640);
        glEnd();

        glColor3f(1.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex2f(300,550);
glVertex2f(300,530);
glVertex2f(100,530);
glVertex2f(100,550);
glEnd();

//track boundary
glColor3f(0.173,0.165,0.0);
glBegin(GL_QUADS);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();

//platform

glColor3f(.4,.7,.6);
glBegin(GL_QUADS);
glVertex2f(0,160);
glVertex2f(0,250);
glVertex2f(1100,250);
glVertex2f(1100,160);
glEnd();


//below track
glColor3f(1.0,0.623529,0.0);
glBegin(GL_QUADS);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

//Railway track

glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(-100,0);
glVertex2f(-100,20);
glVertex2f(1100,20);
glVertex2f(1100,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(-100,80);
glVertex2f(-100,100);
glVertex2f(1100,100);
glVertex2f(1100,80);
glEnd();

glBegin(GL_QUADS);
glVertex2f(0,0);
glVertex2f(0,80);
glVertex2f(10,80);
glVertex2f(10,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(80,0);
glVertex2f(80,80);
glVertex2f(90,80);
glVertex2f(90,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(150,0);
glVertex2f(150,80);
glVertex2f(160,80);
glVertex2f(160,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(220,0);
glVertex2f(220,80);
glVertex2f(230,80);
glVertex2f(230,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(290,0);
glVertex2f(290,80);
glVertex2f(300,80);
glVertex2f(300,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(360,0);
glVertex2f(360,80);
glVertex2f(370,80);
glVertex2f(370,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(430,0);
glVertex2f(430,80);
glVertex2f(440,80);
glVertex2f(440,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(500,0);
glVertex2f(500,80);
glVertex2f(510,80);
glVertex2f(510,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(570,0);
glVertex2f(570,80);
glVertex2f(580,80);
glVertex2f(580,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(640,0);
glVertex2f(640,80);
glVertex2f(650,80);
glVertex2f(650,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(710,0);
glVertex2f(710,80);
glVertex2f(720,80);
glVertex2f(720,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(770,0);
glVertex2f(770,80);
glVertex2f(780,80);
glVertex2f(780,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(840,0);
glVertex2f(840,80);
glVertex2f(850,80);
glVertex2f(850,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(900,0);
glVertex2f(900,80);
glVertex2f(910,80);
glVertex2f(910,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(970,0);
glVertex2f(970,80);
glVertex2f(980,80);
glVertex2f(980,0);
glEnd();

glBegin(GL_QUADS);
glVertex2f(1040,0);
glVertex2f(1040,80);
glVertex2f(1050,80);
glVertex2f(1050,0);
glEnd();

//track bounbary
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_QUADS);
glVertex2f(-100,100);
glVertex2f(-100,150);
glVertex2f(1100,150);
glVertex2f(1100,100);
glEnd();

//railway station boundary (fence)
glColor3f(0.0,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(0,250);
glVertex2f(0,310);
glVertex2f(5,320);
glVertex2f(10,310);
glVertex2f(10,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,250);
glVertex2f(90,310);
glVertex2f(95,320);
glVertex2f(100,310);
glVertex2f(100,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(140,250);
glVertex2f(140,310);
glVertex2f(145,320);
glVertex2f(150,310);
glVertex2f(150,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(190,250);
glVertex2f(190,310);
glVertex2f(195,320);
glVertex2f(200,310);
glVertex2f(200,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(240,250);
glVertex2f(240,310);
glVertex2f(245,320);
glVertex2f(250,310);
glVertex2f(250,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(340,250);
glVertex2f(340,310);
glVertex2f(345,320);
glVertex2f(350,310);
glVertex2f(350,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(390,250);
glVertex2f(390,310);
glVertex2f(395,320);
glVertex2f(400,310);
glVertex2f(400,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,250);
glVertex2f(950,310);
glVertex2f(955,320);
glVertex2f(960,310);
glVertex2f(960,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1000,250);
glVertex2f(1000,310);
glVertex2f(1005,320);
glVertex2f(1010,310);
glVertex2f(1010,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1050,250);
glVertex2f(1050,310);
glVertex2f(1055,320);
glVertex2f(1060,310);
glVertex2f(1060,250);
glEnd();

glBegin(GL_QUADS);
glVertex2f(950,295);
glVertex2f(950,305);
glVertex2f(1100,305);
glVertex2f(1100,295);
glEnd();

glBegin(GL_QUADS);
glVertex2f(950,265);
glVertex2f(950,275);
glVertex2f(1100,275);
glVertex2f(1100,265);
glEnd();

glBegin(GL_QUADS);
glVertex2f(0,295);
glVertex2f(0,305);
glVertex2f(400,305);
glVertex2f(400,295);
glEnd();

glBegin(GL_QUADS);
glVertex2f(0,265);
glVertex2f(0,275);
glVertex2f(400,275);
glVertex2f(400,265);
glEnd();

//big tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,185);
glVertex2f(100,285);
glVertex2f(140,285);
glVertex2f(140,185);
glEnd();



	for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,280,l);
		draw_circle(90,280,l);
		draw_circle(150,280,l);
		draw_circle(210,280,l);
		draw_circle(65,340,l);
		draw_circle(115,340,l);
		draw_circle(175,340,l);

	}

	for(l=0;l<=55;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(115,360,l);


	}



//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_QUADS);
glVertex2f(300,185);
glVertex2f(300,255);
glVertex2f(315,255);
glVertex2f(315,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,250,l);
		draw_circle(330,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(300,290,l);
		draw_circle(320,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(310,315,l);
	}


//tree 3
glColor3f(0.9,0.2,0.0);
glBegin(GL_QUADS);
glVertex2f(1050,185);
glVertex2f(1050,255);
glVertex2f(1065,255);
glVertex2f(1065,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,250,l);
		draw_circle(1080,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1050,290,l);
		draw_circle(1070,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1060,315,l);
	}



/*if(Village==1){

}
*/
if(board == 1){

glBegin(GL_QUADS);
// hut start
        glColor3f(0.6,0.0,0.0);
        glVertex2f(400,250);
        glVertex2f(950,250);
        glVertex2f(950,520);
        glVertex2f(400,520);
        glEnd();


        glColor3f(0,0,0);
        glBegin(GL_QUADS);  // hut door
        glVertex2f(670,250);
        glVertex2f(680,250);
        glVertex2f(680,500);
        glVertex2f(670,500);
        glEnd();

        glColor3f(128,128,128);
        glBegin(GL_QUADS);  // hut door left part
        glVertex2f(630,250);
        glVertex2f(670,250);
        glVertex2f(670,500);
        glVertex2f(630,500);
        glEnd();

        glColor3f(128,128,128);
        glBegin(GL_QUADS);  // hut door right part
        glVertex2f(680,250);
        glVertex2f(720,250);
        glVertex2f(720,500);
        glVertex2f(680,500);
        glEnd();

        glColor3f(128,128,128);
        glBegin(GL_QUADS);  // hut window left part
        glVertex2f(480,400);
        glVertex2f(585,400);
        glVertex2f(585,470);
        glVertex2f(480,470);
        glEnd();

        glColor3f(128,128,128);
        glBegin(GL_QUADS);  // hut window right part
        glVertex2f(780,400);
        glVertex2f(885,400);
        glVertex2f(885,470);
        glVertex2f(780,470);
        glEnd();


        //Railway Station Board

        glColor3f(0.647059,0.164706,0.164706);
        glBegin(GL_QUADS);
        glVertex2f(390,520);
        glVertex2f(960,520);
        glVertex2f(960,570);
        glVertex2f(390,570);
        glEnd();

     glColor3f(1.0,1.0,1.0);
     glRasterPos2f(570,540);
     declare("XYZ RAILWAY STATION");


//signal
	    glColor3f(1.0,0.0,0.0);
	    glBegin(GL_QUADS);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	    glEnd();


	    glColor3f(0.7,0.7,0.7);
	    glBegin(GL_QUADS);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}


}


if(train==1)
{
//train carrier 3

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-600+i-xm,50);
glVertex2f(-600+i-xm,300);
glVertex2f(-1000+i-xm,300);
glVertex2f(-1000+i-xm,50);
glEnd();

//top


glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-590+i-xm,300);
glVertex2f(-590+i-xm,290);
glVertex2f(-1010+i-xm,300);
glVertex2f(-1010+i-xm,290);
glEnd();

// Windows


glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-645+i-xm,165);
glVertex2f(-645+i-xm,275);
glVertex2f(-955+i-xm,275);
glVertex2f(-955+i-xm,165);
glEnd();


glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-655+i-xm,175);
glVertex2f(-655+i-xm,265);
glVertex2f(-945+i-xm,265);
glVertex2f(-945+i-xm,175);
glEnd();


// carrier 3 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(-675+i-xm,50,l);
	draw_circle(-925+i-xm,50,l);
   }

//train carrier 2

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-150+i-xm,50);
glVertex2f(-150+i-xm,300);
glVertex2f(-550+i-xm,300);
glVertex2f(-550+i-xm,50);
glEnd();

//top

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-140+i-xm,300);
glVertex2f(-140+i-xm,290);
glVertex2f(-560+i-xm,300);
glVertex2f(-560+i-xm,290);
glEnd();

// Windows


glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-195+i-xm,165);
glVertex2f(-195+i-xm,275);
glVertex2f(-505+i-xm,275);
glVertex2f(-505+i-xm,165);
glEnd();

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-205+i-xm,175);
glVertex2f(-205+i-xm,265);
glVertex2f(-495+i-xm,265);
glVertex2f(-495+i-xm,175);
glEnd();






glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(240+i-xm,175);
glVertex2f(240+i-xm,265);
glVertex2f(-40+i-xm,265);
glVertex2f(-40+i-xm,175);
glEnd();



//connecter

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-550+i-xm,75);
glVertex2f(-550+i-xm,95);
glVertex2f(-600+i-xm,95);
glVertex2f(-600+i-xm,75);
glEnd();

// carrier 2 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(-225+i-xm,50,l);
	draw_circle(-475+i-xm,50,l);
   }

// train carrier 1


glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(300+i-xm,50);
glVertex2f(300+i-xm,300);
glVertex2f(-100+i-xm,300);
glVertex2f(-100+i-xm,50);
glEnd();

//top

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(300+i-xm,300);
glVertex2f(300+i-xm,290);
glVertex2f(-110+i-xm,300);
glVertex2f(-110+i-xm,290);
glEnd();



// Windows

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(250+i-xm,165);
glVertex2f(250+i-xm,275);
glVertex2f(-50+i-xm,275);
glVertex2f(-50+i-xm,165);
glEnd();

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(240+i-xm,175);
glVertex2f(240+i-xm,265);
glVertex2f(-40+i-xm,265);
glVertex2f(-40+i-xm,175);
glEnd();


//connecter

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-100+i-xm,75);
glVertex2f(-100+i-xm,95);
glVertex2f(-150+i-xm,95);
glVertex2f(-150+i-xm,75);
glEnd();

// carrier 1 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(-25+i-xm,50,l);
	draw_circle(225+i-xm,50,l);
   }

//train base

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,50);
glVertex2f(350+i-xm,125);
glVertex2f(755+i-xm,125);
glVertex2f(820+i-xm,50);
glEnd();

//train control chamber

glColor3f(1.0,0.25,0.0);
glBegin(GL_POLYGON);
glVertex2f(360+i-xm,125);
glVertex2f(360+i-xm,325);
glVertex2f(560+i-xm,325);
glVertex2f(560+i-xm,125);
glEnd();

//window



glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(375+i-xm,175);
glVertex2f(375+i-xm,315);
glVertex2f(545+i-xm,315);
glVertex2f(545+i-xm,175);
glEnd();


glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(385+i-xm,185);
glVertex2f(385+i-xm,305);
glVertex2f(535+i-xm,305);
glVertex2f(535+i-xm,185);
glEnd();


//train top

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,325);
glVertex2f(350+i-xm,350);
glVertex2f(570+i-xm,350);
glVertex2f(570+i-xm,325);
glEnd();

//tain engine
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(560+i-xm,125);
glVertex2f(560+i-xm,225);
glVertex2f(755+i-xm,225);
glVertex2f(755+i-xm,125);
glEnd();


glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(735+i-xm,125);
glVertex2f(735+i-xm,225);
glVertex2f(745+i-xm,225);
glVertex2f(745+i-xm,125);
glEnd();

//train chimney

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(670+i-xm,225);
glVertex2f(670+i-xm,270);
glVertex2f(730+i-xm,270);
glVertex2f(730+i-xm,225);
glEnd();

//train cloud
    for(l=0;l<=25;l++)
        {
            glColor3f(0.179,0.179,0.179);
            draw_circle(675+i-xm,348,l);

        }



        for(l=0;l<=20;l++)
        {
            glColor3f(0.179,0.179,0.179);
            draw_circle(700+i-xm,320,l);
        }

//train head-light

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(755+i-xm,225);
glVertex2f(765+i-xm,225);
glVertex2f(765+i-xm,185);
glVertex2f(755+i-xm,185);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(755+i-xm,225);
glVertex2f(785+i-xm,225);
glVertex2f(755+i-xm,205);

glEnd();

// train connector

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,75);
glVertex2f(350+i-xm,95);
glVertex2f(300+i-xm,95);
glVertex2f(300+i-xm,75);
glEnd();

//train wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(425+i-xm,50,l);
	draw_circle(700+i-xm,50,l);
   }
}
glFlush();
}



void traffic_Light()
{
	int l;
        if(Light==1)
	  {
            for(l=0;l<=20;l++)
		{

                glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);

		glColor3f(0.0,0.7,0.0);
		draw_circle(1065,375,l);
		}
	  }

	else
	  {
            for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);

		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }


      glFlush();
}


void Rain(int value){

if(rainDay){

    rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1200;i++)
    {
        int x=rand(),y=rand();
        x%=1200; y%=800;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}


void idle()
{
glClearColor(1.0,1.0,1.0,1.0);

if(Light==0 && (i>=0 && i<=1150))
 {

	 i+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

 if(Light==0 && (i>=2600 && i<=3000))
 {

	 i+=SPEED/10;
	 m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(Light==0)
 {
	 i=i;
	 m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>3500)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	Plane=0;
 }
if(c>500)
 {
	Comet=0;
 }
glutPostRedisplay();

}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
exit(0);
}


void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
   case 'g':
   case 'G':
      Light=1;
      board=1;
    Village=0;
    break;

    case 'A':
    case 'a':
        rainDay = true;
        Rain(rain);

        break;
    case 'S':
    case 's':
        rainDay = false;
        break;
	case 'r':
	case 'R':
		Light=0;
		board=1;
		Village=0;
		break;

        case 'd':
	case 'D':
		Day=1;
		board=1;
		Village=0;
		break;

	case 'n':
        case 'N':
		Day=0;
		board=1;
		Village=0;
		break;

	case 't':
        case 'T':
		train=1;
		i=0;
		board=1;
		Village=0;
		break;

    case 'v':
    case 'V':
		train=1;
		i=0;
		board=0;
		Village=1;
		break;



        case 27:     // ESC key
        exit(0);
        break;



          case 'p':
          case 'P':
		Plane=1;
		 o=n=0.0;
		break;


       case 'c':
       case 'C':
		Comet=1;
		 c=0.0;
		break;




    };

}


void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	Plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		Comet=1;
		 c=0.0;
	 }
	break;
	}
}



void myinit()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(0.0,0.0,1.0);
  glPointSize(2.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw_object();
  traffic_Light();
  glFlush();
}
int main(int argc, char** argv)
{

int c_menu;
    cout <<  "      A Journey By Train With different mode     " << endl << endl;
    cout <<  "   ........................................... " << endl << endl;
    cout << "Press A or a : To start the Rain " << endl << endl;
    cout << "Press S or s : To Stop the rain" << endl << endl;
    cout << "Press R or r to change the signal Light to red" << endl << endl;
    cout << "Press G or g to change the signal Light to green." << endl << endl;
    cout << "Press E : For Stop Rain" << endl << endl;
    cout << "Press N or n : For Night " << endl << endl;
    cout << "Press D or d : For Day" << endl << endl;
    cout << "Press T or T to Train arrive at station."  << endl << endl;
    cout << "Press p or P to run Plain"  << endl << endl;
    cout << "Press 'Esc' or Click mouse right button to close the program "  << endl << endl;
    cout << "Press C or c to run comet"  << endl << endl;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200.0,800.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("A Railway station with traffic control");
	glutDisplayFunc(display);
        glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	c_menu=glutCreateMenu(main_menu);
	glutMainLoop();
	return 0;


}


