#ifndef TURTLE_H
#define TURTLE_H

#include "glut.h"
#include "DynamicObject.h"
#include <stdio.h>

class Turtle : public DynamicObject {

public:

	Turtle():DynamicObject(Box(-1.35,1.35,-0.2,0.2)){}

	~Turtle(){}

	int answerToColision(){ return 2; }					// 2 = must float

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 110.0 / 255.0, 37.0 / 255.0, 37.0 / 255.0, 0.4 };
		GLfloat shininess = 0.20;
		
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glTranslatef(vector.getX() - 1.0, vector.getY(), vector.getZ());

		//turtle 1
		glTranslatef(+0.0, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();
		
		//turtle 2
		glTranslatef(+1.0, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		//turtle 3
		glTranslatef(+1.0, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif