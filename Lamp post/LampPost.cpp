#include <GL/glut.h>
#include <iostream>
#include <math.h>

// circle function
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
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    // top circle on poll
    circle(0.2, -3.98, 9.9, 214, 214, 214);
    // light bulb
    circle(0.65, 0.79, 9.96, 204, 204, 0);

    // arched hand
    glBegin(GL_QUAD_STRIP);
    glColor3ub(214, 214, 214); // metal
    glVertex2f(-3.79, 9.18);   // g
    glVertex2f(-3.79, 8.85);   // n
    glVertex2f(-2.39, 9.99);   // H
    glVertex2f(-2.39, 9.68);   // m
    glVertex2f(-1.43, 10.31);  // i
    glVertex2f(-1.41, 10.06);  // l
    glVertex2f(-0.5, 10.54);   // J
    glVertex2f(-0.5, 10.29);   // k
    glVertex2f(-0.5, 10.54);   // J
    glVertex2f(-0.37, 9.85);   // q
    glVertex2f(1.44, 10.75);   // o
    glVertex2f(1.83, 10.07);   // P
    glEnd();

    // post
    glBegin(GL_QUADS);
    glColor3ub(214, 214, 214); // metal
    glVertex2f(-3.8, 9.8);     // D
    glVertex2f(-4.15, 9.8);    // c
    glVertex2f(-4.15, -3);     // F
    glVertex2f(-3.8, -3);      // e
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(214, 214, 214); // metal
    glVertex2f(-3.8, -3);      // e
    glVertex2f(-4.15, -3);     // F
    glVertex2f(-3.7, -3.2);    // A1
    glVertex2f(-4.25, -3.2);   // B1
    glVertex2f(-3.65, -3.89);  // Z
    glVertex2f(-4.30, -3.89);  // w
    glVertex2f(-3.60, -4);     // H1
    glVertex2f(-4.35, -4);     // G1
    glVertex2f(-3.55, -5.75);  // E1
    glVertex2f(-4.40, -5.75);  // F1
    glVertex2f(-3.4, -5.8);    // L1
    glVertex2f(-4.55, -5.8);   // I1
    glVertex2f(-3.3, -6);      // k1
    glVertex2f(-4.65, -6);     // j1
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(153, 153, 0);
    glVertex2f(1.3, 9.54);  // r1
    glVertex2f(0.38, 9.44); // q1

    glColor3ub(255, 255, 0);
    glVertex2f(4, 4);    // t1
    glVertex2f(-0.5, 4); // S1

    glColor3ub(255, 255, 51);
    glVertex2f(5, 2);     // V1
    glVertex2f(-0.75, 2); // U1

    glColor3ub(255, 255, 204);
    glVertex2f(9, -6);  // z1
    glVertex2f(-2, -6); // w1

    glEnd();
    glFlush(); // Render now
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(920, 720);
    glutCreateWindow("openGL window"); // Create a window with the given title

    gluOrtho2D(-15, 15, -15, 15);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop

    return 0;
}
