#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <cmath>

using namespace std;

float WhiteBoxPos = 5.0f; // white box Initial position
float BlackBoxPos = -5.0f; // black box Initial position

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1, 1, 1);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(-15, 15, -15, 15);

	//black box
	glPushMatrix();
	glTranslatef(BlackBoxPos, 0.0, 0.0); // Move the box left to right
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0); //black
	glVertex2f(-10, 0);
	glVertex2f(-10, 5);
	glVertex2f(-15, 5);
	glVertex2f(-15, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(WhiteBoxPos, 0.0, 0.0); // Move the box right to left
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255); //black
	glVertex2f(15, 0);
	glVertex2f(15, 5);
	glVertex2f(10, 5);
	glVertex2f(10, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(WhiteBoxPos + 5, 0.0, 0.0); // Move the box right to left
	glTranslatef(BlackBoxPos + 5, 0.0, 0.0); // Move the box left to right
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	WhiteBoxPos -= 0.3f; // Adjust the speed
	BlackBoxPos += 0.3f; // Adjust the speed

	if (WhiteBoxPos < -30.0f) {
		WhiteBoxPos = 5.0f; // Reset initial box position when out of sight
	}

	if (BlackBoxPos > 30.0f) {
		BlackBoxPos = -5.0f; // Reset initial box position when out of sight
	}

	glutPostRedisplay();
	glutTimerFunc(30, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutCreateWindow("display");
	glClearColor(0.0, 0.0, 1.0, 0.0);//blue background

	glutDisplayFunc(display);
	glutTimerFunc(20, update, 0);
	glutMainLoop();
	return 0;
}
