
#include <windows.h>
#include <GL/glut.h>



void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glPointSize(100.0);

	 glBegin(GL_LINE_LOOP);
	 glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(-0.3f, -0.2f); // Bottom-left vertex
     glVertex2f(0.3f, -0.2f);  // Bottom-right vertex
     glVertex2f(0.3f, 0.2f);   // Top-right vertex
     glVertex2f(-0.3f, 0.2f);  // Top-left vertex

    glEnd();


	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
