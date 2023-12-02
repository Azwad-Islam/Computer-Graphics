#include <GL/glut.h>
#include <cmath>

int CurrentObject = 0;
//circle function
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
//triangle function
void ObjectTriangle1() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);// Red color
	glVertex2f(-5, -5);
	glVertex2f(5, -5);
	glVertex2f(0, 5);
	glEnd();
}
//square function
void ObjectSquare2() {
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);// Green color
	glVertex2f(-5, -5);
	glVertex2f(5, -5);
	glVertex2f(5, 5);
	glVertex2f(-5, 5);
	glEnd();
}
//drawing circle
void ObjectCircle3() {
	// Drawing code for object 3
	circle(5, 0, 0, 0, 0, 250);//blue color
}
//diamond function
void ObjectDiamond4() {
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);//white color
	glVertex2f(0, 5);
	glVertex2f(-5, 0);
	glVertex2f(0, -5);
	glVertex2f(5, 0);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Calling the objects and changing them after
	if (CurrentObject == 1) {
		ObjectTriangle1();
	}
	else if (CurrentObject == 2) {
		ObjectSquare2();
	}
	else if (CurrentObject == 3) {
		ObjectCircle3();
	}
	else if (CurrentObject == 4) {
		ObjectDiamond4();
	}

	glutSwapBuffers();
}

//changing the objects after 1 second
void cycleObjects(int value) {
	CurrentObject++;//incrementing the variable so the next object is called

	// Reset the variable to the first object after the fourth one is called
	if (CurrentObject > 4) {
		CurrentObject = 1;
	}

	glutPostRedisplay();
	glutTimerFunc(1000, cycleObjects, 0); //1000 milliseconds = 1 sec
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(480, 480);
	glutCreateWindow("changing objects");

	gluOrtho2D(-10, 10, -10, 10);

	glutDisplayFunc(display);
	glutTimerFunc(0, cycleObjects, 0);

	glutMainLoop();
	return 0;
}
