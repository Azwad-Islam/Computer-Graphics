#include <cmath>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

float angle = 0.0f;//initial value
bool isNight = false;//initially set to false

// Circle function
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

void day()
{
	circle(20, 0, 0, 0, 0, 230);
	circle(2.4, -10, 0, 196, 180, 84);
}

void night()
{
	circle(20, 0, 0, 4, 26, 64);
	circle(1, -6, 0, 4, 255, 255);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1, 1, 1);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(-10, 10, -10, 10);

	if (!isNight)
	{   //making day scene
		glPushMatrix();
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		day();
		glPopMatrix();
		//drawing the sand
		glBegin(GL_QUADS);
		glColor3ub(194, 178, 128);
		glVertex2f(-15, 2);
		glVertex2f(-15, -15);
		glVertex2f(15, -15);
		glVertex2f(15, 2);
		glEnd();
	}
	else
	{   //making night scene
		glPushMatrix();
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		night();
		glPopMatrix();
		//drawing the sand
		glBegin(GL_QUADS);
		glColor3ub(101, 73, 51);
		glVertex2f(-15, 2);
		glVertex2f(-15, -15);
		glVertex2f(15, -15);
		glVertex2f(15, 2);
		glEnd();
	}
	glutSwapBuffers();
}
//updating the angles
void update(int value)
{
	angle -= 5.0f;
	if (angle < 0.0)
	{
		angle += 360.0;
		isNight = !isNight;
	}

	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Display");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(display);
	glutTimerFunc(1, update, 0);
	glutMainLoop();

	return 0;
}
