#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <cmath>

using namespace std;

float angle = 0.0f;

void circle(float radius, float xc, float yc, float r, float g, float b)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		glColor3ub(r, g, b);
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = radius;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x + xc, y + yc);
	}
	glEnd();
}

void blades()
{
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(6, 0);//e
	glVertex2f(5.5, 0.25);//h
	glVertex2f(0, 0.38);//c
	glVertex2f(0, -0.38);//d
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(0, 0.38);//c
	glVertex2f(-6, 0);//k
	glVertex2f(-5.5, -0.25);//l
	glVertex2f(0, -0.38);//d
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(0, 6);//H
	glVertex2f(-0.25, 5.5);//E
	glVertex2f(-0.37, 0);//F
	glVertex2f(0.37, 0);//G
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(0, -6);//H
	glVertex2f(-0.25, -5.5);//E
	glVertex2f(-0.37, 0);//F
	glVertex2f(0.37, 0);//G
	glEnd();
	//circle(2, 0, 0, 0, 0, 0);
	circle(0.47, 0, 0, 209, 195, 182);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1, 1, 1);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(-15, 15, -15, 15);

	//windmill body front

	glBegin(GL_QUADS);
	glColor3ub(237, 228, 211);
	glVertex2f(0.2, 0);//H
	glVertex2f(-0.2, 0);//E
	glColor3ub(254, 244, 223);
	glVertex2f(-0.5, -9);//F
	glVertex2f(0.5, -9);//G
	glEnd();

	glPushMatrix();

	glRotatef(angle, 0.0f, 0.0f, 1.0f);

	blades();
	glPopMatrix();

	glPushMatrix();

	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	blades();
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value)
{
	angle -= 5.0f;
	if (angle < 360.0)
	{
		angle += 360;
	}
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 25 milliseconds
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutCreateWindow("display");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(display);

	glutTimerFunc(20, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
