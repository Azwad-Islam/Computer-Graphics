#include <GL/glut.h>
#include <iostream>

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-10,10 ); //o
	glVertex2f(-10, 5);//A
	glVertex2f(-5, 5);//b
	glVertex2f(-5, 10);//p
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(-5,10); //P
	glVertex2f(-5, 5);//B
	glVertex2f(0, 5);//E
	glVertex2f(0, 10);//q
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(0, 10);//q
	glVertex2f(0, 5);//E
	glVertex2f(5, 5);//G
	glVertex2f(5, 10);//R
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(5, 10);//R
	glVertex2f(5, 5);//G
	glVertex2f(10, 5);//I
	glVertex2f(10, 10);//S
	glEnd();

    //2nd row start
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(-10, 5);//A
	glVertex2f(-10, 0);//D
	glVertex2f(-5, 0);//C
	glVertex2f(-5, 5);//B
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(-5, 5);//B
	glVertex2f(-5, 0);//C
	glVertex2f(0, 0);//F
	glVertex2f(0, 5);//E
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(0, 5);//E
	glVertex2f(0, 0);//F
	glVertex2f(5, 0);//H
	glVertex2f(5, 5);//G
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(5, 5);//G
	glVertex2f(5, 0);//H
	glVertex2f(10, 0);//J
	glVertex2f(10, 5);//I
	glEnd();

    //3rd row start
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(-10, 0);//D
	glVertex2f(-10, -5);//k
	glVertex2f(-5, -5);//L
	glVertex2f(-5, 0);//C
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(-5, 0);//C
	glVertex2f(-5, -5);//L
	glVertex2f(0, -5);//u
	glVertex2f(0, 0);//F
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(0, 0);//F
	glVertex2f(0, -5);//u
	glVertex2f(5, -5);//V
	glVertex2f(5, 0);//H
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(5, 0);//H
	glVertex2f(5, -5);//V
	glVertex2f(10, -5);//W
	glVertex2f(10, 0);//J
	glEnd();

    //4th row start
    glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(-10, -5);//k
	glVertex2f(-10, -10);//M
	glVertex2f(-5, -10);//N
	glVertex2f(-5, -5);//L
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(-5, -5);//L
	glVertex2f(-5, -10);//N
	glVertex2f(0, -10);//T
	glVertex2f(0, -5);//u
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white
	glVertex2f(0, -5);//u
	glVertex2f(0, -10);//T
	glVertex2f(5, -10);//z
	glVertex2f(5, -5);//V
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(5, -5);//V
	glVertex2f(5, -10);//z
	glVertex2f(10, -10);//A1
	glVertex2f(10, -5);//W

	glEnd();

	glFlush();  // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(920,720 );
    glutCreateWindow("openGL window"); // Create a window with the given title

    gluOrtho2D(-30, 30, -30, 30);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop

    return 0;
}
