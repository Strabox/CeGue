#ifndef CAR_H
#define CAR_H

#include "glut.h"
#include "DynamicObject.h"

class Car : public DynamicObject {

public:

	Car():DynamicObject(Box(-0.6,0.6,-0.3,0.3)){}

	~Car(){}

	int answerToColision(){ return 1; }						// 1 = being run over

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };
		GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat shininess = 10;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());
		
		//roof
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.5, 1.0);
		//glNormal3f(0.6, 0, 1);
		glVertex3f(-0.1, 0, 0.4);
		glVertex3f(0.0, -0.15, 0.4);
		glVertex3f(0.2, -0.15, 0.4);
		glVertex3f(0.4, -0.1, 0.4);
		glVertex3f(0.4, 0.1, 0.4);
		glVertex3f(0.2, 0.15, 0.4);
		glVertex3f(0.0, 0.15, 0.4);
		glEnd();
		
		//sides
		//glNormal3f(0.6, 0, 1);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.5, 1.0);
		glVertex3f(-0.2, -0.3, 0.25);//left
		glVertex3f(-0.2, -0.3, 0.1);
		glVertex3f(0.3, -0.3, 0.1);
		glVertex3f(0.3, -0.3, 0.25);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.5, 1.0);
		glVertex3f(-0.2, 0.3, 0.25);//right
		glVertex3f(0.3, 0.3, 0.25);
		glVertex3f(0.3, 0.3, 0.1);
		glVertex3f(-0.2, 0.3, 0.1);
		glEnd();

		
		/*
		//front/rear
		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.3);
		glColor3f(0.0, 0.5, 1.0);
		glScalef(2.0, 1.0, 0.5);
		glutSolidCube(0.6);
		glPopMatrix();
		//roof:
		glPushMatrix();
		glTranslatef(0.1, 0.0, -0.1);
		glColor3f(1.0, 1.0, 0.75);
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();
		*/

		glPopMatrix();
	}
};

#endif