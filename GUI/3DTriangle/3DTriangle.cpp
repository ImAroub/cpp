#include<windows.h>
#include<GL/glut.h>
float angle = 1.0;
float speed = 0.1;
float ROX = 1, ROY = 1;

void Triangle() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(14);
	glLoadIdentity();
	glRotatef(angle, ROX, ROY, 0);

	glBegin(GL_TRIANGLES);
	//First 
	glColor3f(1, 0, 0);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 1.0f);
	glVertex3f(1.0f, -0.5f, 1.0f);
	//Second 
	glColor3f(0, 0, 1);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -0.5f, 1.0f);
	glVertex3f(0.0f, -0.5f, -1.0f);
	//Third 
	glColor3f(0.5, 0, 0.5);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -0.5f, -1.0f);
	glVertex3f(-1.0f, -0.5f, 1.0f);
	//Forth 
	glColor3f(1, 0.5, 0.5);
	glVertex3f(-1.0f, -0.5f, 1.0f);
	glVertex3f(0.0f, -0.5f, -1.0f);
	glVertex3f(1.0f, -0.5f, 1.0f);
	glEnd();

	angle += speed;
	if (angle > 360) angle = 0;
	glutSwapBuffers();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -3, 3, -3, 3);
	glMatrixMode(GL_MODELVIEW);
	glRotatef(1, 1, 0, 0);
}

void specFunc(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: if (speed < 2.0) speed += 0.1; break;
	case GLUT_KEY_DOWN:if (speed > 0.0)  speed -= 0.1;; break;
	case GLUT_KEY_RIGHT:ROX = 0; ROY = 1; break;
	case GLUT_KEY_LEFT:ROY = 0; ROX = 1; break;
	}
}

int main() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("3D Triangle");
	init();
	glutDisplayFunc(Triangle);
	glutIdleFunc(Triangle);
	glutSpecialFunc(specFunc);
	glutMainLoop();
	return 0;
}
