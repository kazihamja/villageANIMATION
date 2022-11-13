#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#define PI 3.1416
int windowWidth=500; int windowHeight=500;
bool flagScale=false;
double sun_move=0;
double cloud_move=0;
double boat_move=0;


void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20;

	GLfloat twicePi = 2.0f * PI;


	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
 void sun()
 {   glColor3f(1,1,0);
     drawFilledCircle(7,13,1.2);
 }

 void cloud()
 {   glColor3f(1,1,1);
     drawFilledCircle(-7,13,1.7);
     drawFilledCircle(-9,13,1.2);
     drawFilledCircle(-5,13,1.5);
 }
 void sky()
 {
     glPushMatrix();
     glColor3f(0,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-20,3);
     glVertex2f(20,3);
      glVertex2f(20,20);
       glVertex2f(-20,20);
    glEnd();
   glPopMatrix();

 }
 void filed()
 {
     glPushMatrix();
     glColor3f(0,0.5,0);
    glBegin(GL_QUADS);
    glVertex2f(-20,-20);
     glVertex2f(20,-20);
      glVertex2f(20,-4);
       glVertex2f(-20,-4);
    glEnd();
   glPopMatrix();

 }
 void river()
 {
     glPushMatrix();
     glColor3f(0,0.5,1);
    glBegin(GL_QUADS);
    glVertex2f(-20,-5);
    glVertex2f(20,-5);
    glVertex2f(20,5);
    glVertex2f(-20,5);
    glEnd();
   glPopMatrix();

 }
  void house()
 {
 glPushMatrix();
     glColor3f(0.5,0.35,0.05);
    glBegin(GL_QUADS);
    glVertex2f(-9,-18);
    glVertex2f(-6.5,-18);
    glVertex2f(-6.5,-14);
    glVertex2f(-9,-14);
    glEnd();
   glPopMatrix();
    glPushMatrix();
     glColor3f(0,0.5,1);
    glBegin(GL_QUADS);
    glVertex2f(-12,-18);
    glVertex2f(-4,-18);
    glVertex2f(-4,-12);
    glVertex2f(-12,-12);
    glEnd();
   glPopMatrix();

   glPushMatrix();
     glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(-7.5,-9);
    glVertex2f(-3,-12);
    glVertex2f(-13,-12);
    glEnd();
   glPopMatrix();



 }
 void tree()
 {
     glPushMatrix();
     glColor3f(0.5,0.35,0.05);
    glBegin(GL_QUADS);
    glVertex2f(16,-18);
    glVertex2f(15.5,-18);
    glVertex2f(15.5,-12);
    glVertex2f(16,-12);
    glEnd();
   glPopMatrix();

   glPushMatrix();
     glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(16,-9);
    glVertex2f(18,-12);
    glVertex2f(13.5,-12);
    glEnd();
   glPopMatrix();













 }

 void boat()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,.5,0);
    glVertex2f(0,-2);
    glVertex2f(4,-2);
    glVertex2f(5,0);

    glVertex2f(-1,0);


    glEnd();
glPopMatrix();

glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(2,-1);
    glVertex2f(3,17);

    glVertex2f(3,1);
    glVertex2f(2,4);


    glEnd();
glPopMatrix();

glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex2f(6,4);
    glVertex2f(6,7);

    glEnd();
glPopMatrix();
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //glViewport(0, 0 ,windowWidth ,windowHeight);


glPushMatrix();
     glTranslatef(cloud_move,0,0);
     cloud();
   glPopMatrix();
 glPushMatrix();
     glTranslatef(sun_move,0,0);
     sun();
   glPopMatrix();
sky();

glPushMatrix();
     glTranslatef(boat_move,0,0);
     boat();
   glPopMatrix();
   river();
house();

tree();
glPushMatrix();
glTranslatef(12,0,0);
house();
glPopMatrix();

glPushMatrix();
glTranslatef(-4,0,0);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-17,0,0);
tree();
glPopMatrix();




filed();

    glFlush();
    glutSwapBuffers();
}
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

    case 'S':
        flagScale=true;
        break;
    case 's':
        flagScale=false;
        break;



    case 20:	// Escape key
        exit(1);
    }
    glutPostRedisplay();
}

void animate()
{
	if (flagScale == true)
	{
		sun_move+= 0.02;
		if(sun_move > 16)
			 sun_move= -20;
	}
	if (flagScale == false)
	{
		sun_move = 0;

	}

	if (flagScale == true)
	{
		cloud_move+= 0.02;
		if(cloud_move > 16)
			 cloud_move= -20;
	}
	if (flagScale == false)
	{
		cloud_move = 0;

	}

	if (flagScale == true)
	{
		boat_move+= 0.02;
		if(boat_move > 16)
			 boat_move= -20;
	}
	if (flagScale == false)
	{
		boat_move = 0;

	}




	glutPostRedisplay();
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("village_by_hamja");
    glViewport(0, 0 ,windowWidth ,windowHeight);
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
