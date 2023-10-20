#include <GL/glut.h>
#include <iostream>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(7.5);

    glBegin(GL_TRIANGLES);
    glColor3ub(34, 139, 34);
    glVertex2f(0, 16); // F
    glColor3ub(50, 205, 50);
    glVertex2f(-6.33, 2.75); // E
    glColor3ub(0, 100, 0);
    glVertex2f(6.33, 2.75); // G
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(34, 139, 34);
    glVertex2f(0, 20); // J
    glColor3ub(50, 205, 50);
    glVertex2f(-5.5, 9); // H
    glColor3ub(0, 100, 0);
    glVertex2f(5.5, 9); // I
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(50, 205, 50);
    glVertex2f(0, 22); // L
    glColor3ub(50, 205, 50);
    glVertex2f(-4.6, 14); // K
    glColor3ub(0, 100, 0);
    glVertex2f(4.6, 14); // M
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);   // brown
    glVertex2f(-0.23, 14.7); // B
    glVertex2f(-1.19, 0);    // A
    glVertex2f(1.19, 0);     // D
    glVertex2f(0.23, 14.7);  // C
    glEnd();

    // top branch
    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);    // brown
    glVertex2f(-1.54, 11.41); // P
    glVertex2f(-1.69, 11.23); // S
    glVertex2f(-0.55, 9.86);  // r
    glVertex2f(0.5, 10.64);   // q
    glEnd();

    // middle branch
    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);  // brown
    glVertex2f(1.63, 8.85); // U
    glVertex2f(0.65, 8.19); // T
    glVertex2f(0.71, 7.32); // w
    glVertex2f(1.86, 8.75); // V
    glEnd();

    // last branch
    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);   // brown
    glVertex2f(-1.61, 6.49); // B1
    glVertex2f(-1.73, 6.25); // C1
    glVertex2f(-0.85, 5.22); // Z
    glVertex2f(-0.79, 6.08); // A1
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(720, 720);
    glutCreateWindow("openGL window"); // Create a window with the given title

    gluOrtho2D(-30, 30, -30, 30);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop

    return 0;
}
