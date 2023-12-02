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

void Wheel()
{
	circle(1.35, 0, 0, 1, 1, 1);
	circle(0.92, 0, 0, 230, 230, 230);
	circle(0.14, 0, 0, 51, 51, 51);

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(51, 51, 51);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.92, 0);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(51, 51, 51);
	glVertex2f(0.0, 0.0);
	glVertex2f(0, -0.92);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(51, 51, 51);
	glVertex2f(0.0, 0.0);
	glVertex2f(0, 0.92);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(51, 51, 51);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.92, 0.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1, 1, 1);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(-15, 15, -15, 15);

	glPushMatrix();

	//Car BODY front
	glBegin(GL_QUADS);
	glColor3ub(246, 226, 105);
	glVertex2f(2.53975, 2.28505);//h
	glVertex2f(-0.76025, 2.68505);//g
	glVertex2f(-0.77, 0.13);//z1
	glVertex2f(4.27312, 0.1639);//L
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(246, 226, 105);
	glVertex2f(-0.76025, 2.68505);//g
	glVertex2f(-3.60025, 4.70505);//f
	glVertex2f(-7.14686, 4.65676);//E
	glVertex2f(-12.74025, 2.54505);//D
	glVertex2f(-12.98025, 0.22505);//c
	glVertex2f(-0.77, 0.13);//z1
	glEnd();

	//Glass
	glBegin(GL_QUADS);
	glColor3ub(51, 51, 51);
	glVertex2f(-1.42184, 2.61318);//p
	glVertex2f(-3.64574, 4.29613);//o
	glVertex2f(-7.02665, 4.26608);//n
	glVertex2f(-7.02665, 2.70334);//m
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(51, 51, 51);
	glVertex2f(-7.54382, 4.04514);
	glVertex2f(-11.00025, 2.66505);
	glVertex2f(-7.56025, 2.66505);
	glEnd();

	//LIGHTS FRONTS

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(3, 1.72);
	glVertex2f(2.43913, 1.7195);
	glVertex2f(2.4729, 1.04412);
	glVertex2f(3.6, 0.99);
	glEnd();

	//LIGHTS REAR
	glBegin(GL_QUADS);
	glColor3ub(225, 90, 100);
	glVertex2f(-12.28419, 1.55);
	glVertex2f(-12.84, 1.55);
	glVertex2f(-12.92, 0.82);
	glVertex2f(-12.33484, 0.82462);
	glEnd();

	//Door handle
	glBegin(GL_QUADS);
	glColor3ub(178, 223, 245);
	glVertex2f(-6, 2.14);
	glVertex2f(-7, 2.14);
	glVertex2f(-7, 1.8);
	glVertex2f(-6, 1.8);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	//front wheel
	Wheel();
	glPopMatrix();
	//back wheel
	glPushMatrix();

	glTranslatef(-9.59911, 0.0, 0.0);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	Wheel();
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
	glClearColor(0.0, 0.0, 1.0, 0.0);

	glutDisplayFunc(display);

	glutTimerFunc(20, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
