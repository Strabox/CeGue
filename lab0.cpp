#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include <glut.h>
#include "Frog.h"
#include "Roadside.h"

#define VPORTLEFT -5.0
#define VPORTRIGHT 5.0
#define VPORTBOTTOM -2.0
#define VPORTTOP 12.0

int rotate_y, rotate_x; //usado para rodar a câmara e assim ver se os modelos estão em ordem
Frog* sapo; //sapo DUMMY
Roadside* estradaborda; //estradaborda DUMMY

void display(void)
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	// Reset transformations
	glLoadIdentity();

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 0.0, 0.0, 1.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	/*glColor3f(0.0, 1.0, 0.0);
	*/
	sapo->draw();
	estradaborda->draw();
	/*glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.5, 0.25, 0.0);
	glVertex3f(0.5, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.5, 0.75, 0.0);
	glEnd();
	*/
	/*glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);


	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();*/
	/*glPushMatrix();
	glColor3f(0.5, 1.0, 0.0);
	glTranslatef(0.0, -0.1, -0.1);
	glutSolidSphere(0.3, 16, 16);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 1.0, 0.5);
	glTranslatef(0.0, 0.2, -0.2);
	glutSolidSphere(0.2, 12, 12);
	glPopMatrix();*/
	/*  don't wait!
	*  start processing buffered OpenGL routines
	*/

	glFlush();
}

void reshape(int w, int h) {
	float xmin = VPORTLEFT, xmax = VPORTRIGHT, ymin = VPORTBOTTOM, ymax = VPORTTOP;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		gluOrtho2D(xmin - delta, xmax + delta, ymin, ymax);
	}
	else
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		gluOrtho2D(xmin, xmax, ymin - delta, ymax + delta);
	}
}

/*void myKeyboardAction(unsigned char key, int x, int y){
	game->keyBoardAction(key, _largura, _altura);
	glutPostRedisplay();
}
*/

void specialKeys(int key, int x, int y) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	//  Request display update
	glutPostRedisplay();

}

void regularKeys(unsigned char key, int x, int y){
	if ((key == 'a') || (key == 'A')) sapo->moveDown();
	else if ((key == 'q') || (key == 'Q')) sapo->moveUp();
	else if ((key == 'p') || (key == 'P')) sapo->moveRight();
	else if ((key == 'o') || (key == 'O')) sapo->moveLeft();
	glutPostRedisplay();
}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(VPORTLEFT, VPORTRIGHT, VPORTBOTTOM, VPORTTOP, 3.0, -3.0);
	sapo = new Frog();
	sapo->setPosition(0.0, 0.0, 0.0);
	sapo->setZRotation(0.0);
	estradaborda = new Roadside();
	estradaborda->setPosition(0.0, 0.0, 0.0);

}

/*
*  Declare initial window size, position, and display mode
*  (single buffer and RGBA).  Open window with "hello"
*  in its title bar.  Call initialization routines.
*  Register callback function to display graphics.
*  Enter main loop and process events.
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
/*	glutKeyboardFunc(myKeyboardAction);
*/	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(regularKeys);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}

#endif