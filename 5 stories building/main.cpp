#include <GL/glut.h>
#include <iostream>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(7.5);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glVertex2f(6,0 ); //D
    glVertex2f(6, 21);//c
    glVertex2f(-6, 21);//b
    glVertex2f(-6, 0);//A
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(5,0 ); //D
    glVertex2f(5, 20);//c
    glVertex2f(-5, 20);//b
    glVertex2f(-5, 0);//A
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glVertex2f(2,0 ); //H
    glVertex2f(2, 2);//g
    glVertex2f(-2, 2);//f
    glVertex2f(-2, 0);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(-2,4 ); //j
    glVertex2f(-2, 6);//g
    glVertex2f(-4, 6);//f
    glVertex2f(-4, 4);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(4,4 ); //j
    glVertex2f(4, 6);//g
    glVertex2f(2, 6);//f
    glVertex2f(2, 4);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(-2,8 ); //j
    glVertex2f(-2, 10);//g
    glVertex2f(-4, 10);//f
    glVertex2f(-4, 8);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(4,8 ); //j
    glVertex2f(4, 10);//g
    glVertex2f(2, 10);//f
    glVertex2f(2, 8);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(-2,12 ); //j
    glVertex2f(-2, 14);//g
    glVertex2f(-4, 14);//f
    glVertex2f(-4, 12);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(4,12); //j
    glVertex2f(4, 14);//g
    glVertex2f(2, 14);//f
    glVertex2f(2, 12);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(-2, 16); //j
    glVertex2f(-2, 18);//g
    glVertex2f(-4, 18);//f
    glVertex2f(-4, 16);//e
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // black
    glVertex2f(4,16 ); //j
    glVertex2f(4, 18);//g
    glVertex2f(2, 18);//f
    glVertex2f(2, 16);//e
    glEnd();




    glFlush();
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
