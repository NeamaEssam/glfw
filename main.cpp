#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;


float screenWidth = 700;
float screenHieght = 700;
float a;
float x = 0.;
float y = 0.;
float flag = 0;
void drawTriangle();
int main() {
	GLFWwindow *window;
	//initilize library
	if (!glfwInit()) {
		cout << " Can't initilize the GLFW";
		return -1;
	}
	//Create Window
	window = glfwCreateWindow(screenWidth, screenHieght, "ProjectTest", NULL, NULL);
	if (!window)
	{
		cout << "Can't render the window ";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glViewport(0.0f, 0.0f, screenWidth, screenHieght); //draw openGl in pixels 
	//glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	//glOrtho(0, screenWidth, 0,screenHieght, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-0.85, 0.85, 0.0);
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glTranslatef(x, y, 0.0f);
		drawTriangle();
		glPopMatrix();
		if (flag == 0.0)
			if (x <1.7)
				x += 0.001f;
			else if (y > -1.7)
				y -= 0.001f;
			else
				flag = 1.0;
		if (flag == 1.0)
			if (x >= 0.0f)
				x -= 0.001f;
			else if (y <= 0.0f)
				y += 0.001f;
			else
				flag = 0.0;


		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}


void drawTriangle() {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glColor3f(1.0f, 0.6f, 0.1f);
		a = i * 3.142 / 180;
		glVertex3f(0.125*cos(a), 0.125*sin(a), 0.0);
	}
	glEnd();
}

