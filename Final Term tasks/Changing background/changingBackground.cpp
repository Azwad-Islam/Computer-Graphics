#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <unistd.h>

float ColorRed = 0.0;
float ColorGreen = 0.0;
float ColorBlue = 0.0;

void display() {
    glClearColor(ColorRed, ColorGreen, ColorBlue, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void ChangingBackground(int v) {
    //background color switches from red to green to blue after each timer call-> 1 second
    if (ColorRed == 0.0 && ColorGreen == 0.0 && ColorBlue == 0.0) {// all color value is checked
        ColorRed = 1.0;  // red value is set to 1 for background color
        ColorGreen = 0.0;// green value is set to zero
        ColorBlue = 0.0;// blue value is set to zero
    } else if (ColorRed == 1.0 && ColorGreen == 0.0 && ColorBlue == 0.0) {//color red value is checked
        ColorRed = 0.0; //red value is set to zero
        ColorGreen = 1.0;//green value is set to 1 for background color
        ColorBlue = 0.0; //blue value is set to zero
    } else if (ColorRed == 0.0 && ColorGreen == 1.0 && ColorBlue == 0.0) {//color green value is checked
        ColorRed = 0.0; //red value is set to zero
        ColorGreen = 0.0; // green value is set to zero
        ColorBlue = 1.0; // blue value is set to 1 for background color
    }

    glutPostRedisplay();
    glutTimerFunc(1000, ChangingBackground, 0);//1000 ms = 1 sec
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Changing Background");

    glutDisplayFunc(display);
    glutTimerFunc(0, ChangingBackground, 0);

    glutMainLoop();
    return 0;
}
